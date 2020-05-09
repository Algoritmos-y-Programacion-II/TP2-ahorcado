//
// Created by Valentina on 8/5/2020.
//

#include "Jugador.h"

Jugador:: Jugador(int vidasOut, string nombreOut) {
    vidas = vidasOut;
    nombre = nombreOut;
}

int Jugador:: obtenerVidas() {
    return vidas;
}

string Jugador:: obtenerNombre() {
    return nombre;
}

void Jugador:: asignarVidas(int vidasOut) {
    vidas = vidasOut;
}

void Jugador:: asignarNombre(string nombreOut) {
    nombre = nombreOut;
}

void Jugador:: quitarVidas(int vidasASacar) {
    vidas -= vidasASacar;
}