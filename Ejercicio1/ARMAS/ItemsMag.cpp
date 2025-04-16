#include "ItemsMag.hpp"
using namespace std;

/*
En este archivo implementé los métodos de la clase Items_Mag. Básicamente se trata de cómo se construye un ítem mágico con sus atributos: nombre, 
daño, maná, elemento mágico y alcance. Después, cada método devuelve esa información cuando se la necesite, por ejemplo para mostrar el nombre o 
saber cuánto maná gasta.
El método getElemento() usa un switch para transformar el tipo de elemento (que es un enum) a texto legible como "Fuego" o "Tierra". Y getAlcance()
simplemente devuelve cuántos metros puede llegar el ataque del ítem.
*/

Items_Mag::Items_Mag(string nombre, int danio, int mana, Elemento elemento, float metros )
    : nombre(nombre), danio(danio), mana(mana), elemento(elemento), alcance(metros) {}

string Items_Mag :: getNombre() const { return nombre; }
int Items_Mag :: getDanio() const { return danio; }
int Items_Mag :: getMana() const { return mana; }
float Items_Mag :: getAlcance() const { return alcance;}

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
