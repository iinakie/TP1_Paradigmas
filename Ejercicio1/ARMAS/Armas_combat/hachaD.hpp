#ifndef HACHAD_HPP
#define HACHAD_HPP

#include "../ARMAS/ArmasCombat.hpp"
#include <iostream>
#include <string>


class HachaD : public ArmaCombate {
public:
    HachaD();  

    void usar() override;
    void reparar() override;

    void mostrarInfo() const;  
};

#endif
