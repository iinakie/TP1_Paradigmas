#ifndef I_ARMAS_HPP
#define I_ARMAS_HPP

#include <string>
using namespace std;

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
