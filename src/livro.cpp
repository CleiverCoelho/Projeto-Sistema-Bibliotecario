#include "livro.hpp"

using namespace std;

Livro::Livro(string _titulo, string _autor, string _estadoConservacao, string _genero, int _qtdExemplares){
    _count++;
    this->titulo = _titulo;
    this->autor = _autor;
    this->codigo = _count;
    this->estadoConservacao = _estadoConservacao;
    this->genero = _genero;
    this->qtdExemplares = _qtdExemplares;

}

Livro::Livro(string _titulo, string _autor, string _estadoConservacao, string _genero){
    _count++;
    this->titulo = _titulo;
    this->autor = _autor;
    this->codigo = _count;
    this->estadoConservacao = _estadoConservacao;
    this->genero = _genero;
    this->qtdExemplares = 1;
}

Livro::Livro(){
    _count++;
   this->qtdExemplares = 0;
}

int Livro::_count = 1000;

string Livro::getTitulo(){
    return this->titulo;
}

int Livro::getCodigo(){
    return this->codigo;
}

string Livro::getGenero(){
    return this->genero;
}

void Livro::print(){
    cout << endl;
    cout << "LIVRO"<< endl << "Título: " << this->titulo << endl << "Autor: " << this->autor << endl;
    cout << "Código: " << this->codigo<<endl << "Estado de conservação: " << this->estadoConservacao << endl << endl;
}
