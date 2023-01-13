#include "reservas.hpp"
 
using namespace std;

void Reservas::setCodigo(string _codigo){
    this->reservas.push_back(_codigo);
}

void Reservas::removeCodigo(string _codigo){
    for (int i=0; i< reservas.size(); i++){
        if (reservas[i] == _codigo){
            reservas.erase(reservas.begin()+i);
        }
    }
}

void Reservas::printReservas(){
    if (reservas.empty()) cout <<"Não há nenhuma reserva de salas ou armários."<< endl;
    else {
        for (int i=0; i< reservas.size(); i++){
            cout << reservas[i] << endl;
        }
    }
}
