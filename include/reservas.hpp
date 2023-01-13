#ifndef RESERVAS_HPP
#define RESERVAS_HPP

#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Reservas{
    private:
    vector<string> reservas;

    public:
    
     /**
     * @brief Método que atribui um código a reserva solicitada pelo usuário.
     * @param _codigo Parâmetro que contém o código da reserva.
     */
    void setCodigo(string _codigo);
    
     /**
     * @brief Método que remove o código de reserva.
     * @param _codigo Parâmetro que contém o código da reserva a ser removido.
     */
    void removeCodigo(string _codigo);
    
     /**
     * @brief Método que imprime as reservas feitas.
     */
    void printReservas();
};
#endif
