#ifndef ARMASCOMBAT_HPP
#define ARMASCOMBAT_HPP

#include "I_Armas.hpp"  
using namespace std;

/*
En este archivo defino una clase abstracta llamada ArmaCombate, que representa a las armas físicas del juego, como espadas o hachas 
(que solo usan los Guerreros). Hereda de la interfaz IArma, así que tiene que implementar las funciones básicas como usar, reparar y mostrarInfo. 
Además, esta clase agrega cosas específicas de las armas de combate: su durabilidad, su rareza (por ejemplo, si es "Primitiva" o "Ascendente") y 
un ataque especial. Es abstracta, así que no se puede crear directamente un objeto de esta clase, sino que otras clases como Espada o Hacha van 
a heredar de acá y definir bien cómo funcionan.
*/

enum class Rareza {
    Primitivo,
    Tambaleante,
    Aprendiz,
    Oficial,
    Maestro_Artesano,
    Ascendente
};


enum class AtaqueEspecial {
    GolpeRelampago,
    GolpeTerremoto,
    GolpeAcuatico,
    GolpeSonico,
    RompeEscudos,
    Clonacion
};

class ArmaCombate : public IArma {
protected:
    string nombre;
    int danio;
    int durabilidad;
    Rareza rareza;
    AtaqueEspecial ataque_especial;

public:
    ArmaCombate(std::string nombre, int danio, int durabilidad, Rareza rareza, AtaqueEspecial ataque_especial);
    
    virtual string getNombre() const override;
    virtual int getDanio() const override;
    virtual int getDurabilidad() const;
    virtual string getRareza() const;
    virtual string getAtaqueEspecial() const;

    // Los métodos usar() y reparar() quedan abstractos
    virtual void usar() override = 0;
    virtual void reparar() override = 0;
    
    virtual void mostrarInfo() const override = 0;

    virtual ~ArmaCombate() = default;
};

#endif
