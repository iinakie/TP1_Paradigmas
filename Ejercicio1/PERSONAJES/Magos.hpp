#ifndef MAGOS_HPP
#define MAGOS_HPP
#include <memory> 
#include "../ARMAS/I_Armas.hpp"
#include "I_Personajes.hpp"  
using namespace std;

/*
En este archivo defino una clase abstracta para todos los magos del juego. Lo que hice fue usar la interfaz de personajes (IPersonajes) y extenderla 
con características específicas de los magos, como el maná y la afinidad (fuego, agua, oscuridad, etc.).
También tiene funciones para manejar cosas básicas como obtener el nombre, vida, estamina, afinidad y maná. Además, los magos pueden defenderse y 
tener armas mágicas guardadas en un vector. La idea es que esta clase sirva como base para crear distintos tipos de magos (como brujo o hechicero), 
pero que cada uno tenga que completar sus propias funciones para atacar, defenderse y recibir daño.
*/

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
