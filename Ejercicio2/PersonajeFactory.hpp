
#ifndef PERSONAJEFACTORY_HPP
#define PERSONAJEFACTORY_HPP

#include <memory>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "../Ejercicio1/PERSONAJES/I_Personajes.hpp"
#include "../Ejercicio1/ARMAS/I_Armas.hpp"

// Personajes Guerreros y Magos
#include "../Ejercicio1/PERSONAJES/Guerreros/barbaro.hpp"
#include "../Ejercicio1/PERSONAJES/Guerreros/paladin.hpp"
#include "../Ejercicio1/PERSONAJES/Guerreros/caballero.hpp"
#include "../Ejercicio1/PERSONAJES/Guerreros/mercenario.hpp"
#include "../Ejercicio1/PERSONAJES/Guerreros/gladiador.hpp"

#include "../Ejercicio1/PERSONAJES/Magos/hechicero.hpp"
#include "../Ejercicio1/PERSONAJES/Magos/brujo.hpp"
#include "../Ejercicio1/PERSONAJES/Magos/nigromante.hpp"
#include "../Ejercicio1/PERSONAJES/Magos/conjurador.hpp"

// Armas para Guerreros
#include "../Ejercicio1/ARMAS/Armas_combat/espada.hpp"
#include "../Ejercicio1/ARMAS/Armas_combat/hacha.hpp"
#include "../Ejercicio1/ARMAS/Armas_combat/hachaD.hpp"
#include "../Ejercicio1/ARMAS/Armas_combat/lanza.hpp"
#include "../Ejercicio1/ARMAS/Armas_combat/garrote.hpp"

// Ítems mágicos para Magos
#include "../Ejercicio1/ARMAS/Items_mag/amuleto.hpp"
#include "../Ejercicio1/ARMAS/Items_mag/pocion.hpp"
#include "../Ejercicio1/ARMAS/Items_mag/baston.hpp"
#include "../Ejercicio1/ARMAS/Items_mag/libro_hechizos.hpp"
#include "../Ejercicio1/ARMAS/Items_mag/pocion.hpp"

/*
En este archivo declaro la clase PersonajeFactory, que se encarga de crear personajes (tanto magos como guerreros) y asignarles armas en función de 
ciertas condiciones aleatorias. En lugar de crear cada objeto de forma manual, la clase maneja la creación de los personajes y sus respectivas 
armas a través de métodos estáticos.
- inicializarRandom(): Inicia la semilla para generar números aleatorios.
- crearPersonajeAleatorio(): Devuelve un personaje aleatorio, ya sea un mago o un guerrero, utilizando rand() para elegir entre varias opciones.
- crearArmaCompatible(): Según el tipo de personaje (mago o guerrero), asigna un arma compatible. Los guerreros pueden tener armas de combate (como
 espadas o hachas), mientras que los magos pueden tener ítems mágicos (como amuletos o pociones).
- crearPersonajeConArma(): Crea un personaje y le asigna un arma, usando los métodos anteriores.
La clase permite manejar la creación de personajes y armas de forma más organizada y flexible, usando shared_ptr para manejar la memoria de los 
objetos creados.
*/


class PersonajeFactory {
public:
    static void inicializarRandom();
    static shared_ptr<IPersonajes> crearPersonajeAleatorio();
    static shared_ptr<IArma> crearArmaCompatible(const string& tipoPersonaje);
    static shared_ptr<IPersonajes> crearPersonajeConArma();
};

#endif