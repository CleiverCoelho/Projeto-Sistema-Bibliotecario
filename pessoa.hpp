#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>

using namespace std;

class Pessoa {
    private:
        string nome;
        int idade;
        long int cpf;
    public:
         /**
         * @brief Construtor de Pessoa que contém todos os seus parâmetros.
         * @param _nome Parâmetro que contém o nome da pessoa.
         * @param _idade Parâmetro que contém a idade da pessoa.
         * @param _cpf Parâmetro que contém o CPF da pessoa.
         */
        Pessoa(string, int, long int);
    
         /**
         * @brief Construtor padrão de Pessoa.
         * 
         */
        Pessoa();
    
        /**
         * @brief Método virtual puro que será futuramente reescrito para printar as informações.
         */
        virtual void print() = 0;
    
         /**
         * @brief Método que consegue acessar o nome da Pessoa.
         * @return nome Uma string que contém o nome da Pessoa.
         */
        string getNome();
    
        /**
         * @brief Método que consegue acessar a idade da Pessoa.
         * @return idade Um inteiro que contém a idade da Pessoa.
         */
        int getIdade();

};

#endif
