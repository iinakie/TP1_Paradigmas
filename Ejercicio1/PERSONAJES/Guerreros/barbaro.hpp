#ifndef BARBARO_HPP
#define BARBARO_HPP
#include <memory> 
#include "../../ARMAS/I_Armas.hpp"
#include "Guerreros.hpp"

class Barbaro : public Guerrero {
private:
    shared_ptr<IArma> arma;  

public:
    Barbaro();  // Constructor por defecto

    int hacerDanio() override;
    void recibirDanio(int danio) override;
    void defender() override;     

    void mostrarInfo() const override;

    void setArma(std::shared_ptr<IArma> nuevaArma);
};

#endif
