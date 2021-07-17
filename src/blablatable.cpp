#include "blablatable.h"

#ifndef NO_DB

#include <cstdlib>

/*
Checa se o `email` existe no banco de dados.
Retorna true caso positivo, falso caso contrário.
*/
bool BlaBlaTable::existeEmail(const std::string& email)
{
    // Pesquisa no banco de dados por alguem com esse email e senha.
    
    std::string q = "SELECT EMAIL FROM USUARIO WHERE EMAIL = '";
    q += email; // Muito suscetível a SQL-injection. Perdão Ganesh.
    q += "'";

    // Create a non-transactional object. TODO: fix
    pqxx::nontransaction N(*C);

    // Executa a consulta.
    pqxx::result R( N.exec( q ));

    return R.size() > 0 ? true : false;
}

/*
Checa se a `senha` corresponde ao `email`.
Retorna true caso positivo, falso caso contrário.
*/
bool BlaBlaTable::matchEmailSenha(const std::string& email, const std::string& senha)
{
    // Pesquisa no banco de dados por alguem com esse email e senha.
    std::string q = "SELECT SENHA FROM USUARIO WHERE EMAIL = '";
    q += email; // Muito suscetível a SQL-injection. Perdão Ganesh.
    q += "'";

    // Não transacional pois é uma leitura.
    pqxx::nontransaction N(*C);

    // Executa a consulta.
    pqxx::result R( N.exec( q ));

    bool validadeSenha = false;

    // Verifica os resultados encontrados.
    for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c)
    {
        std::string acq_senha = c[0].as<std::string>();
        if (senha.compare(acq_senha) == 0) validadeSenha = true;
        break;
    }

    return validadeSenha;
}

/*
Envia uma mensagem do remetente para o destinatario.
*/
void BlaBlaTable::enviaMensagem(
    const std::string& remetente, 
    const std::string& destinatario,
    const std::string& conteudoMensagem)
{

    time_t momento_atual;
    char buffer[256] = {0};
    struct tm *info_tempo;

    time( &momento_atual );

    info_tempo = localtime( &momento_atual );

    strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", info_tempo);
    std::string dataHora(buffer); // 2021/08/09 14:21:19

    std::string q = "INSERT INTO MENSAGEM (USUARIO_ENVIA, USUARIO_RECEBE, MENSAGEM, DATA)\
    VALUES ('";
    q += remetente + "', '" +
         destinatario +"', '" +
         conteudoMensagem +
         "', TO_TIMESTAMP('"+ dataHora + "', 'YYYY/MM/DD HH24:MI:SS'));";

    // Transacional pois altera o banco.
    pqxx::work W(*C);

    W.exec(q);
    W.commit();

    std::cout << "Mensagem enviada!\n";
}

/*
Retorna uma lista das últimas `nPessoas` que o `usuarioEmail` falou, ordernadas
da mais recente para a mais antiga. Caso existam menos que `nPessoas`, retorna
uma lista com todas as pessoas.
*/
std::vector<std::string> BlaBlaTable::ultimasPessoas(
    const std::string& usuarioEmail, 
    int nPessoas)
{

    std::string q = "SELECT E.USUARIO FROM (SELECT U.USUARIO, MAX(U.DATA) as DATA FROM ("
        "("
            "SELECT USUARIO_RECEBE as USUARIO, DATA FROM MENSAGEM M "
            "WHERE USUARIO_ENVIA = '"; q += usuarioEmail; q += "'"
        ")"
        "UNION"
        "("
            "SELECT USUARIO_ENVIA  as USUARIO, DATA FROM MENSAGEM "
            "WHERE USUARIO_RECEBE = '"; q += usuarioEmail; q += "'"
        ")) U "
    "GROUP BY U.USUARIO "
    "ORDER BY DATA DESC) E;";

    // Não transacional pois é uma leitura.
    pqxx::nontransaction N(*C);

    // Executa a consulta.
    pqxx::result R( N.exec( q ));
    
    std::vector<std::string> pessoas;
    
    // Verifica os resultados encontrados.
    for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c)
    {
        pessoas.push_back(c[0].as<std::string>()); // Copia string, de acordo com a referência do c++
    }

    if (pessoas.size() > nPessoas) 
    {
        pessoas.resize(nPessoas);
    }

    return pessoas;
}

/*
Retorna um vector com as últimas `nMensagens` mensagens que o usuário trocou,
mas com o limite de uma por conversa. Caso existam menos que `nMensagens`, 
retorna um vector com o máximo de mensagens possíveis (sem duplicatas).
O vetor é ordenado da mais recente pra mais antiga.
*/
std::vector<msg> BlaBlaTable::ultimasMensagens(
    const std::string& usuarioEmail,
    int nMensagens)
{

std::string q =

"WITH MSG AS "
"( "
"     ( "
"         SELECT USUARIO_RECEBE as USUARIO, DATA, MENSAGEM as M "
"         FROM MENSAGEM "
"         WHERE USUARIO_ENVIA = '"; q += usuarioEmail; q += "' "
"     ) "
"     UNION "
"     ( "
"         SELECT USUARIO_ENVIA as USUARIO, DATA, MENSAGEM as M "
"         FROM MENSAGEM "
"         WHERE USUARIO_RECEBE = '"; q += usuarioEmail; q += "' "
"     ) "
") "
"SELECT A.USUARIO, A.DATA, A.M "
"FROM MSG A "
"LEFT OUTER JOIN MSG B ON A.USUARIO = B.USUARIO AND A.DATA < B.DATA "
"WHERE B.USUARIO IS NULL; ";

    // Não transacional pois é uma leitura.
    pqxx::nontransaction N(*C);

    // Executa a consulta.
    pqxx::result R( N.exec( q ));
    
    std::vector<msg> msgsResposta;
    
    // Verifica os resultados encontrados.
    for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c)
    {
        msgsResposta.push_back(
        {
            std::string(c[1].as<std::string>()),
            std::string(c[0].as<std::string>()),
            std::string(usuarioEmail),
            std::string(c[2].as<std::string>())
        }); // Copia string, de acordo com a referência do c++
    }

    if (msgsResposta.size() > nMensagens) 
    {
        msgsResposta.resize(nMensagens);
    }

    return msgsResposta;
}

/*
Retorna um vector com as últimas `nMensagens` mensagens trocadas entre o 
`usuarioEmail` e a `outraPessoa` (ou seja, um deles é o remetente e o outro é
o destinatario) 
O vetor é ordenado da mais recente pra mais antiga.
*/
std::vector<msg> BlaBlaTable::ultimasMensagensIndividuais(
    const std::string& usuarioEmail,
    const std::string& outraPessoa,
    int nMensagens)
{

    std::string q =
"SELECT * "
"FROM MENSAGEM "
"WHERE "
"    (USUARIO_ENVIA = '"; q += usuarioEmail; q += "' AND USUARIO_RECEBE = '"; q += outraPessoa; q += "') "
"    OR (USUARIO_ENVIA = '"; q += outraPessoa; q += "' AND USUARIO_RECEBE = '"; q += usuarioEmail; q += "') "
"ORDER BY DATA DESC "
"LIMIT("; q += std::to_string(nMensagens); q += ")";

    /*
    std::vector<msg> msgsResposta =
    {
        {"10:03", outraPessoa, usuarioEmail, "você sabe que impossível é uma palavra forte"},
        {"10:01", usuarioEmail, outraPessoa, "difícil ou impossivel?"},
        {"10:01", outraPessoa, usuarioEmail, "acho dificil"},
        {"10:00", usuarioEmail, outraPessoa, "fala pra mim"},
        {"10:00", usuarioEmail, outraPessoa, "quero"},
        {"10:00", outraPessoa, usuarioEmail, "quer saber mesmo?"},
        {"09:59", usuarioEmail, outraPessoa, "vc acha que eu tenho chance?"},
        {"09:58", usuarioEmail, outraPessoa, "mano, acho que vou falar com ela..."}
    };*/

    // Não transacional pois é uma leitura.
    pqxx::nontransaction N(*C);

    // Executa a consulta.
    pqxx::result R( N.exec( q ));
    
    std::vector<msg> msgsResposta;
    
    // Verifica os resultados encontrados.
    for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c)
    {
        msgsResposta.push_back(
        {
            std::string(c[3].as<std::string>()),
            std::string(c[0].as<std::string>()),
            std::string(c[1].as<std::string>()),
            std::string(c[2].as<std::string>())
        }); // Copia string, de acordo com a referência do c++
    }

    if (msgsResposta.size() > nMensagens) 
    {
        msgsResposta.resize(nMensagens);
    }

    return msgsResposta;

    return msgsResposta;
}

BlaBlaTable::BlaBlaTable()
{
    C = NULL;
    init_db();
}

BlaBlaTable::~BlaBlaTable()
{
    close_db();   
}

/*
Inicialização da comunicação com o banco de dados.
*/
void BlaBlaTable::init_db()
{
    _status = false;
    if (C != NULL) delete C;

    std::cout << "Conectando ao DB\n";
    try
    {

        // Ve se uma string de conexão foi passada
        char* conn_str = getenv("PSQL_CONN");

        if (conn_str == NULL)
            conn_str = "user = postgres password = postgres123 \
                        hostaddr = 127.0.0.1 port = 5432";

        C = new pqxx::connection(conn_str);

        if (C->is_open())
        {
          std::cout << "Conexão estabelecda com: " << C->dbname() << std::endl;
        }
        else
        {
          std::cout << "Não foi possível conectar!" << std::endl;
          return;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Não foi possível conectar!" << std::endl;
	return;
    }
    _status = true;
}

/*
Término da comunicação com o banco de dados.
*/
void BlaBlaTable::close_db()
{
    if (C != NULL)
    {
	if(C->is_open()) C->close();
	delete C;
    }

    C = NULL;
}

// Validade
bool BlaBlaTable::is_ok() { return _status; }

#endif
