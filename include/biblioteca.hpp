#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "usuario.hpp"
#include "bibliotecario.hpp"
#include "acervo.hpp"
#include "pessoa.hpp"
#include "reservas.hpp"
#include <string>
#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Biblioteca{
    
    private:
        int senhaAdministradora = 1010;
        vector<Usuario> usuarios;
        vector<Bibliotecario> bibliotecarios;
        Acervo acervoDeLivros;
        vector<int> salas = {1,2,3,4,5,6,7,8,9,10};
        vector<int> armarios = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        Reservas reservas;
    
    public:
        
         /**
         * @brief Constroi o administrador da biblioteca com a senha padrão sendo o ano vigente.
         */
        Biblioteca();
    
         /**
         * @brief Método que acessa a senha.
         * @return O retorno é um inteiro contendo a senha.
         */
        int getSenha();
    
         /**
         * @brief Método que altera a senha.
         * @param _novaSenha Valor inteiro que contém a nova senha.
         */
        void setSenha(int _novaSenha);
    
         /**
         * @brief Método que remove um livro do Acervo.
         * @param Livro Parâmetro que contém o livro a ser emprestado.
         */
        void emprestarLivro(Livro);
    
         /**
         * @brief Método que adiciona novamente o livro ao Acervo.
         * @param Livro Parâmetro que contém o livro a ser emprestado.
         */
        void devolverLivro(Livro);
    
         /**
         * @brief Método que cadastra usuários ao sistema de Biblioteca.
         * @param Usuario Parâmetro que contém o usuário a ser cadastrado ao sistema.
         */
        void cadastrarUsuarios(Usuario);
    
         /**
         * @brief Método que remove um usuário já cadastrado ao sistema de Biblioteca.
         * @param Usuario Parâmetro que contém o usuário a ser removido do sistema de Biblioteca.
         */
        void removerUsuarios(Usuario);
    
         /**
         * @brief Método que cadastra um bibliotecário ao sistema de Biblioteca.
         * @param Bibliotecario Parâmetro que contém o bibliotecário a ser cadastrado ao sistema.
         */
        void cadastrarBibliotecarios(Bibliotecario);
    
         /**
         * @brief Método que remove um bibliotecário já cadastrado ao sistema de Biblioteca.
         * @param Bibliotecario Parâmetro que contém o bibliotecário a ser removido do sistema de Biblioteca.
         */
        void removerBibliotecarios(Bibliotecario);
    
         /**
         * @brief Método que procura se há um cadastro no sistema de um bibliotecário específico através do seu número de registro.
         * @param _registro Parâmetro que contém o número de registro do Bibliotecário.
         * @return Bibliotecario Retorna o Bibliotecário procurado ou um bibliotecário vazio, caso não tenha o pesquisado.
         */
        Bibliotecario procurarBibliotecario(int); 
        
         /**
         * @brief Método que procura se há um cadastro no sistema de um usuário específico através do seu número de matrícula.
         * @param _matricula Parâmetro que contém o número de matrícula do Usuário.
         * @return Usuario Retorna o Usuário procurado ou um usuário vazio, caso não tenha o pesquisado.
         */
        Usuario procurarUsuario(int);
    
         /**
         * @brief Método que procura se o bibliotecário está cadastrado.
         * @param Bibliotecario Parâmetro que conrém um Bibliotecário.
         * @return Retorna true ou false.
         */
        bool checarCadastro(Bibliotecario);
    
         /**
         * @brief Método que procura se o usuário está cadastrado.
         * @param Usuário Parâmetro que conrém um Bibliotecário.
         * @return Retorna true ou false.
         */
        bool checarCadastro(Usuario);
    
         /**
         * @brief Método que imprime os usuários e bibliotecários cadastrados ao sistema.
         */
        void verBiblioteca(void);
    
         /**
         * @brief Método que busca se uma sala ou armário está disponpivel na lista da biblioteca.
         * @param _sala sala a ser verificada.
         * @param _armario armario a ser verificado.
         * @return retorna um booleano indicando se a sala ou armpario estão disponpiveis.
         */
        bool find(int _sala, int _armario);
    
         /**
         * @brief Método que apaga o armário ou sala selecionados do vetor.
         * @param _sala sala a ser retirada do vetor de salas disponíveis.
         * @param _armario armario a ser retirado do vetor de armários disponpiveis
         */
        void erase(int _sala, int _armario);
    
        /**
         * @brief Método que apaga adiciona a sala ou armário devolvido ao vetor.
         * @param _sala sala a ser adicionada no vetor de salas disponíveis.
         * @param _armario armario a ser adicionado no vetor de armários disponpiveis
         */
        void add(int _sala, int _armario);
    
        /**
         * @brief Método que empresta uma sala ou armário para um usuário.
         * @param _sala sala a ser emprestada.
         * @param _armario armario a ser emprestado.
         * @param _matricula do usuário que solicita a reserva.
         */
        void emprestar(int _sala, int _armario, int _matricula);
    
        /**
         * @brief Método que devolve uma sala ou armário que o usuário usou.
         * @param _sala sala a ser devolvida.
         * @param _armario armario a ser devolvido.
         * @param _matricula do usuário que devolve a reserva.
         */
        void devolver(int _sala, int _armario, int _matricula);
    
        /**
         * @brief Método que consulta as reservas feitas.
         */
        void consultarReservas();
        

};

#endif
