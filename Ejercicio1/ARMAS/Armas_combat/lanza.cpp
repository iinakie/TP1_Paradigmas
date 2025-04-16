#include "lanza.hpp"
#include <iostream>
using namespace std;

Lanza :: Lanza()
    : ArmaCombate("Espada", 25, 100, Rareza::Primitivo, AtaqueEspecial::GolpeRelampago) {}

void Lanza :: usar() {
    if (durabilidad > 0) {
        cout << "Atacás con la lanza infligiendo " << danio << " de daño." << endl;
        durabilidad -= 20;
    } else {
        cout << "La lanza está rota. ¡Necesita reparación!" << endl;
    }
}

void Lanza :: reparar() {
    cout << "Reparando la lanza..." << endl;
    durabilidad = 100;
}

void Lanza :: mostrarInfo() const {
    cout << "---- LANZA ----" << endl;
    ArmaCombate :: mostrarInfo();
}
