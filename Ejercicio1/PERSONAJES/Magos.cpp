#include "Magos.hpp"
#include <iostream>

using namespace std;

/*
En este archivo implemento las funciones de la clase abstracta Mago. Acá es donde puse cómo se construye un mago y cómo se accede a sus atributos 
como el nombre, vida, estamina, maná y afinidad elemental (como fuego, aire, etc.).
También armé funciones para que los magos puedan mostrar su información completa por consola y para que puedan tener varias armas mágicas. 
Por ejemplo, con agregarArma puedo darle un arma a un mago, y después mostrarInfo muestra todos sus datos y sus armas actuales.
*/

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

