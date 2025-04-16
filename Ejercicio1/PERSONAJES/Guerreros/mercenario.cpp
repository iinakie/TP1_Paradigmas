#include "mercenario.hpp"
#include <iostream>

using namespace std;

Mercenario :: Mercenario()
    : Guerrero("Mercenario", 150, 70, 10, Armadura::Pantalones) {}

int Mercenario::hacerDanio() {
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
void Mercenario :: defender() {
    enDefensa = true;
    cout << "El mercenario se pone en guardia y se prepara para defenderse." << endl;
} 


void Mercenario :: recibirDanio(int danio) {
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

    cout << "El mercenario recibió " << danioReal << " de daño. Vida restante: " << vida << endl;
}

void Mercenario :: mostrarInfo() const {
    cout << "--- Mercenario ---" << endl;
    Guerrero::mostrarInfo(); 
}

void Mercenario :: setArma(shared_ptr<IArma> nuevaArma) {
    arma = nuevaArma;
}