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

void info(){
    std::string mensagemInfo;
    mensagemInfo = std::string()+
    "Esse programa foi realizado com muito carinho em Julho de 2021 para a "+
    "disciplina de Banco de Dados (SCC0240) da USP de Sao Carlos."+
    "\n"+
    "Github do projeto: https://github.com/henriquenunez/blablatravel\n"+
    "\n"+
    "Autores:\n"+
    "\n"+
    "Breno Queiroz\n"+
    "Dikson Santos\n"+
    "Henrique Hiram\n";
    std::cout << mensagemInfo;
    return;
}

void ajuda(){
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
    "ver - Mostra as ultimas mensagens.\n"+
    "info - Um pouco mais sobre o projeto.\n"+
    "sair - Finaliza a aplicacao.\n";
    std::cout << mensagemAjuda;
    return;
}

/*
shell interativa que recebe o input do usuario e executa os comandos.
*/
void shell()
{
    std::string bemVindo;
    bemVindo = std::string()+
    "# Bem vindo ao chat blablatravel!\n"+
    "# Digite \"ajuda\" para mais informacoes.\n";
    std::cout << bemVindo;

    while(true)
    {
        std::cout << "> " ;
        std::string comando;
        if (!std::getline(std::cin, comando))
        {
            break;
            //pra lidar com ctrl+D
        }

        if (comando == "ajuda")
        {
            ajuda();
        }
        else if (comando == "info")
        {
            info();
        }
        else if (comando == "sair"){
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