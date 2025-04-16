#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PersonajeFactory.hpp"

using namespace std;

/*
Este archivo contiene la implementación del programa principal que simula la creación y visualización de personajes aleatorios (magos y guerreros) 
con armas, y muestra sus detalles en consola.
1) Inicialización de números aleatorios: La función srand() inicializa el generador de números aleatorios utilizando la hora actual (time(0)), 
lo que garantiza que se obtendrán diferentes resultados en cada ejecución.

2) Generación aleatoria de personajes:
    - Magos: Se generan entre 3 y 7 personajes magos utilizando rand() % 5 + 3, y luego se asignan armas aleatorias a cada uno utilizando el método 
    crearPersonajeConArma() de la clase PersonajeFactory. Los personajes se agregan al vector personajes solo si su clase es "Mago".
    - Guerreros: De manera similar, se generan entre 3 y 7 personajes guerreros. Se asegura que solo se agreguen guerreros a la lista, verificando 
    que el personaje creado sea de la clase "Guerrero".
    - Visualización de personajes: Luego de crear todos los personajes (magos y guerreros), el programa recorre el vector personajes e imprime la 
    información de cada uno (como nombre, vida, estamina, etc.) junto con el daño estimado que pueden causar en un ataque utilizando el método 
    hacerDanio().
En este archivo demuestro la integración de las clases y métodos creados en el resto del proyecto, mostrando la flexibilidad de la PersonajeFactory
para generar personajes y asignarles armas de forma aleatoria.
*/

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
