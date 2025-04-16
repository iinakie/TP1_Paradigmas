#ifndef HACHA_HPP
#define HACHA_HPP

#include "../ARMAS/ArmasCombat.hpp"
#include <iostream>
#include <string>


class Hacha : public ArmaCombate {
public:
    Hacha();  

    void usar() override;
    void reparar() override;

    void mostrarInfo() const;  
};

#endif
