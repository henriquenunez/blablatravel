#ifndef MSGS_USUARIOS_H
#define MSGS_USUARIOS_H

#include <string>

struct msg {
    std::string timeStamp;
    std::string remetente;
    std::string destinatario;
    std::string conteudoMensagem;
    /*
    Inicializador. Permite que você declare coisas tipo
    msg minhaMensagem("12:40", "eu@email", "ela@email", "oi, tudo bem?");
    */
    msg(
        std::string timeStamp,
        std::string remetente,
        std::string destinatario,
        std::string conteudoMensagem)
    {
        this->timeStamp = timeStamp;
        this->remetente = remetente;
        this->destinatario = destinatario;
        this->conteudoMensagem = conteudoMensagem;
    };
};

#endif