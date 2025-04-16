#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PersonajeFactory.hpp"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    int cantidadMagos = rand() % 5 + 3;      // de 3 a 7
    int cantidadGuerreros = rand() % 5 + 3;  // de 3 a 7

    vector<shared_ptr<IPersonajes>> personajes;

    // Crear los magos
    for (int i = 0; i < cantidadMagos; ++i) {
        shared_ptr<IPersonajes> mago;
        do {
            mago = PersonajeFactory::crearPersonajeConArma();
        } while (mago->getClase() != "Mago");
        personajes.push_back(mago);
    }

    // Crear los guerreros
    for (int i = 0; i < cantidadGuerreros; ++i) {
        shared_ptr<IPersonajes> guerrero;
        do {
            guerrero = PersonajeFactory::crearPersonajeConArma();
        } while (guerrero->getClase() != "Guerrero");
        personajes.push_back(guerrero);
    }

    // Mostrar todos
    for (size_t i = 0; i < personajes.size(); ++i) {
        cout << "\nPersonaje #" << (i + 1) << ":\n";
        personajes[i]->mostrarInfo();
        cout << "Daño estimado al atacar: " << personajes[i]->hacerDanio() << endl;
    }

    return 0;
}
