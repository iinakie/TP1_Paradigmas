#ifndef AMULETO_HPP
#define AMULETO_HPP

#include "../ARMAS/ItemsMag.hpp"
#include <iostream>
#include <string>


class Amuleto : public Items_Mag {
public:
    Amuleto();  

    void usar() override;
    void reparar() override;

    void mostrarInfo() const;  
};

#endif
