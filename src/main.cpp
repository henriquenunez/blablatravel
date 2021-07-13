#include <iostream>
#include <string>

/*
imprime uma mensagem de erro na shell.
*/
void erro(std::string mensagemErro)
{
    std::cout << "ERRO: " << mensagemErro << std::endl;
    return;
}

/* 
mostra informações sobre o projeto.
*/
void info()
{
    std::string mensagemInfo;
    mensagemInfo = std::string()+
    "Esse programa foi realizado com muito carinho em Julho de 2021 para a "+
    "disciplina de Banco de Dados (SCC0240) da USP de Sao Carlos.\n"+
    "\n"+
    "Ele é um sistema de chat de um sistema fictício, o BlaBlaTravel, "+
    "que permite que turistas e guias turísticos marquem encontros entre si.\n"+
    "\n"+
    "GitHub do projeto: https://github.com/henriquenunez/blablatravel\n"+
    "\n"+
    "Autores:\n"+
    "\n"+
    "Breno Queiroz\n"+
    "Dikson Santos\n"+
    "Henrique Hiram\n";
    std::cout << mensagemInfo;
    return;
}

/*
mostra a tela de ajuda com os comandos disponiveis.
*/
void ajuda()
{
    std::string mensagemAjuda;
    mensagemAjuda = std::string()+
    "Sistema integrado de chat do blablatravel. "+
    "Aqui, voce pode falar com seu guia ou companheiros de passeio!\n"+
    "Qual o seu proximo destino?\n"+
    "\n"+
    "Comandos:\n"+
    "\n"+
    "ajuda - Mostra essa tela de ajuda aqui.\n"+
    "login - Loga com a sua conta.\n"+
    "logout - Desloga da sua conta.\n"+
    "chat - Mostra as ultimas mensagens.\n"+
    "enviar - Envia uma nova mensagem.\n"+
    "info - Um pouco mais sobre o projeto.\n"+
    "sair - Finaliza a aplicacao.\n";
    std::cout << mensagemAjuda;
    return;
}

/*
efetua o login do usuario com sua senha no sistema.
*/
void login(std::string& usuarioCPF, bool& logged)
{
    if (logged)
    {
        erro("você já está logado. faça logout para entrar em outra conta.");
        return;
    }

    std::string prompt = "CPF: ";
    std::cout << prompt;

    std::string CPF;
    std::getline(std::cin, CPF);
    bool validadeCPF = true;
    // [help] VALIDA CPF, se for errado faz virar false
    if (!validadeCPF)
    {
        erro("CPF Inválido. Tente novamente.");
        return;
    }

    prompt = "Senha: ";
    std::cout << prompt;

    std::string senha;
    std::getline(std::cin, senha);
    bool validadeSenha = true;
    // [help] VALIDA SENHA, se for errada faz virar false
    if (!validadeSenha)
    {
        erro("Senha inválida. Tente novamente.");
        return;
    }

    usuarioCPF = CPF;
    logged = true;
    std::string sucesso = "Logado com sucesso!";
    std::cout << sucesso << std::endl;
    return;
}

/*
faz logout do usuario.
*/
void logout(std::string& usuario, bool& logged)
{
    if (!logged)
    {
        erro("você não está logado.");
        return;
    }

    usuario.clear();
    logged = false;

    std::string sucesso = "Desconectado. Até mais! ;)";
    std::cout << sucesso << std::endl;
    return;
}

/*
mostra as últimas mensagens do usuário na tela.
*/
void chat(const std::string& usuario, const bool& logged)
{
    if (!logged)
    {
        erro("você precisa fazer login para ver suas mensagens.");
        return;
    }

    
    std::cout << "ainda nao foi implementado kkkk" << std::endl;
    return;
}

/*
envia uma nova mensagem.
*/
void enviar(const std::string& usuario, const bool& logged)
{
    if (!logged){
        erro("você precisa fazer login pra enviar uma mensagem.");
        return;
    }

    std::cout << "ainda nao foi implementado kkkk" << std::endl;
    return;
}

/*
shell interativa que recebe o input do usuario e executa os comandos.
fica em loop recebendo os comandos do usuário até ser encerrada.
*/
void shell()
{
    std::string bemVindo;
    bemVindo = std::string()+
    "# Bem vindo ao chat blablatravel!\n"+
    "# Digite \"ajuda\" para mais informacoes.\n";
    std::cout << bemVindo;
    //CPF do usuário
    std::string usuarioCPF; 
    bool logged = false;

    while(true)
    {
        std::cout << "> " ;
        std::string comando;
        if (!std::getline(std::cin, comando))
        {
            break;
            //pra lidar com ctrl+D/EOF
        }

        if (comando == "ajuda")
        {
            ajuda();
        }
        else if (comando == "login")
        {
            login(usuarioCPF, logged);
        }
        else if (comando == "logout")
        {
            logout(usuarioCPF, logged);
        }
        else if (comando == "chat") 
        {
            chat(usuarioCPF, logged);
        }
        else if (comando == "enviar"){
            enviar(usuarioCPF, logged);
        }
        else if (comando == "info")
        {
            info();
        }
        else if (comando == "sair")
        {
            std::string despedida = std::string()+
            "\"Todos os meus dias são um adeus.\"\n"+
            "- François Chateaubriand\n";
            std::cout << despedida;
            break;
        }
        else
        {
            erro("comando invalido. digite \"ajuda\" pra ver a lista de comandos.");
        }
        
    }
    return;
}

int main()
{
    shell();
    return 0;
}