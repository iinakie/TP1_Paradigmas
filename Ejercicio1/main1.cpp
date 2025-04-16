#include <iostream>
#include "PERSONAJES/Guerreros/barbaro.hpp"
#include "PERSONAJES/Magos/hechicero.hpp"
#include "ARMAS/Armas_combat/espada.hpp"
#include "ARMAS/Items_mag/amuleto.hpp"

using namespace std;

/*
Este programa simula una pequeña batalla entre dos personajes: un Guerrero y un Mago. Los personajes están representados por objetos de las 
clases Barbaro y Hechicero, respectivamente, los cuales son de las clases derivadas de una "jerarquía" más general de personajes 
(Guerreros y Magos). Además, cada uno de estos personajes tiene un arma asociada, representada por los objetos Espada y Amuleto.
*/


int main() {
    // Crear un Guerrero (Barbaro) 
    shared_ptr<Guerrero> barbaro = make_shared<Barbaro>();
    shared_ptr<IArma> espada = make_shared<Espada>();

    barbaro->agregarArma(espada); //le pongo espada

    // Mostrar la información del Guerrero
    cout << "Información del Guerrero:" << endl;
    barbaro->mostrarInfo();
    cout << "Daño al atacar: " << barbaro->hacerDanio() << endl;

    // Crear un Mago (Hechicero) 
    shared_ptr<Mago> hechicero = make_shared<Hechicero>();
    shared_ptr<IArma> amuleto = make_shared<Amuleto>();

    hechicero->agregarArma(amuleto);// le pongo amuleto

    // Mostrar la información del Mago
    cout << "\nInformación del Mago:" << endl;
    hechicero->mostrarInfo();
    cout << "Daño al atacar: " << hechicero->hacerDanio() << endl;

    // Simulación de batallas simples
    cout << "\n--- Simulación de batallas ---" << endl;

    // Guerrero ataca a Mago
    int danioGuerrero = barbaro->hacerDanio();
    int danioMago = hechicero->hacerDanio();

    cout << "\nEl Guerrero hace " << danioGuerrero << " de daño al Mago." << endl;
    cout << "El Mago hace " << danioMago << " de daño al Guerrero." << endl;

    // Definir daño recibido
    hechicero->recibirDanio(danioGuerrero);
    barbaro->recibirDanio(danioMago);

    cout << "\n--- Fin de la Simulación ---" << endl;

    return 0;
}
