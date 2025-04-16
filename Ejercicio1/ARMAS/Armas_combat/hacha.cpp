#include "hacha.hpp"
#include <iostream>
using namespace std;

Hacha :: Hacha()
    : ArmaCombate("Hacha", 30, 100, Rareza::Ascendente, AtaqueEspecial::GolpeRelampago) {}

void Hacha :: usar() {
    if (durabilidad > 0) {
        cout << "Atacás con el hacha infligiendo " << danio << " de daño." << endl;
        durabilidad -= 20;
    } else {
        cout << "El hacha está rota. ¡Necesita reparación!" << endl;
    }
}

void Hacha :: reparar() {
    cout << "Reparando el hacha..." << endl;
    durabilidad = 100;
}

void Hacha :: mostrarInfo() const {
    cout << "---- HACHA ----" << endl;
    ArmaCombate :: mostrarInfo();
}
