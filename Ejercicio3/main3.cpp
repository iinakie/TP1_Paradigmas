#include <iostream>
#include <cstdlib>
#include <ctime>
#include "main3.hpp"

using namespace std;

/*
Este archivo contiene el código principal para gestionar una batalla entre dos personajes. Los jugadores pueden elegir a su personaje y su arma, 
mientras que el segundo jugador (enemigo) es generado aleatoriamente. Se sigue un modelo de combate basado en las acciones de "Golpe Fuerte", 
"Golpe Rápido" y "Defensa y Golpe".

1) Creación de personajes:
    - Jugador 1: El usuario elige el personaje y el arma manualmente.
    - Jugador 2: El personaje del enemigo se genera aleatoriamente con un arma.

2) Acciones:
    - Jugador 1 elige una acción entre las tres posibles (con un cin).
    - Jugador 2 tiene su acción seleccionada aleatoriamente.

3) Resolución de la ronda:
    - El combate se resuelve comparando las acciones de ambos jugadores. Dependiendo de las elecciones, el daño se asigna a cada uno. "Golpe Fuerte"
    vence a "Golpe Rápido", "Golpe Rápido" vence a "Defensa y Golpe", y "Defensa y Golpe" bloquea el "Golpe Fuerte".

4) Estado de los jugadores:
    - El código muestra la información del personaje de cada jugador, su arma y los puntos de vida (HP) restantes después de cada ronda.

5) Final del juego:
    - El ciclo de la batalla continúa hasta que uno de los jugadores se le termine sus puntos de vida. El jugador que pierda sus 100 HP primero 
    pierde la batalla.
*/


shared_ptr<IPersonajes> crearPersonajeManual();
shared_ptr<IArma> elegirArmaManual(const string& tipo);

Accion elegirAccionJugador1() {
    int opcion;
    while (true) {
        cin >> opcion;
        if (opcion >= 1 && opcion <= 3) break;
        cout << "Opción inválida. Elegí 1, 2 o 3: ";
    }
    return static_cast<Accion>(opcion);
}

Accion elegirAccionJugador2() {
    int random = rand() % 3 + 1;
    return static_cast<Accion>(random);
}

int resolverRonda(Accion a1, Accion a2) {
    if (a1 == a2) return 0; // empate

    if (a1 == Accion::GolpeFuerte && a2 == Accion::GolpeRapido) return 1;
    if (a1 == Accion::GolpeRapido && a2 == Accion::DefensaGolpe) return 1;
    if (a1 == Accion::DefensaGolpe && a2 == Accion::GolpeFuerte) return 1;

    return 2; // gana el jugador 2
}

void mostrarEstado(shared_ptr<IPersonajes> p1, shared_ptr<IPersonajes> p2) {
    cout << "\nJugador 1: " << p1->getNombre() << " con " << (p1->getArmas().empty() ? "ninguna arma" : p1->getArmas()[0]->getNombre()) << endl;
    cout << "Jugador 2: " << p2->getNombre() << " con " << (p2->getArmas().empty() ? "ninguna arma" : p2->getArmas()[0]->getNombre()) << endl;
}

shared_ptr<IPersonajes> crearPersonajeManual() {
    cout << "Elige tu personaje:\n";
    cout << "1. Bárbaro\n2. Paladín\n3. Caballero\n4. Mercenario\n5. Gladiador\n6. Hechicero\n7. Brujo\n8. Nigromante\n9. Conjurador\n> ";
    int opcion;
    cin >> opcion;
    switch (opcion) {
        case 1: return make_shared<Barbaro>();
        case 2: return make_shared<Paladin>();
        case 3: return make_shared<Caballero>();
        case 4: return make_shared<Mercenario>();
        case 5: return make_shared<Gladiador>();
        case 6: return make_shared<Hechicero>();
        case 7: return make_shared<Brujo>();
        case 8: return make_shared<Nigromante>();
        case 9: return make_shared<Conjurador>();
        default: cout << "Opción inválida, se selecciona Bárbaro por defecto.\n"; return make_shared<Barbaro>();
    }
}

shared_ptr<IArma> elegirArmaManual(const string& tipo) {
    cout << "\nElige tu arma:\n";
    if (tipo == "Guerrero") {
        cout << "1. Espada" << endl;
        cout << "2. Hacha" << endl;
        cout << "3. Hacha Doble" << endl;
        cout << "4. Lanza"<< endl;
        cout << "5. Garrote" << endl;
        int op; cin >> op;
        switch (op) {
            case 1: return make_shared<Espada>();
            case 2: return make_shared<Hacha>();
            case 3: return make_shared<HachaD>();
            case 4: return make_shared<Lanza>();
            case 5: return make_shared<Garrote>();
            default: return make_shared<Espada>();
        }
    } else {
        cout << "1. Amuleto" << endl;
        cout << "2. Poción" << endl;
        cout << "3. Bastón" << endl;
        cout << "4. Libro Hechizos" << endl;
        cout << "5. Pocion" << endl;
        int op; cin >> op;
        switch (op) {
            case 1: return make_shared<Amuleto>();
            case 2: return make_shared<Pocion>();
            case 3: return make_shared<Baston>();
            case 4: return make_shared<LibroHechizos>();
            case 5: return make_shared<Pocion>();
            default: return make_shared<Amuleto>();
        }
    }
}
int main() {
    srand(static_cast<unsigned>(time(0)));

    cout << "--- COMIENZA LA BATALLA ---\n";

    // Jugador 1 elige personaje y arma manualmente
    auto jugador1 = crearPersonajeManual();
    string tipo1 = jugador1->getClase();
    jugador1->agregarArma(elegirArmaManual(tipo1));

    // Jugador 2 aleatorio
    auto jugador2 = PersonajeFactory::crearPersonajeConArma();
    cout << "Jugador 2 (Enemigo):\n";
    jugador2->mostrarInfo();

    int hp1 = 100;
    int hp2 = 100;

    while (hp1 > 0 && hp2 > 0) {
        mostrarEstado(jugador1, jugador2);
        cout << "\nElige una opción:" << endl;
        cout << "1. Golpe fuerte" << endl;
        cout << "2. Golpe Rápido" << endl;
        cout << "3. Defensa y ataque" << endl;
        Accion accion1 = elegirAccionJugador1();
        Accion accion2 = elegirAccionJugador2();

        cout << "\n" << jugador1->getNombre() << " usa " << (int)accion1 << " y "
             << jugador2->getNombre() << " usa " << (int)accion2 << ".\n";

        int resultado = resolverRonda(accion1, accion2);

        if (resultado == 1) {
            hp2 -= 10;
            cout << jugador1->getNombre() << " hace 10 puntos de daño a " << jugador2->getNombre() << ".\n";
        } else if (resultado == 2) {
            hp1 -= 10;
            cout << jugador2->getNombre() << " hace 10 puntos de daño a " << jugador1->getNombre() << ".\n";
        } else {
            cout << "¡Empate! Nadie recibe daño.\n";
        }

        cout << "\n--- HPs ---\n";
        cout << "Jugador 1: " << hp1 << " HP\n";
        cout << "Jugador 2: " << hp2 << " HP\n";
    }

    if (hp1 <= 0) {
        cout << "\nPerdiste la batalla...\n";
    } else {
        cout << "\n¡Ganaste la batalla!\n";
    }

    return 0;
}

