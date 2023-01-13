#include "livro.hpp"
#include "acervo.hpp"
#include "biblioteca.hpp"
#include "bibliotecario.hpp"
#include "usuario.hpp"
#include <fstream>
#include <algorithm>

int main() {
    int op;
    int op2;
    int senha;
    string nome;
    int idade;
    long int cpf;
    int matricula;
    int registro;
    int chave;
    string titulo = "";
    string autor = "";
    int codigo;
    string estadoConservacao;
    string genero;
    int quantidade;
    int sala;
    int armario;
    Biblioteca administrador;
    Acervo acervoGeral;
    
    cout << endl << "Seja bem-vindo(a) ao Sistema Bibliotecário do Instituto de Engenharia Nikola Tesla ⚡" << endl << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "Menu principal" << endl << endl;
    cout << "Selecione o modo de entrada: " << endl << "[1] - Administrador" << endl << "[2] - Bibliotecário" << endl << "[3] - Usuário" << endl << endl;
    while (cin >> op){
        switch (op) {
        case 1:
            cout << "Olá administrador, por favor insira sua senha para prosseguir: " <<endl;
            cin >> senha; 
            if (senha == administrador.getSenha()){
                op2=0;
                cout << "Menu de opções do administrador: " <<endl;
                cout << "[1] - Cadastro de usuários" << endl << "[2] - Cadastro de bibliotecários" << endl << "[3] - Cadastro de livros no acervo" << endl;
                cout << "[4] - Descadastro de usuário" << endl << "[5] - Descadastro de bibliotecários" << endl << "[6] - Alterar senha" << endl << "[7] - Imprimir Biblioteca" << endl;
                cout << "[8] - Voltar ao menu principal" << endl;
                cin >> op2;
                if (op2 == 1){
                    cout << "Informe o nome, idade, CPF e matrícula do usuário pressionando 'enter' após cada informação: "<< endl;
                    cin.ignore();
                    getline(cin,nome);
                    cin >> idade >> cpf >> matricula;
                    Usuario aluno1(nome, idade, cpf, matricula);
                    administrador.cadastrarUsuarios(aluno1);
                }
                if (op2 == 2) {
                    cout << "Informe o nome, idade, CPF, registro e chave de acesso do bibliotecário pressionando 'enter' após cada informação: "<< endl;
                    cin.ignore();
                    getline(cin,nome);
                    cin >> idade >> cpf >> registro >> chave;
                    Bibliotecario bibliotecario(nome, idade, cpf, registro, chave);
                    administrador.cadastrarBibliotecarios(bibliotecario);
                }
                if (op2 == 3){
                    cout << "Informe o título, autor, código, estado de conservação, gênero e a quantidade do livro pressionando 'enter' após cada informação: "<< endl;
                    cin.ignore();
                    getline(cin,titulo);
                    getline(cin,autor);
                    cin >> codigo >> estadoConservacao;
                    cin >> genero;
                    cin >> quantidade;
                    transform(genero.begin(),genero.end(),genero.begin(),::tolower);
                    if (quantidade == 1){
                        Livro livro(titulo,autor,estadoConservacao, genero);
                        acervoGeral.adicionarLivros(livro);
                    }
                    else {
                        Livro livro(titulo,autor,estadoConservacao, genero, quantidade);
                        acervoGeral.adicionarLivros(livro); 
                    }
                }
                if (op2 == 4){
                    cout << "Digite a matricula do Usuario que deseja remover do sistema" << endl;
                    int matriculaUsu;
                    cin >> matriculaUsu;
                    administrador.removerUsuarios(administrador.procurarUsuario(matriculaUsu));
                    break;
                }
                if (op2 == 5){
                    cout << "Digite o registro do Bibliotecario que deseja remover do sistema: " << endl;
                    int registroBib;
                    cin >> registroBib;
                    administrador.removerBibliotecarios(administrador.procurarBibliotecario(registroBib));
                    break;
                }
                if (op2 == 6){
                    int novaSenha;
                    cout << "Informe uma nova senha: ";
                    cin >> novaSenha;
                    administrador.setSenha(novaSenha);
                    cout << "Senha atualizada com sucesso." << endl;
                }
                if (op2 == 7){
                    administrador.verBiblioteca();
                    acervoGeral.verAcervo();
                } 
                if (op2 ==8){
                    break;
                }
            }
            else {
                cout << "Senha inválida" << endl;
                break;
            }
        break;
        case 2:
            op2 = 0;
            cout << "Olá bibliotecário, informe seu resgistro para continuar: " <<endl;
            cin >> registro;
            cout << "Menu de opções do bibliotecário: " <<endl;
            cout << "[1] - Consultar livro" << endl << "[2] - Cadastro de livros no acervo" << endl << "[3] - Consultar biblioteca" << endl;
            cout << "[4] - Consultar Emprestimos de Livros" << endl <<"[5] - Voltar ao menu principal" << endl;
            cin >> op2;
            if (op2==1){
                cout << "Informe o gênero e o título do livro pressionando 'enter' após cada informação: "<< endl;
                cin.ignore();
                getline(cin,genero);
                getline(cin,titulo);
                acervoGeral.consultarAcervo(genero, titulo);
            }
            if (op2 == 2){
                    cout << "Informe o título, autor, código, estado de conservação, gênero e a quantidade do livro pressionando 'enter' após cada informação: "<< endl;
                    cin.ignore();
                    getline(cin,titulo);
                    getline(cin,autor);
                    cin >> codigo >> estadoConservacao;
                    cin >>genero;
                    cin >> quantidade;
                    transform(genero.begin(),genero.end(),genero.begin(),::tolower);
                    if (quantidade == 1){
                        Livro livro(titulo,autor,estadoConservacao, genero);
                        acervoGeral.adicionarLivros(livro);
                    }
                    else {
                        Livro livro(titulo,autor,estadoConservacao, genero, quantidade);
                        acervoGeral.adicionarLivros(livro); 
                    }
            }
            if (op2 ==3){
                administrador.verBiblioteca();
                acervoGeral.verAcervo();
            }
            if (op2 == 4){
                acervoGeral.verLivrosEmprestados();
                break;
            }
            if (op2 ==5){
                break;
            }
        break;
        case 3:
            op2 = 0;
            cout << "Olá usuário, informe sua matrícula para continuar: " <<endl;
            cin >> matricula;
            cout << "Menu de opções do usuário: " <<endl;
            cout << "[1] - Consultar livro" << endl << "[2] - Empréstimo de livro" << endl << "[3] - Devolução de livro" << endl;
            cout << "[4] - Reservar sala de estudos" << endl << "[5] - Reservar armário" << endl << "[6] - Devolver sala de estudos" << endl;
            cout << "[7] - Devolver armário" << endl << "[8] - Voltar ao menu principal" << endl;
            cin >> op2;
            if (op2==1){
                cout << "Informe o gênero e o título do livro pressionando 'enter' após cada informação: "<< endl;
                cin.ignore();
                getline(cin,genero);
                getline(cin,titulo);
                acervoGeral.consultarAcervo(genero, titulo);
            }
            if (op2 ==2){
                cout << "Informe o gênero e o título do livro pressionando 'enter' após cada informação: "<< endl;
                cin.ignore();
                getline(cin,genero);
                getline(cin,titulo);
                Livro livro = acervoGeral.getLivro(genero, titulo);
                Usuario usuario = administrador.procurarUsuario(matricula);
                acervoGeral.realizarEmprestimo(usuario, livro);
                break;
            }
            if (op2==3){
                cout << "Informe o gênero e o título do livro pressionando 'enter' após cada informação: "<< endl;
                cin.ignore();
                getline(cin,genero);
                getline(cin,titulo);
                Livro livro = acervoGeral.getLivro(genero, titulo);
                if (livro.qtdExemplares == 0){
                    cout << "O livro nao existe no acervo!" << endl;
                    break;
                }
                Usuario usuario = administrador.procurarUsuario(matricula);
                acervoGeral.realizarDevolucao(usuario, livro);
                break;
            }
            if (op2 == 4){
                cout << "Informe a sala e sua matrícula pressionando 'enter' após cada informação: "<< endl;
                cin >> sala >> matricula;
                administrador.emprestar(sala,0,matricula);
            }
            if (op2 == 5){
                cout << "Informe o armário e sua matrícula pressionando 'enter' após cada informação: "<< endl;
                cin >> armario >> matricula;
                administrador.emprestar(0,armario,matricula);
            }
            if (op2 == 6){
                cout << "Informe a sala e sua matrícula pressionando 'enter' após cada informação: "<< endl;
                cin >> sala >> matricula;
                administrador.devolver(sala,0,matricula);
            }
            if (op2 == 7){
                cout << "Informe o armário e sua matrícula pressionando 'enter' após cada informação: "<< endl;
                cin >> armario >> matricula;
                administrador.devolver(0,armario,matricula);
            }
            if (op2 == 8){
                break;
            }

        break;
        }
        
        cout << "----------------------------------------------------------------------------------------------------" << endl;
        cout << "Menu principal" << endl << endl;
        cout << "Selecione o modo de entrada: " << endl << "[1] - Administrador" << endl << "[2] - Bibliotecário" << endl << "[3] - Usuário" << endl << endl;
    }
    return 0;
}
