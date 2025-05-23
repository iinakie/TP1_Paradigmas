#include "PersonajeFactory.hpp"
#include <memory>
/*
Este archivo implementa los métodos de la clase PersonajeFactory, los cuales se encargan de crear personajes y armas de forma aleatoria y 
asignarlas a los personajes correspondientes. Utiliza la funcionalidad de rand() para garantizar que la creación de personajes y armas sea 
impredecible en cada ejecución.
- crearPersonajeAleatorio(): Este método crea un personaje aleatorio. Usando rand() % 10, se elige un valor entre 0 y 9, donde los primeros 5 
valores representan guerreros (como Barbaro, Paladin, etc.) y los otros 5 representan magos (como Hechicero, Brujo, etc.). Si el valor aleatorio 
no coincide, se crea un Barbaro por defecto.
- crearArmaCompatible(): Dependiendo del tipo de personaje (mago o guerrero), se asigna un arma compatible. Los guerreros pueden tener armas de 
combate (como Espada, Hacha, Lanza, etc.), mientras que los magos reciben ítems mágicos (como Amuleto, Pocion, Baston, etc.).
- crearPersonajeConArma(): Este método primero crea un personaje aleatorio utilizando crearPersonajeAleatorio(), luego le asigna entre 0 y 2 armas 
aleatorias, mediante crearArmaCompatible() y el método agregarArma(), que agrega las armas al personaje.
En esta implementación utilizo punteros inteligentes (shared_ptr) para manejar la memoria automáticamente y evitar fugas de memoria. Además, 
los métodos están diseñados para ser fácilmente extensibles, lo que hace que se pueda agregar más personajes o armas en el futuro con facilidad.
*/


shared_ptr<IPersonajes> PersonajeFactory::crearPersonajeAleatorio() {
    int tipo = rand() % 10; // 0–4 guerreros, 5–9 magos

    switch (tipo) {
        case 0: return make_shared<Barbaro>();
        case 1: return make_shared<Paladin>();
        case 2: return make_shared<Caballero>();
        case 3: return make_shared<Mercenario>();
        case 4: return make_shared<Gladiador>();
        case 5: return make_shared<Hechicero>();
        case 6: return make_shared<Brujo>();
        case 7: return make_shared<Nigromante>();
        case 8: return make_shared<Conjurador>();
        case 9: return make_shared<Hechicero>();
        default: return make_shared<Barbaro>();
    }
}

shared_ptr<IArma> PersonajeFactory::crearArmaCompatible(const string& tipoPersonaje) {
    int tipo = rand() % 5;

    if (tipoPersonaje == "Guerrero") {
        switch (tipo) {
            case 0: return make_shared<Espada>();
            case 1: return make_shared<Hacha>();
            case 2: return make_shared<HachaD>();
            case 3: return make_shared<Lanza>();
            case 4: return make_shared<Garrote>();
        }
    } else {
        switch (tipo) {
            case 0: return make_shared<Amuleto>();
            case 1: return make_shared<Pocion>();
            case 2: return make_shared<Baston>();
            case 3: return make_shared<LibroHechizos>();
            case 4: return make_shared<Pocion>();
        }
    }

    return nullptr;
}

shared_ptr<IPersonajes> PersonajeFactory::crearPersonajeConArma() {
    auto personaje = crearPersonajeAleatorio();
    string tipo = personaje->getClase();

    int cantidadArmas = rand() % 3; // 0–2 armas
    for (int i = 0; i < cantidadArmas; ++i) {
        auto arma = crearArmaCompatible(tipo);
        personaje->agregarArma(arma);
    }

    return personaje;
}
