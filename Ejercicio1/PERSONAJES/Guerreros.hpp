#ifndef GUERREROS_HPP
#define GUERREROS_HPP
#include <memory> 
#include <vector>
#include "../ARMAS/I_Armas.hpp"
#include "I_Personajes.hpp"  
using namespace std;

/*
En este archivo definí la clase abstracta Guerrero. Básicamente, representa a cualquier personaje del tipo guerrero, como un bárbaro o un caballero.
Tiene atributos típicos como nombre, vida, estamina, fuerza y qué armadura usa.
También incluí un vector para que el guerrero pueda tener varias armas. Las funciones declaradas acá sirven para obtener sus datos (getNombre, 
getVida, etc.), hacer daño, defenderse y recibir daño. Pero como es una clase abstracta, todavía no le digo cómo lo hacen, eso se completa en los 
guerreros específicos como el Barbaro.
*/

enum class Armadura {
    Casco,
    Pechera,
    Pantalones,
    Botas,
    Escudo,
    Guantes
};

class Guerrero : public IPersonajes {
protected:
    string nombre;
    int vida;
    int estamina;
    int fuerza;
    Armadura armadura;
    bool enDefensa = false;
    vector<shared_ptr<IArma>> armas;

public:
    Guerrero(std::string nombre, int vida, int estamina, int fuerza, Armadura armadura);

    virtual string getNombre() const override;
    virtual int getVida() const override;
    virtual int getEstamina() const override;
    virtual int getFuerza() const;
    virtual string getArmadura() const;

    virtual int hacerDanio() override = 0;
    virtual void recibirDanio(int danio) override = 0;
    virtual void defender() override = 0;

    virtual void mostrarInfo() const override = 0;

    void agregarArma(shared_ptr<IArma> arma) override;
    vector<shared_ptr<IArma>> getArmas() const override;

    string getClase() const override { return "Guerrero"; }

    virtual ~Guerrero() = default;
};

#endif
