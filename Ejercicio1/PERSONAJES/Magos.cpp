#include "Magos.hpp"
#include <iostream>

using namespace std;

Mago::Mago(string nombre, int vida, int mana, int estamina, Afinidad afindad)
    : nombre(nombre), vida(vida), mana(mana), estamina(estamina), afinidad(afindad) {}

string Mago :: getNombre() const { return nombre; }
int Mago :: getVida() const { return vida; }
int Mago :: getManaMago() const { return mana; }
int Mago :: getEstamina() const { return estamina;}
string Mago :: getAfinidad() const {
    switch (afinidad) {
        case Afinidad :: Fuego: return "Fuego";
        case Afinidad :: Agua: return "Agua";
        case Afinidad :: Hielo: return "Hielo";
        case Afinidad :: Oscuridad: return "Oscuridad";
        case Afinidad :: Luz: return "Luz";
        case Afinidad :: Tierra: return "Tierra";
        case Afinidad :: Aire: return "Aire";
        default: return "Desconocida";
    };
}

void Mago::agregarArma(shared_ptr<IArma> arma) {
    armas.push_back(arma);
}

vector<shared_ptr<IArma>> Mago::getArmas() const {
    return armas;
}

void Mago::mostrarInfo() const {
    cout << "Nombre: " << getNombre() << endl;
    cout << "Vida: " << getVida() << endl;
    cout << "Estamina: " << getEstamina() << endl;
    cout << "Mana: " << getManaMago() << endl;
    cout << "Afinidad: " << getAfinidad() << endl;
    if (!armas.empty()) {
        cout << "Armas: " << endl;
        for (const auto& arma : armas) {
            cout << " - " << arma->getNombre() << " (Daño: " << arma->getDanio() << ")" << endl;
        }
    } else {
        cout << "Armas: Ninguna" << endl;
    }
}

