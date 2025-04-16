#include "libro_hechizos.hpp"
#include <iostream>
using namespace std;

LibroHechizos :: LibroHechizos()
    : Items_Mag("Libro de Hechizos", 55, 5, Elemento::Oscuridad , 10.0) {}

void LibroHechizos :: usar() {
    if (mana <= 0) {
        cout << "No tenes suficiente mana para usar el libro de hechizos." << endl;
    } else {
        cout << "El libro de hechizos de "<< getElemento() << "ha hecho " << danio << "de daño." << endl;
        mana -= 1;
    }
}

void LibroHechizos :: reparar() {
    cout << "Recargando el mana..." << endl;
    mana = 5;
}

void LibroHechizos :: mostrarInfo() const {
    cout << "Información del item magico:" << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Daño: " << getDanio() << endl;
    cout << "Mana: " << getMana() << endl;
    cout << "Elemento: " << getElemento() << endl;
    cout << "Alcance: " << getAlcance() << endl;
}
