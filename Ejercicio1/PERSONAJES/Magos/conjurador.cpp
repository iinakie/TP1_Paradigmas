#include "conjurador.hpp"
#include <iostream>

using namespace std;

Conjurador::Conjurador()
    : Mago("Conjurador", 120, 50, 30, Afinidad::Fuego) {}  

int Conjurador::hacerDanio() {
    if (mana >= 15) {
        mana -= 15;
    } else {
        cout << "No hay suficiente maná. El daño es reducido." << endl;
        mana = 0;
        return 5; // daño mínimo
    }

    int danio = 10; // daño base mágico
    if (arma) {
        danio += arma->getDanio();
    }
    return danio;
}

void Conjurador::defender() {
    enDefensa = true;
    cout << "El Conjurador invoca un escudo mágico para protegerse." << endl;
}

void Conjurador::recibirDanio(int danio) {
    int resistencia = 0;

    switch (afinidad) {
        case Afinidad::Fuego:
            resistencia = 5;
            break;
        case Afinidad::Agua:
        case Afinidad::Hielo:
            resistencia = 8;
            break;
        case Afinidad::Oscuridad:
        case Afinidad::Luz:
            resistencia = 10;
            break;
        case Afinidad::Tierra:
        case Afinidad::Aire:
            resistencia = 6;
            break;
    }

    if (enDefensa) {
        resistencia += 10;
        mana += 10;
        if (mana > 100) mana = 100;
        enDefensa = false;
        cout << "Defensa mágica activa. Maná recuperado y daño reducido." << endl;
    }

    int danioReal = max(0, danio - resistencia);
    vida -= danioReal;

    cout << "El Conjurador recibió " << danioReal << " de daño. Vida restante: " << vida << endl;
}

void Conjurador::mostrarInfo() const {
    cout << "--- Conjurador ---" << endl;
    Mago::mostrarInfo();
}

void Conjurador::setArma(shared_ptr<IArma> nuevaArma) {
    arma = nuevaArma;
}