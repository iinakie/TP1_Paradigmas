#ifndef MAGOS_HPP
#define MAGOS_HPP
#include <memory> 
#include "../ARMAS/I_Armas.hpp"
#include "I_Personajes.hpp"  
using namespace std;

enum class Afinidad {
    Fuego,
    Agua,
    Hielo,
    Oscuridad,
    Luz,
    Tierra,
    Aire, 
};



class Mago : public IPersonajes {
protected:
    string nombre;
    int vida;
    int mana;
    int estamina;
    Afinidad afinidad;
    bool enDefensa = false;  
    vector<shared_ptr<IArma>> armas;

public:
    Mago(std::string nombre, int vida, int mana, int estamina, Afinidad afinidad);
    
    virtual string getNombre() const override;
    virtual int getVida() const override;
    virtual int getEstamina() const override;
    virtual int getManaMago() const;
    virtual string getAfinidad() const;

    virtual int hacerDanio() override = 0;
    virtual void recibirDanio(int danio) override = 0;
    virtual void defender() override = 0;

    virtual void mostrarInfo() const override = 0;

    void agregarArma(shared_ptr<IArma> arma) override;
    vector<shared_ptr<IArma>> getArmas() const override;

    string getClase() const override { return "Mago"; }

    virtual ~Mago() = default;
};

#endif
