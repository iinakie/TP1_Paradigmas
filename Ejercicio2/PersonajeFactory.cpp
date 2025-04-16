#include "PersonajeFactory.hpp"

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
