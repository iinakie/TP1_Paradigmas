#ifndef LANZA_HPP
#define LANZA_HPP

#include "../ARMAS/ArmasCombat.hpp"
#include <iostream>
#include <string>


class Lanza : public ArmaCombate {
public:
    Lanza();  

    void usar() override;
    void reparar() override;

    void mostrarInfo() const;  
};

#endif
