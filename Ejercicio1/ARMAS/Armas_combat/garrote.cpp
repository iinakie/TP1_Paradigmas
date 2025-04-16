#include "garrote.hpp"
#include <iostream>
using namespace std;

Garrote :: Garrote()
    : ArmaCombate("Garrote", 20, 100, Rareza::Primitivo, AtaqueEspecial::GolpeRelampago) {}

void Garrote :: usar() {
    if (durabilidad > 0) {
        cout << "Atacás con el garrote infligiendo " << danio << " de daño." << endl;
        durabilidad -= 20;
    } else {
        cout << "El garrote está roto. ¡Necesita reparación!" << endl;
    }
}

void Garrote :: reparar() {
    cout << "Reparando el agarrote..." << endl;
    durabilidad = 100;
}

void Garrote :: mostrarInfo() const {
    cout << "---- GARROTE ----" << endl;
    ArmaCombate :: mostrarInfo();
}
