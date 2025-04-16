#ifndef MAIN_BATALLA_HPP
#define MAIN_BATALLA_HPP

#include <memory>
#include <string>
#include "Ejercicio2/PersonajeFactory.hpp"

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