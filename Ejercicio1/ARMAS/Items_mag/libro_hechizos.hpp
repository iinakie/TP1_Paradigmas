#ifndef LIBRO_HECHIZOS_HPP
#define LIBRO_HECHIZOS_HPP

#include "../ARMAS/ItemsMag.hpp"
#include <iostream>
#include <string>


class LibroHechizos : public Items_Mag {
public:
    LibroHechizos();  

    void usar() override;
    void reparar() override;

    void mostrarInfo() const;  
};

#endif
