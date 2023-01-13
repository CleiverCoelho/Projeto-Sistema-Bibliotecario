#include "pessoa.hpp"

Pessoa::Pessoa(string _nome, int _idade, long int _cpf){
    this->nome = _nome;
    this->idade = _idade;
    this->cpf = _cpf;
}

Pessoa::Pessoa(){
}

void Pessoa::print(){
    cout << "Nome: " << endl;
    cout << "Idade: " << endl;
}

string Pessoa::getNome(){
    return this->nome;
}
int Pessoa::getIdade(){
    return this->idade;
} 
