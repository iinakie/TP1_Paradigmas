#ifndef BRUJO_HPP
#define BRUJO_HPP
#include <memory> 
#include "../../ARMAS/I_Armas.hpp"
#include "Magos.hpp"

class Brujo : public Mago {
private:
    shared_ptr<IArma> arma;  

public:
    Brujo();  // Constructor por defecto

    int hacerDanio() override;
    void recibirDanio(int danio) override;
    void defender() override;     

    void mostrarInfo() const override;

    void setArma(std::shared_ptr<IArma> nuevaArma);
};

#endif
