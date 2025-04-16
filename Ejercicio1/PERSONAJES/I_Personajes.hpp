#ifndef I_PERSONAJES_HPP
#define I_PERSONAJES_HPP
#include <memory>
#include <string>
#include <vector>
#include "../ARMAS/I_Armas.hpp"
using namespace std;

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
