#ifndef HECHICERO_HPP
#define HECHICERO_HPP
#include <memory> 
#include "../../ARMAS/I_Armas.hpp"
#include "Magos.hpp"

class Hechicero : public Mago {
private:
    shared_ptr<IArma> arma;  

public:
    Hechicero();  // Constructor por defecto

    int hacerDanio() override;
    void recibirDanio(int danio) override;
    void defender() override;     

    void mostrarInfo() const override;

    void setArma(std::shared_ptr<IArma> nuevaArma);
};

#endif
