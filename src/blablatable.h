#ifndef BLABLATABLE_H
#define BLABLATABLE_H

#include <iostream>
#include <string>
#include <vector>
#include "msgsUsuarios.h"

#ifndef NO_DB
#include <pqxx/pqxx>
#endif

class BlaBlaTable
{
public:
    /*
    Construtor e destrutor da classe. Só são necessários se estamos realmente
    utilizando o banco de dados.
    */
    #ifndef NO_DB
    BlaBlaTable();
    ~BlaBlaTable();
    #endif

    /*
    Checa se o `email` existe no banco de dados.
    Retorna true caso positivo, falso caso contrário.
    */
    bool existeEmail(const std::string& email);

    /*
    Checa se a `senha` corresponde ao `email`.
    Retorna true caso positivo, falso caso contrário.
    */
    bool matchEmailSenha(const std::string& email, const std::string& senha);

    /*
    Envia uma mensagem do remetente para o destinatario.
    */
    void enviaMensagem(
        const std::string& remetente,
        const std::string& destinatario,
        const std::string& conteudoMensagem);

    /*
    Retorna um vector das últimas `nPessoas` pessoas que o `usuarioEmail` falou, 
    ordenadas da mais recente para a mais antiga. Caso existam menos que 
    `nPessoas`, retorna um vector com todas as pessoas.
    */
    std::vector<std::string> ultimasPessoas(
        const std::string& usuarioEmail, 
        int nPessoas);

    /*
    Retorna um vector com as últimas `nMensagens` mensagens que o usuário trocou,
    mas com o limite de uma por conversa. Caso existam menos que `nMensagens`, 
    retorna um vector com o máximo de mensagens possíveis (sem duplicatas).
    O vetor é ordenado da mais recente pra mais antiga.
    */
    std::vector<msg> ultimasMensagens(
        const std::string& usuarioEmail,
        int nMensagens);

    /*
    Retorna um vector com as últimas `nMensagens` mensagens trocadas entre o 
    `usuarioEmail` e a `outraPessoa` (ou seja, um deles é o remetente e o outro é
    o destinatario) 
    O vetor é ordenado da mais recente pra mais antiga.
    */
    std::vector<msg> ultimasMensagensIndividuais(
        const std::string& usuarioEmail,
        const std::string& outraPessoa,
        int nMensagens);
#ifndef NO_DB
private:
    void init_db();
    void close_db();

    pqxx::connection *C;
#endif
};

#endif