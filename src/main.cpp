#include "blablatable.h"
#include "msgsUsuarios.h"

#include <iostream>
#include <string>
#include <algorithm>

struct mensagem
{
    std::string usuarioEmail; // Email do usuário
    bool logged = false; // Estado (logado/deslogado)
    
    /*
    Imprime uma mensagem de erro na shell.
    */
    void erro(std::string mensagemErro)
    {
        std::cout << "ERRO: " << mensagemErro << std::endl;
        return;
    }

    /*
    Mostra uma lista de opções e retorna uma escolha entre elas.
    */
    int escolheDaLista(std::vector<std::string> opcoes)
    {
        for (int i=0; i<(int)opcoes.size(); i++)
        {
            std::cout << i << " - " << opcoes[i] << std::endl;
        }

        while(true)
        {
            std::string prompt = "Digite um número: ";
            std::cout << prompt;
            int opcao;
            std::string strOpcao;
            std::getline(std::cin, strOpcao);
            bool flagOpcao = false;
            try 
            {
                opcao = stoi(strOpcao);
            }
            catch(...) 
            {
                flagOpcao = true;
            }
            if (opcao < 0 or opcao >= (int)opcoes.size())
            {
                flagOpcao = true;
            }
            if (flagOpcao) 
            {
                erro("digite um número válido.");
            }
            else 
            {
                return opcao;
            }
        }

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
        bool validadeEmail = T.existeEmail(email);
        if (!validadeEmail)
        {
            erro("email inválido. Tente novamente.");
            return;
        }
    
        prompt = "Senha: ";
        std::cout << prompt;

        std::string senha;
        std::getline(std::cin, senha);
        bool validadeSenha = T.matchEmailSenha(email, senha);
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
    Faz logout do usuário.
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
    
    void mostraMensagens(std::vector<msg>& mensagens)
    {
        if (mensagens.empty())
        {
            std::cout << "Nada pra mostrar por aqui..." << std::endl;
            return;
        }
        int tamanhoLinha = 10;
        std::string reta;
        for (int i=0; i<tamanhoLinha; i++)
        {
            reta += std::string("─");
        }
        std::string tela;

        for (int i=0; i<(int)mensagens.size(); i++)
        {
            tela += std::string("┌") + reta + "\n";

            msg atual = mensagens[i];
            std::string prefixo, outraPessoa;
            if (atual.remetente == usuarioEmail)
            {
                prefixo = "(você) ";
                outraPessoa = atual.destinatario;
            }
            else
            {
                outraPessoa = atual.remetente;
            }
        

            tela += std::string()+ 
            "│ " + outraPessoa + "\n"+
            "│ " + atual.timeStamp + "\n"+
            "│ " + prefixo + atual.conteudoMensagem + "\n";
            
        }
        std::cout << tela;
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

        int nMensagens = 6;
        std::vector<msg> mensagensParaMostrar = T.ultimasMensagens(
            usuarioEmail,
            nMensagens);
        
        mostraMensagens(mensagensParaMostrar);
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
    void ler()
    {
        if (!logged)
        {
            erro("faça login para ver suas mensagens com alguém.");
            return;
        }
        int nMensagens = 6;
        int nPessoas = 5;
        std::string outraPessoa;

        std::vector<std::string> listaPessoas = T.ultimasPessoas(usuarioEmail, nPessoas);
        std::vector<std::string> listaOpcoes = {"Cancelar", "Outro usuário"};
        listaOpcoes.insert(
            listaOpcoes.end(), 
            listaPessoas.begin(), 
            listaPessoas.end());

        int indiceDestinatario = escolheDaLista(listaOpcoes);

        if (indiceDestinatario == 0)
        {
            return;
        }
        else if (indiceDestinatario != 1)
        {
            outraPessoa = listaPessoas[indiceDestinatario-2];
        }
        else {
            std::string destinatario;
            std::cout << "Digite o email do usuário: ";
            std::getline(std::cin, destinatario);
            if (!T.existeEmail(destinatario))
            {
                erro("Esse usuário não existe.");
                return;
            }
            outraPessoa = destinatario;
        }

        std::vector<msg> mensagensParaMostrar = T.ultimasMensagensIndividuais(
            usuarioEmail,
            outraPessoa,
            nMensagens);
        
        std::reverse(mensagensParaMostrar.begin(), mensagensParaMostrar.end());
        
        mostraMensagens(mensagensParaMostrar);
        return;
    }

    /*
    envia uma nova mensagem para o email `destinatario`
    */
    void novaMensagem(std::string destinatario)
    {
        if (!T.existeEmail(destinatario))
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
        
        T.enviaMensagem(usuarioEmail, destinatario, mensagemDestinatario);
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

        int nPessoas = 4;
        std::vector<std::string> listaPessoas = T.ultimasPessoas(usuarioEmail, nPessoas);

        std::string prompt = "Com quem você quer conversar?";
        std::cout << prompt << std::endl;

        std::vector<std::string> listaOpcoes = {"Cancelar", "Nova conversa"};
        listaOpcoes.insert(
            listaOpcoes.end(), 
            listaPessoas.begin(), 
            listaPessoas.end());


        int indiceDestinatario = escolheDaLista(listaOpcoes);

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

	if (!T.is_ok()) { std::cout << "Saindo...\n"; return; }

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

    BlaBlaTable T; // Encapsulamento das operações de banco de dados.
};

int main()
{
    mensagem estado;
    //estado.init_db();
    estado.shell();
    return 0;
}
