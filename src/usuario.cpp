#include "usuario.hpp"

Usuario::Usuario(string _nome, int _idade, long int _cpf, int _matricula) : Pessoa(_nome, _idade, _cpf){
    this->matricula = _matricula;
}

Usuario::Usuario(){
}

int Usuario::getMatricula(){
    return this->matricula;
}

void Usuario::print(){
    cout << "Nome: " << getNome() << endl;
    cout << "Idade: " << getIdade() <<endl;
    cout << "Matricula: " << this->matricula << endl;
    return;
}
