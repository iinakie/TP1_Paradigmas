#ifndef POCION_HPP
#define POCION_HPP

#include "../ARMAS/ItemsMag.hpp"
#include <iostream>
#include <string>


class Pocion : public Items_Mag {
public:
    Pocion();  

    void usar() override;
    void reparar() override;

    void mostrarInfo() const;  
};

#endif
