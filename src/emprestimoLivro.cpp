#include "emprestimoLivro.hpp"

using namespace std;

EmprestimoLivro::EmprestimoLivro(Usuario _usuario, Livro _livro){
    this->usuario = _usuario;
    this->livro = _livro;
    this->statusEmprestimo = false;
}

EmprestimoLivro::EmprestimoLivro(){
    this->statusEmprestimo = false;
}

Usuario EmprestimoLivro::getUsuario(){
    return this->usuario;
}
Livro EmprestimoLivro::getLivro(){
    return this->livro;
}
bool EmprestimoLivro::getStatusEmprestimo(){
    return this->statusEmprestimo;
}

void EmprestimoLivro::setStatusEmprestimo(bool valorLogico){
    this->statusEmprestimo = valorLogico;
    return;
}
