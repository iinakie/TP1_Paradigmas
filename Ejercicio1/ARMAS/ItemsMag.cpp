#include "ItemsMag.hpp"
using namespace std;


Items_Mag::Items_Mag(std::string nombre, int danio, int mana, Elemento elemento, float metros )
    : nombre(nombre), danio(danio), mana(mana), elemento(elemento), alcance(metros) {}

string Items_Mag :: getNombre() const { return nombre; }
int Items_Mag :: getDanio() const { return danio; }
int Items_Mag :: getMana() const { return mana; }

string Items_Mag::getElemento() const {
    switch (elemento) {
        case Elemento :: Fuego: return "Fuego";
        case Elemento :: Acuatico: return "Acuatico";
        case Elemento :: Aire: return "Aire";
        case Elemento :: Oscuridad: return "Oscuridad";
        case Elemento :: Luz: return "Luz";
        case Elemento :: Tierra: return "Tierra";
        default: return "Desconocida";
    };
}
float Items_Mag :: getAlcance() const { return alcance;}
