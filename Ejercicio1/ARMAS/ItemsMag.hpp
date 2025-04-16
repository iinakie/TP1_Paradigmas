#ifndef ITEMSMAG_HPP
#define ITEMSMAG_HPP

#include "I_Armas.hpp"  
using namespace std;

/*
En este archivo definí una clase abstracta llamada Items_Mag, que representa los ítems mágicos que usan los magos en el juego. Esta clase hereda 
de la interfaz IArma, así que también tiene funciones como usar() y reparar() (aunque acá no están implementadas porque van a ser distintas en 
cada ítem específico como el amuleto o el bastón).
Los atributos que tiene cada ítem son: el nombre, el daño que hace, el maná que consume, el elemento mágico que representa (como fuego, aire, 
oscuridad, etc.), y el alcance del ataque. También hay métodos para acceder a cada uno de esos atributos, que después se usan para mostrar o 
calcular cosas durante la batalla.
*/

enum class Elemento {
    Fuego,
    Acuatico,
    Aire,
    Oscuridad,
    Luz,
    Tierra
};

class Items_Mag : public IArma {
    protected:
        string nombre;
        int danio;
        int mana;
        Elemento elemento;
        float alcance;
    
    public:
        Items_Mag(string nombre, int danio, int mana, Elemento elemento, float alcance);
        
        virtual string getNombre() const override;
        virtual int getDanio() const override;
        virtual int getMana() const;
        virtual string getElemento() const;
        virtual float getAlcance() const;
    
        // Los métodos usar() y reparar() quedan abstractos
        virtual void usar() override = 0;
        virtual void reparar() override = 0;
    
        virtual ~Items_Mag() = default;
    };

#endif
