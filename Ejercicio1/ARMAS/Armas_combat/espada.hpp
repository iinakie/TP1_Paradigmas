#ifndef ESPADA_HPP
#define ESPADA_HPP

#include "../ARMAS/ArmasCombat.hpp"
#include <iostream>
#include <string>


class Espada : public ArmaCombate {
public:
    Espada();  

    void usar() override;
    void reparar() override;

    void mostrarInfo() const;  
};

#endif
