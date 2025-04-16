#include "hachaD.hpp"
#include <iostream>
using namespace std;

HachaD :: HachaD()
    : ArmaCombate("HachaD", 40, 100, Rareza::Ascendente, AtaqueEspecial::GolpeRelampago) {}

void HachaD :: usar() {
    if (durabilidad > 0) {
        cout << "Atacás con el hacha doble infligiendo " << danio << " de daño." << endl;
        durabilidad -= 20;
    } else {
        cout << "El hacha doble está rota. ¡Necesita reparación!" << endl;
    }
}

void HachaD :: reparar() {
    cout << "Reparando el hacha doble..." << endl;
    durabilidad = 100;
}

void HachaD :: mostrarInfo() const {
    cout << "---- HACHA DOBLE ----" << endl;
    ArmaCombate :: mostrarInfo();
}
