#include "ArmasCombat.hpp"
#include <iostream>

using namespace std;
/* 
En este archivo implemento los métodos de la clase abstracta ArmaCombate. Acá se define cómo funciona el constructor, que recibe todos los datos 
importantes del arma (nombre, daño, durabilidad, rareza y ataque especial). También están las funciones para acceder a esa información 
(getNombre, getDanio, etc.), y otras que transforman los enums (como Rareza o AtaqueEspecial) en strings para que sea más fácil mostrarlos 
por pantalla. La función mostrarInfo() imprime todos los datos del arma de forma ordenada.
*/

ArmaCombate::ArmaCombate(string nombre, int danio, int durabilidad, Rareza rareza, AtaqueEspecial ataque_especial )
    : nombre(nombre), danio(danio), durabilidad(durabilidad), rareza(rareza), ataque_especial(ataque_especial) {}

string ArmaCombate :: getNombre() const { return nombre; }
int ArmaCombate :: getDanio() const { return danio; }
int ArmaCombate :: getDurabilidad() const { return durabilidad; }
string ArmaCombate :: getAtaqueEspecial() const {
    switch (ataque_especial) {
        case AtaqueEspecial :: GolpeRelampago: return "Golpe Relampago";
        case AtaqueEspecial :: GolpeTerremoto: return "Golpe Terremoto";
        case AtaqueEspecial :: GolpeAcuatico: return "Golpe Acuatico";
        case AtaqueEspecial :: GolpeSonico: return "Golpe Sonico";
        case AtaqueEspecial :: RompeEscudos: return "RompeEscudos";
        case AtaqueEspecial :: Clonacion: return "Clonacion";
        default: return "Desconocido";
    };
}
string ArmaCombate::getRareza() const {
    switch (rareza) {
        case Rareza :: Primitivo: return "Primitivo";
        case Rareza :: Tambaleante: return "Tambaleante";
        case Rareza :: Aprendiz: return "Aprendiz";
        case Rareza :: Oficial: return "Oficial";
        case Rareza :: Maestro_Artesano: return "Maestro Artesano";
        case Rareza :: Ascendente: return "Ascendente";
        default: return "Desconocida";
    };
}

void ArmaCombate :: mostrarInfo() const {
    cout << "Información del arma:" << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Daño: " << getDanio() << endl;
    cout << "Durabilidad: " << getDurabilidad() << endl;
    cout << "Rareza: " << getRareza() << endl;
    cout << "Ataque especial: " << getAtaqueEspecial() << endl;
}
