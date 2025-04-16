#include "nigromante.hpp"
#include <iostream>

using namespace std;

Nigromante::Nigromante()
    : Mago("Nigromante", 120, 60, 40, Afinidad::Fuego) {}  

int Nigromante::hacerDanio() {
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

void Nigromante::defender() {
    enDefensa = true;
    cout << "El Nigromante invoca un escudo mágico para protegerse." << endl;
}

void Nigromante::recibirDanio(int danio) {
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

    cout << "El Nigromante recibió " << danioReal << " de daño. Vida restante: " << vida << endl;
}

void Nigromante::mostrarInfo() const {
    cout << "--- Nigromante ---" << endl;
    Mago::mostrarInfo();
}

void Nigromante::setArma(shared_ptr<IArma> nuevaArma) {
    arma = nuevaArma;
}