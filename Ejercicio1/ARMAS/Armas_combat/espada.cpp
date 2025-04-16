#include "espada.hpp"
#include <iostream>
using namespace std;

Espada :: Espada()
    : ArmaCombate("Espada", 35, 100, Rareza::Primitivo, AtaqueEspecial::GolpeRelampago) {}

void Espada :: usar() {
    if (durabilidad > 0) {
        cout << "Atacás con la espada infligiendo " << danio << " de daño." << endl;
        durabilidad -= 20;
    } else {
        cout << "La espada está rota. ¡Necesita reparación!" << endl;
    }
}

void Espada :: reparar() {
    cout << "Reparando la espada..." << endl;
    durabilidad = 100;
}

void Espada :: mostrarInfo() const {
    cout << "---- ESPADA ----" << endl;
    ArmaCombate :: mostrarInfo();
}
