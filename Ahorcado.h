//
// Created by Valentina on 8/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_AHORCADO_H
#define TRABAJOPRACTICO2AHORCADO_AHORCADO_H


#include "Jugador.h"
#include "CharDinamico.h"

const int NO_EMPEZO_JUEGO = -1;
const int EMPEZO_JUEGO = 0;
const int GANO_JUEGO = 1;
const int PERDIO_JUEGO = 2;

class Ahorcado {

    private:
        int intentosFallidos, estadoJuego = NO_EMPEZO_JUEGO;
        CharDinamico palabraAAdivinar;
        Jugador jugador;
        char caracteresAdivinados[];

    public:
        // PRE:
        // POST:
        Ahorcado(int vidasOut, string nombre, string palabraAleatoria, int tamanioPalabra);

        // PRE: vidasOut > 0 y nombreJugadorOut != ""
        // POST: Crea un jugador con vidasOut cantidad de vidas, nombreJugadorOut nombre,
        //       elige una palabra random del array PALABRAS_A_ADIVNAR para adivinar
        //       y modifica estadoJuego a COMENZO


        void nuevoJuego();

        int obtenerEstadoJuego();

        // PRE: caracter debe ser una letra [a-z]
        // POST: devuelve true si caracter esta en palabraAAdivinar, de lo contrario false
        bool checkCaracter(char caracter);

        // PRE: -
        // POST: si el usuario ingresa s, devuelve true, de lo contrario false
        bool deseaJugarDeNuevo();

        // PRE: caracter debe ser una letra [a-z]
        // POST: permite que el usuario arriesgue una letra
        void arriesgar(char caracter);

        // PRE: palabra debe ser un string válido que solo contenga letras [a-z]
        // POST: permite que el usuario arriesge una palabra
        void arriesgar(string palabra);

        void actualizarAhorcado(string palabraArriesgada);
        void actualizarAhorcado(char caracter);
        void actualizarDibujoAhorcado(int fallos);
        // PRE: -
        // POST: Muestra por pantalla el mensaje correspondiente de acuerdo a si el jugador gano o perdio
        void mostrarMensajeGanoOPerdio();

        // PRE: -
        // POST: Muestra por pantalla el logo
        void mostrarLogo();

        void mostrarDespedida();


};


#endif //TRABAJOPRACTICO2AHORCADO_AHORCADO_H
