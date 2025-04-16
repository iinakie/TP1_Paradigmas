#ifndef GLADIADOR_HPP
#define GLADIADOR_HPP
#include <memory> 
#include "../../ARMAS/I_Armas.hpp"
#include "Guerreros.hpp"

class Gladiador : public Guerrero {
private:
    shared_ptr<IArma> arma;  
public:
    Gladiador();  // Constructor por defecto

    int hacerDanio() override;
    void recibirDanio(int danio) override;
    void defender() override;     

    void mostrarInfo() const override;

    void setArma(std::shared_ptr<IArma> nuevaArma);
};

#endif
