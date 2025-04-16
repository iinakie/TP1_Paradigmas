#ifndef NIGROMANTE_HPP
#define NIGROMANTE_HPP
#include <memory> 
#include "../../ARMAS/I_Armas.hpp"
#include "Magos.hpp"

class Nigromante : public Mago {
private:
    shared_ptr<IArma> arma;  

public:
    Nigromante();  // Constructor por defecto

    int hacerDanio() override;
    void recibirDanio(int danio) override;
    void defender() override;     

    void mostrarInfo() const override;

    void setArma(std::shared_ptr<IArma> nuevaArma);
};

#endif
