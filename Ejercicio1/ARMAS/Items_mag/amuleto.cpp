#include "amuleto.hpp"
#include <iostream>
using namespace std;

Amuleto :: Amuleto()
    : Items_Mag("Amuleto", 30, 5, Elemento::Fuego , 20.0) {}

void Amuleto :: usar() {
    if (mana <= 0) {
        cout << "No tenes suficiente mana para usar el amuleto." << endl;
    } else {
        cout << "El amuleto de "<< getElemento() << "ha hecho " << danio << "de daño." << endl;
        mana -= 1;
    }
}

void Amuleto :: reparar() {
    cout << "Recargando el mana..." << endl;
    mana = 5;
}

void Amuleto :: mostrarInfo() const {
    cout << "Información del item magico:" << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Daño: " << getDanio() << endl;
    cout << "Mana: " << getMana() << endl;
    cout << "Elemento: " << getElemento() << endl;
    cout << "Alcance: " << getAlcance() << endl;
}
