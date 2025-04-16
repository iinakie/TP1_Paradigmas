#ifndef I_ARMAS_HPP
#define I_ARMAS_HPP

#include <string>
using namespace std;

/*
Este archivo define una interfaz llamada IArma. Básicamente,  dice qué funciones mínimas debe tener cualquier tipo de arma en el juego. 
Todas las armas (ya sean mágicas o de combate) van a heredar de esta clase y van a tener que implementar sí o sí las funciones que están acá: 
obtener el nombre del arma, su daño, poder usarla, repararla y mostrar su información. Esta es una forma de asegurarse de que todas las armas 
tengan el mismo comportamiento, a la hora de usar estas funciones.
*/

class IArma {
public:
    //Las Armas y los Items los tienen
    virtual string getNombre() const = 0;
    virtual int getDanio() const = 0;

    //Las Armas y los Items las usan
    virtual void usar() = 0;
    virtual void reparar() = 0;

    virtual void mostrarInfo() const  = 0;

    virtual ~IArma() = default;
};

#endif
