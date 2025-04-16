#ifndef GARROTE_HPP
#define GARROTE_HPP

#include "../ARMAS/ArmasCombat.hpp"
#include <iostream>
#include <string>


class Garrote : public ArmaCombate {
public:
    Garrote();  

    void usar() override;
    void reparar() override;

    void mostrarInfo() const;  
};

#endif