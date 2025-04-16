#ifndef BASTON_HPP
#define BASTON_HPP

#include "../ARMAS/ItemsMag.hpp"
#include <iostream>
#include <string>


class Baston : public Items_Mag {
public:
Baston();  

    void usar() override;
    void reparar() override;

    void mostrarInfo() const;  
};

#endif
