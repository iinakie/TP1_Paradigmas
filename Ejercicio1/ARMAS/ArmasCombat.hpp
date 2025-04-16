#ifndef ARMASCOMBAT_HPP
#define ARMASCOMBAT_HPP

#include "I_Armas.hpp"  
using namespace std;

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
