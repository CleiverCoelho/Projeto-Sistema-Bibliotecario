#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <iostream>
#include <string>

using namespace std;

class Livro{
    private:
        static int _count;
        string titulo;
        string autor;
        int codigo;
        string estadoConservacao;
        string genero;
    
    public:
        int qtdExemplares;
    
        /**
         * @brief Construtor de um Livro que contém todos os seus parâmetros.
         * @param _titulo Parâmetro que contém o título do Livro.
         * @param _autor Parâmetro que contém o autor do Livro.
         * @param _estadoConservacao Parâmetro que contém o estado de conservação do Livro.
         * @param _genero Parâmetro que contém o gênero do Livro.
         * @param _qtdExemplares Parâmetro que contém a quantidade de exemplares do Livro.
         */
        Livro(string _titulo, string _autor, string _estadoConservacao, string _genero, int _qtdExemplares);
    
        /**
         * @brief Construtor de um Livro que contém todos os seus parâmetros.
         * @param _titulo Parâmetro que contém o título do Livro.
         * @param _autor Parâmetro que contém o autor do Livro.
         * @param _estadoConservacao Parâmetro que contém o estado de conservação do Livro.
         * @param _genero Parâmetro que contém o gênero do Livro.
         */
        Livro(string _titulo, string _autor, string _estadoConservacao, string _genero);
    
        /**
         * @brief Construtor padrão de um Livro.
         */
        Livro();
    
        /**
         * @brief Método que consegue acessar o título do livro.
         * @return titulo Uma string que contém o título do livro.
         */
        string getTitulo();
    
        /**
         * @brief Método que consegue acessar o código do livro.
         * @return codigo Um inteiro que contém o código do livro.
         */
        int getCodigo();
    
        /**
         * @brief Método que consegue acessar o gênero do livro.
         * @return genero Uma string que contém o gênero do livro.
         */
        string getGenero();
    
        /**
         * @brief Método que imprime as informações de um livro, ou seja, seu título, autor, código e o estado de conservação.
         */
        void print();
};

#endif
