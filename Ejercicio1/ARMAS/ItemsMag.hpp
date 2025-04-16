#ifndef ITEMSMAG_HPP
#define ITEMSMAG_HPP

#include "I_Armas.hpp"  
using namespace std;

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
