#include "pocion.hpp"
#include <iostream>
using namespace std;

Pocion :: Pocion()
    : Items_Mag("Pocion", 30, 5, Elemento::Acuatico , 20.0) {}

void Pocion :: usar() {
    if (mana <= 0) {
        cout << "No tenes suficiente mana para usar la pocion." << endl;
    } else {
        cout << "La pocion de "<< getElemento() << "ha hecho " << danio << "de daño." << endl;
        mana -= 1;
    }
}

void Pocion :: reparar() {
    cout << "Recargando el mana..." << endl;
    mana = 5;
}

void Pocion :: mostrarInfo() const {
    cout << "Información del item magico:" << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Daño: " << getDanio() << endl;
    cout << "Mana: " << getMana() << endl;
    cout << "Elemento: " << getElemento() << endl;
    cout << "Alcance: " << getAlcance() << endl;
}
