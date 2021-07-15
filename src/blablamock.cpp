#include "blablatable.h"

#ifdef NO_DB

/*
Checa se o `email` existe no banco de dados.
Retorna true caso positivo, falso caso contrário.
*/
bool BlaBlaTable::existeEmail(const std::string& email)
{
    if (email.find("@") != std::string::npos)
        return true;
    else
        return false;
}

/*
Checa se a `senha` corresponde ao `email`.
Retorna true caso positivo, falso caso contrário.
*/
bool BlaBlaTable::matchEmailSenha(const std::string& email, const std::string& senha)
{
    return true;
}

/*
Envia uma mensagem do remetente para o destinatario.
*/
void BlaBlaTable::enviaMensagem(
    const std::string& remetente, 
    const std::string& destinatario,
    const std::string& conteudoMensagem)
{
    std::string feedback = std::string()+
    "<LOG DO MOCK>: a mensagem [" + conteudoMensagem + "] foi enviada de ["+
    remetente + "] para [" + destinatario + "]";
    std::cout << feedback << std::endl;

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
    std::vector<std::string> pessoas = 
    {
        "dikson@gmail.com", 
        "breno@usp.br",
        "hiram@outlook.com",
        "joao@gmail.com",
        "marcos@gmail.com",
        "marcosaurelio@gmail.com",
        "naju@hotmail.com"
    };
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
    
    std::vector<msg> msgsResposta =
    {
        msg("10:01", usuarioEmail, "aline@email.com", "oi, tudo bem?"),
        msg("09:58", usuarioEmail, "rodrigo@email.com", "acho que vou falar com ela..."),
        msg("08:58", "spam@x.com", usuarioEmail, "médicos ODEIAM esse truque pra perder peso!"),
        msg("5:58", "guia@email.com", usuarioEmail, "mano, acho que você deixou seu iPhone no meu carro kkk")
    };
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
    /*
    Para o mock, eu implementei de um jeito que sempre vai ter mensagem entre
    o usuario e a outra pessoa. Stonks?
    Stonks.
    */
    std::vector<msg> msgsResposta =
    {
        msg("10:03", outraPessoa, usuarioEmail, "você sabe que impossível é uma palavra forte"),
        msg("10:01", usuarioEmail, outraPessoa, "difícil ou impossivel?"),
        msg("10:01", outraPessoa, usuarioEmail, "acho dificil"),
        msg("10:00", usuarioEmail, outraPessoa, "fala pra mim"),
        msg("10:00", usuarioEmail, outraPessoa, "quero"),
        msg("10:00", outraPessoa, usuarioEmail, "quer saber mesmo?"),
        msg("09:59", usuarioEmail, outraPessoa, "vc acha que eu tenho chance?"),
        msg("09:58", usuarioEmail, outraPessoa, "mano, acho que vou falar com ela...")
    };
    return msgsResposta;
}

#endif
