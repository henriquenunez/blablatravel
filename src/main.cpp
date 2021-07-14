#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include "blablatable.h"

struct mensagem
{
    std::string usuarioEmail; //Email do usuário
    bool logged = false; //Estado (logado/deslogado)
    
    /*
    Imprime uma mensagem de erro na shell.
    */
    void erro(std::string mensagemErro)
    {
        std::cout << "ERRO: " << mensagemErro << std::endl;
        return;
    }
    
    /*
    Mostra informações sobre o projeto.
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
    Mostra a tela de ajuda com os comandos disponiveis.
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
        "ler - Mostra as mensagens com um contato.\n"+
        "enviar - Envia uma nova mensagem.\n"+
        "info - Um pouco mais sobre o projeto.\n"+
        "sair - Finaliza a aplicacao.\n";
        std::cout << mensagemAjuda;
        return;
    }
    
    /*
    Efetua o login do usuario com sua senha no sistema.
    */
    void login()
    {
        if (logged)
        {
            erro("você já está logado. faça logout para entrar em outra conta.");
            return;
        }
    
        std::string prompt = "Email: ";
        std::cout << prompt;
    
        std::string email;
        std::getline(std::cin, email);
        bool validadeEmail = existeEmail(email);
        if (!validadeEmail)
        {
            erro("email inválido. Tente novamente.");
            return;
        }
    
        prompt = "Senha: ";
        std::cout << prompt;

        std::string senha;
        std::getline(std::cin, senha);
        bool validadeSenha = matchEmailSenha(email, senha);
        if (!validadeSenha)
        {
            erro("senha inválida. Tente novamente.");
            return;
        }

        usuarioEmail = email;

        logged = true;
        std::string sucesso = "Logado com sucesso!";
        std::cout << sucesso << std::endl;
        return;
    }
    
    /*
    Faz logout do usuario.
    */
    void logout()
    {
        if (!logged)
        {
            erro("você não está logado.");
            return;
        }
    
        usuarioEmail.clear();
        logged = false;
    
        std::string sucesso = "Desconectado. Até mais! ;)";
        std::cout << sucesso << std::endl;
        return;
    }
    
    /*
    Mostra as últimas mensagens do usuário na tela.
    ┌─────────
    │ 1/2/2018 bob@gmail.com
    │ (você) eai mano, de boa? vo...
    ├─────────
    │ 1/2/2016 alice@gmail.com
    │ hahaha daquela vez eu nã...
    └─────────
    */
    void chat()
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
    Mostra as ultimas mensagens com um contato especifico.
    ┌─────────
    │ 1/2/2018 bob@gmail.com
    │ (você) eai mano, de boa? vo...
    ├─────────
    │ 1/2/2016 alice@gmail.com
    │ hahaha daquela vez eu nã...
    └─────────
    */
    void ler(){
        if (!logged)
        {
            erro("faça login para ver suas mensagens com alguém.");
            return;
        }
    }

    /*
    envia uma nova mensagem para o email `destinatario`
    */
    void novaMensagem(std::string destinatario)
    {
        if (!existeEmail(destinatario))
        {
            erro("Esse usuário não existe.");
            return;
        }
        if (destinatario == usuarioEmail)
        {
            erro("Você não pode enviar uma mensagem para si mesmo.");
            return;
        }

        std::string prompt = std::string()+
        "Nova mensagem para ["+destinatario+"]:\n"+
        "[>] ";
        std::cout << prompt;
        std::string mensagemDestinatario;
        std::getline(std::cin, mensagemDestinatario);
        
        enviaMensagem(usuarioEmail, destinatario, mensagemDestinatario);
    }

    /*
    Pede informação ao usuário para enviar uma nova mensagem.
    */
    void enviar()
    {
        if (!logged)
        {
            erro("você precisa fazer login pra enviar uma mensagem.");
            return;
        }

        int nPessoas = 3;
        std::vector<std::string> listaPessoas = ultimasPessoas(usuarioEmail, nPessoas);
        nPessoas = listaPessoas.size();

        std::string prompt = "Com quem você quer conversar?";
        std::cout << prompt << std::endl;
        std::cout << "0 - Cancelar" << std::endl;
        std::cout << "1 - Nova conversa" << std::endl;
        for (int i=0; i<listaPessoas.size(); i++)
        {
            std::cout << i+2 << " - " << listaPessoas[i] << std::endl;
        }

        int indiceDestinatario;

        while(true)
        {
            prompt = "Digite um número: ";
            std::cout << prompt;
            std::string strIndiceDestinatario;
            std::getline(std::cin, strIndiceDestinatario);
            bool flagNumero = false;
            try 
            {
                indiceDestinatario = stoi(strIndiceDestinatario);
            }
            catch(...) 
            {
                flagNumero = true;
            }
            if (indiceDestinatario < 0 or indiceDestinatario > nPessoas+1)
            {
                flagNumero = true;
            }
            if (flagNumero) 
            {
                erro("digite um número válido.");
            }
            else 
            {
                break;
            }
        }

        if (indiceDestinatario == 0)
        {
            return;
        }
        else if (indiceDestinatario != 1)
        {
            novaMensagem(listaPessoas[indiceDestinatario-2]);
        }
        else {
            std::string destinatario;
            std::cout << "Digite o email do recipiente: ";
            std::getline(std::cin, destinatario);
            novaMensagem(destinatario);
        }
        
        return;
    }

    /*
    Inicialização da comunicação com o banco de dados.
    */
    void init_db()
    {
        std::cout << "Initializing database...\n";
        try { // dbname = public 
           C = new pqxx::connection("user = postgres password = postgres123 \
           hostaddr = 127.0.0.1 port = 5432");
           if (C->is_open()) {
              std::cout << "Opened database successfully: " << C->dbname() << std::endl;
           } else {
              std::cout << "Can't open database" << std::endl;
              return;
           }
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
    
    void close_db()
    {
        C->close();
        delete C;
    }
    
    /*
    Shell interativa que recebe o input do usuario e executa os comandos.
    Fica em loop recebendo os comandos do usuário até ser encerrada.
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
                //pra lidar com ctrl+D/EOF
            }
    
            if (comando == "ajuda")
            {
                ajuda();
            }
            else if (comando == "login")
            {
                login();
            }
            else if (comando == "logout")
            {
                logout();
            }
            else if (comando == "chat") 
            {
                chat();
            }
            else if (comando == "ler")
            {
                ler();
            }
            else if (comando == "enviar")
            {
                enviar();
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

    pqxx::connection *C;
};

int main()
{
    mensagem estado;
    estado.init_db();
    estado.shell();
    return 0;
}
