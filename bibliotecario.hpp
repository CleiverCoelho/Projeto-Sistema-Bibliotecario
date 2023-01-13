#ifndef BIBLIOTECARIO_HPP
#define BIBLIOTECARIO_HPP

#include "pessoa.hpp"
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Bibliotecario : public Pessoa{
    private:
        int registro;
        int chaveAcesso;

    public:
    
         /**
         * @brief Construtor de Bibliotecário. Ele consegue instanciar os parâmtros de um bibliotecário.
         * @param _nome Parâmetro que possui o nome do Bibliotecário.
         * @param _idade Parâmetro que possui a idade do Bibliotecário.
         * @param _cpf Parâmetro que possui o CPF do Bibliotecário.
         * @param _registro Parâmetro que possui o número de registro do Bibliotecário.
         * @param _chaveAcesso Parâmetro que possui a senha do Bibliotecário.
         */
        Bibliotecario(string, int, long int, int, int);
    
         /**
         * @brief Construtor padrão de Bibliotecário.
         */
        Bibliotecario();
        
         /**
         * @brief Método que consegue acessar o registro privado do Bibliotecário.
         * @return registro Retorna o número de registro do Bibliotecário.
         */
        int getRegistro();
    
         /**
         * @brief Método que consegue acessar a senha privada do Bibliotecário.
         * @return chaveAcesso Retorna a senha de acesso do Bibliotecário.
         */
        int getChaveAcesso();
    
         /**
         * @brief Método que consegue modificar a senha de acesso do Bibliotecário.
         * @param chaveAntiga Parâmetro que contém a senha antiga do Bibliotecário.
         * @param chaveNova Parâmetro que contém a nova senha do Bibliotecário.
         */
        void setChaveAcesso(int, int);
    
         /**
         * @brief Método que printa as informações do Bibliotecário, ou seja, seu nome, idade e registro.
         */
        void print() override;
};

#endif
