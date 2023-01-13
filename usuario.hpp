#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <iostream>
#include <list>
#include "reservas.hpp"
#include "pessoa.hpp"
#include "livro.hpp"

using namespace std;

class Usuario : public Pessoa{
    private:
        int matricula;
        list<Livro> livrosEmprestados;

    public:
        /**
         * @brief Construtor de Usuário que contém todos os seus parâmetros.
         * @param _nome Parâmetro que contém o nome do Usuário.
         * @param _idade Parâmetro que contém a idade do Usuário.
         * @param _cpf Parâmetro que contém o CPF do Usuário.
         * @param _matricula Parâmetro que contém o número de matrícula do Usuário.
         */
        Usuario(string, int, long int, int);
    
        /**
         * @brief Construtor padrão de Usuário.
         */
        Usuario();
    
        /**
         * @brief Método que consegue acessar o número de matrícula do usuário.
         * @return matricula Um inteiro que contém o número de matrícula do usuário.
         */
        int getMatricula(void);
    
         /**
         * @brief Método que imprime as informações de usuário.
         */
        void print(void) override;
};

#endif
