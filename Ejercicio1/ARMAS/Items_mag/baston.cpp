#include "baston.hpp"
#include <iostream>
using namespace std;

Baston :: Baston()
    : Items_Mag("Baston", 50, 5, Elemento::Luz , 40.0) {}

void Baston :: usar() {
    if (mana <= 0) {
        cout << "No tenes suficiente mana para usar el baston." << endl;
    } else {
        cout << "El baston de "<< getElemento() << "ha hecho " << danio << "de daño." << endl;
        mana -= 1;
    }
}

void Baston :: reparar() {
    cout << "Recargando el mana..." << endl;
    mana = 5;
}

void Baston :: mostrarInfo() const {
    cout << "Información del item magico:" << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Daño: " << getDanio() << endl;
    cout << "Mana: " << getMana() << endl;
    cout << "Elemento: " << getElemento() << endl;
    cout << "Alcance: " << getAlcance() << endl;
}
