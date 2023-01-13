#include "bibliotecario.hpp"

using namespace std;

Bibliotecario::Bibliotecario(string _nome, int _idade, long int _cpf, int _registro, 
    int _chaveAcesso) : Pessoa(_nome, _idade, _cpf){
        this->registro = _registro;
        this->chaveAcesso = _chaveAcesso;
}

Bibliotecario::Bibliotecario(){}

void Bibliotecario::setChaveAcesso(int chaveAntiga, int chaveNova){
    if (chaveAntiga == this->chaveAcesso){
        this->chaveAcesso = chaveNova;
    }else{
        cout << "Não foi possível redefinir a senha. Chave de Acesso antiga ERRADA!" << endl;
    }
}

int Bibliotecario::getChaveAcesso(){
    return this->chaveAcesso;
}

int Bibliotecario::getRegistro(){
    return this->registro;
}

void Bibliotecario::print(){
    cout << "Nome: " << getNome() << endl;
    cout << "Idade: " << getIdade() << endl;
    cout << "Registro: " << this->registro << endl;
    return;
}
