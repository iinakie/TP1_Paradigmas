#include "gladiador.hpp"
#include <iostream>

using namespace std;

Gladiador :: Gladiador()
    : Guerrero("Gladiador", 100, 50, 50, Armadura::Pantalones) {}

int Gladiador::hacerDanio() {
    // Por cada ataque gasta 10 de estamina
    if (estamina > 10) {
        estamina -= 10;
    } else {
        estamina = 0;
    }
        
    int danioTotal = fuerza;

    if (arma) {
        danioTotal += arma->getDanio();  // ← agrega daño del arma si tiene
    }

    return danioTotal;
}

void Gladiador :: defender() {
    enDefensa = true;
    cout << "El gladiador se pone en guardia y se prepara para defenderse." << endl;
} 


void Gladiador :: recibirDanio(int danio) {
    int defensa = 0;
    if (armadura == Armadura::Pechera || armadura == Armadura::Pantalones) {
        defensa = 10;
    } else if (armadura == Armadura::Botas || armadura == Armadura::Casco) {
        defensa = 5;
    }

    if (enDefensa) {
        defensa += 10;             // se mejora la defensa
        estamina += 15;            // recupera estamina
        if (estamina > 100) estamina = 100; 
        enDefensa = false;         // se resetea luego del turno defensivo
    }

    int danioReal = max(0, danio - defensa); //el daño real será el daño que supere la defensa, pero nunca menos de 0.
    vida -= danioReal;

    cout << "El gladiador recibió " << danioReal << " de daño. Vida restante: " << vida << endl;
}

void Gladiador :: mostrarInfo() const {
    cout << "--- Gladiador ---" << endl;
    Guerrero::mostrarInfo(); 
}

void Gladiador :: setArma(shared_ptr<IArma> nuevaArma) {
    arma = nuevaArma;
}