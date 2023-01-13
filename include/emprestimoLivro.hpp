#ifndef EMPRESTIMOLIVRO_HPP
#define EMPRESTIMOLIVRO_HPP

#include "usuario.hpp"
#include "livro.hpp"
#include <string>
#include <iostream>
#include <vector>

class EmprestimoLivro{
    private:
        Usuario usuario;
        bool statusEmprestimo;
        Livro livro;

    public:
    
         /**
         * @brief Método que atribui um livro a um usuário.
         * @param Usuario Parâmetro que contém o Usuario.
         * @param Livro Parâmetro que contém um Livro.
         */
        EmprestimoLivro(Usuario, Livro);
    
         /**
         * @brief Método que atribui false ao parâmetro status de empréstimo.
         */
        EmprestimoLivro();

         /**
         * @brief Método que retorna o Usuário que pegou o livro emprestado.
         * @return Retorna o Usuário.
         */
        Usuario getUsuario();
    
         /**
         * @brief Método que retorna o Livro emprestado.
         * @return Retorna o Livro.
         */
        Livro getLivro();
    
         /**
         * @brief Método que retorna o status do empréstimo.
         * @return Retorna true ou false.
         */
        bool getStatusEmprestimo();
    
         /**
         * @brief Método que altera o status do empréstimo.
         * @param valorLogico Contém um valor booleano, true ou false.
         */
        void setStatusEmprestimo(bool);

};

#endif
