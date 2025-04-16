#ifndef I_PERSONAJES_HPP
#define I_PERSONAJES_HPP
#include <memory>
#include <string>
#include <vector>
#include "../ARMAS/I_Armas.hpp"
using namespace std;

/*
En este archivo defino una interfaz para los personajes del juego. Básicamente es como un molde que dice qué funciones tienen que tener todos 
los personajes, sin importar si son magos o guerreros.
Los métodos más importantes son para obtener los datos del personaje (como nombre, vida y estamina), hacer daño, recibir daño y defenderse. 
También agregué funciones para que puedan tener armas (con agregarArma() y getArmas()), así cada personaje puede tener su propia lista de armas.
La idea es que todos los personajes que hereden de esta interfaz estén obligados a implementar estos métodos para que el juego funcione bien.
*/

class IPersonajes {
public:
    virtual string getNombre() const = 0;
    virtual int getVida() const = 0;
    virtual int getEstamina() const = 0;

    virtual int hacerDanio() = 0;
    virtual void recibirDanio(int danio) = 0;
    virtual void defender() = 0;

    virtual void mostrarInfo() const = 0;
    virtual void agregarArma(shared_ptr<IArma> arma) = 0;
    virtual vector<shared_ptr<IArma>> getArmas() const = 0;

    virtual string getClase() const = 0;

    virtual ~IPersonajes() = default;
};

#endif
