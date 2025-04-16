#ifndef MAIN_BATALLA_HPP
#define MAIN_BATALLA_HPP

#include <memory>
#include <string>
#include "Ejercicio2/PersonajeFactory.hpp"

/*
Este archivo define la interfaz de las funciones y enumeraciones relacionadas con el manejo de la batalla entre dos personajes. Estas funciones 
hacen que se pueda simular la interacción entre los personajes (jugadores), eligiendo sus acciones durante el combate.

1) Enumeración Accion: Define las tres posibles acciones que los jugadores pueden realizar en una batalla:
    - GolpeFuerte: El jugador realiza un ataque fuerte.
    - GolpeRapido: El jugador realiza un ataque rápido.
    - DefensaGolpe: El jugador se defiende y, a la vez, contraataca.
Estas acciones se utilizan para determinar cómo interactúan los personajes en cada ronda de la pelea.

2) Funciones principales:
    - elegirAccionJugador1(): Esta función hace que el jugador 1 pueda seleccionar una acción entre las tres posibles. La elección se realiza a 
    través de la entrada del usuario.
    - elegirAccionJugador2(): Similar a la función anterior, pero para el jugador 2. Esta acción es seleccionada aleatoriamente para el jugador 2 
    utilizando el generador de números aleatorios.
    - resolverRonda(Accion a1, Accion a2): Dada la elección de acciones de ambos jugadores, esta función resuelve la ronda. Compara las acciones de 
    ambos jugadores y calcula el daño o los efectos de la batalla de acuerdo con las reglas del "piedra, papel, tijera".
    - mostrarEstado(shared_ptr<IPersonajes> p1, shared_ptr<IPersonajes> p2): Esta función muestra el estado actual de ambos personajes, incluyendo 
    su vida y otros detalles importantes para el jugador.

En este archivo facilito la organización y el control de las interacciones de combate entre los personajes, permitiendo una simulación dinámica del 
juego.
*/

enum class Accion {
    GolpeFuerte = 1,
    GolpeRapido,
    DefensaGolpe
};

Accion elegirAccionJugador1();
Accion elegirAccionJugador2();
int resolverRonda(Accion a1, Accion a2);
void mostrarEstado(shared_ptr<IPersonajes> p1, shared_ptr<IPersonajes> p2);

#endif