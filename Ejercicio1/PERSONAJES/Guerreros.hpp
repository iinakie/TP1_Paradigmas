#ifndef GUERREROS_HPP
#define GUERREROS_HPP
#include <memory> 
#include <vector>
#include "../ARMAS/I_Armas.hpp"
#include "I_Personajes.hpp"  
using namespace std;

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
