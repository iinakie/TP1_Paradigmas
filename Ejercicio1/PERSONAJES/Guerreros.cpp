#include "Guerreros.hpp"
#include <iostream>

using namespace std;

/*
En este archivo implemento la clase Guerrero que ya había definido en el .hpp. Acá escribí cómo se comportan sus funciones. Por ejemplo, cómo se 
obtiene el nombre, la vida, la fuerza, o cómo se muestra la información completa del guerrero.
También agregué la posibilidad de que el guerrero tenga varias armas (con vector<shared_ptr<IArma>>), y se pueden agregar con agregarArma(). La 
función mostrarInfo() imprime todo lo importante del guerrero, incluyendo su armadura y las armas que tenga.
*/

Guerrero :: Guerrero(string nombre, int vida, int estamina, int fuerza, Armadura armadura )
    : nombre(nombre), vida(vida), estamina(estamina), fuerza(fuerza), armadura(armadura) {}

string Guerrero :: getNombre() const { return nombre; }
int Guerrero :: getVida() const { return vida; }
int Guerrero :: getEstamina() const { return estamina; }
int Guerrero :: getFuerza() const { return fuerza;}
string Guerrero :: getArmadura() const {
    switch (armadura) {
        case Armadura :: Casco: return "Casco";
        case Armadura :: Pechera: return "Pechera";
        case Armadura :: Pantalones: return "Pantalones";
        case Armadura :: Botas: return "Botas";
        default: return "Desconocida";
    };
}

void Guerrero::agregarArma(shared_ptr<IArma> arma) {
    armas.push_back(arma);
}

vector<shared_ptr<IArma>> Guerrero::getArmas() const {
    return armas;
}

void Guerrero :: mostrarInfo() const {
    cout << "Nombre: " << getNombre() << endl;
    cout << "Vida: " << getVida() << endl;
    cout << "Estamina: " << getEstamina() << endl;
    cout << "Fuerza: " << getFuerza() << endl;
    cout << "Armadura: " << getArmadura() << endl;
    if (!armas.empty()) {
        cout << "Armas: " << endl;
        for (const auto& arma : armas) {
            cout << " - " << arma->getNombre() << " (Daño: " << arma->getDanio() << ")" << endl;
        }
    } else {
        cout << "Armas: Ninguna" << endl;
    }
}


