//
// Created by Valentina on 17/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_AHORCADO_H
#define TRABAJOPRACTICO2AHORCADO_AHORCADO_H


#include "Jugador.h"
#include "CharDinamico.h"

const int EMPEZO_JUEGO = 0;
const int GANO_JUEGO = 1;
const int PERDIO_JUEGO = 2;
const int CANT_VIDAS = 7;

const int VERDURAS = 1;
const int FRUTAS = 2;
const int PAISES = 3;
const int NOMBRES_FEMENINOS = 4;
const int NOMBRES_MASCULINOS = 5;
const int COLORES = 6;

const int CANT_PALABRAS = 10;

const string PALABRAS_VERDURAS[CANT_PALABRAS] = {"PAPA", "ACELGA", "TOMATE", "ZANAHORIA", "REMOLACHA", "BATATA", "ESPINACA", "ZUCCINI", "BERENJENA", "CEBOLLA"};
const string PALABRAS_FRUTAS[CANT_PALABRAS] = {"BANANA", "MANZANA", "MANDARINA", "NARANJA", "HIGO", "DATIL", "MELON", "SANDIA", "ANANA", "CIRUELA"};
const string PALABRAS_PAISES[CANT_PALABRAS] = {"ARGENTINA", "PARAGUAY", "URUGUAY", "CHILE", "BOLIVIA", "PERU", "ECUADOR", "VENEZUELA", "MEXICO", "GUATEMALA"};
const string PALABRAS_NOMBRES_M[CANT_PALABRAS] = {"TOMAS", "PEDRO", "JUAN", "hernan", "ALEJANDRO", "TOBIAS", "MATEO", "THEO", "JORGE", "ANDRES"};
const string PALABRAS_NOMBRES_F[CANT_PALABRAS] = {"VALERIA", "AGUSTINA", "ALEXA", "MARTINA", "MAGALI", "VERONICA", "FLORENCIA", "JOSELINA", "ANDREA", "INES"};
const string PALABRAS_COLORES[CANT_PALABRAS] = {"AMARILLO", "AZUL", "NARANJA", "ROJO", "VERDE", "VIOLETA", "NEGRO", "BLANCO", "GRIS", "CELESTE"};

class Ahorcado {
    // -------------------------- ATRIBUTOS -------------------------- //
    private:
        int estadoJuego, categoria;
        string letrasErroneas;
        CharDinamico palabraAAdivinar, palabraSecreta;
        Jugador jugador;

    // -------------------------- METODOS -------------------------- //
    public:

        // PRE: -
        // POST: Construye un ahorcado con estadoJuego en EMPEZO_JUEGO
        Ahorcado();

        // PRE: jugadorOut tiene que ser un objeto valido
        // POST: Construye un ahorcado con el jugadorOut, asignandole CANT_VIDAS al jugador, e inicializando
        //       estadoJuego en EMPEZO_JUEGO
        Ahorcado(Jugador jugadorOut);

        // PRE: -
        // POST: Es la estructura del juego, utilizar este metodo si no se desea implementar la logica en el main
        void main();

        // PRE: jugadorOut tiene que ser un objeto valido
        // POST: Le asigna el nombre de jugadorOut al atributo jugador
        void asignarNombreJugador(Jugador jugadorOut);

        // PRE: tamanioOut tiene que ser mayor o igual a cero
        // POST: Le asigna a palabraSecreta tamanioOut cantidad de guiones bajos (´_´)
        void asignarPalabraSecreta(int tamanioOut);

        // PRE: palabra debe contener solo letras (mayusculas o minusculas) de la A-Z exceptuando la Ñ
        // POST: Le asigna a palabraAAdivinar el string palabra
        void asignarPalabraAAdivinar(string palabra);

        // PRE: opcion debe ser un entero valido
        // POST: Le asigna al atributo categoria la opcion recibida por parametro
        void asignarCategoria(int opcion);

        // PRE: -
        // POST: Devuelve un entero que representa el estado del juego
        int obtenerEstadoJuego();

        // PRE: -
        // POST: Devuelve la categoria
        int obtenerCategoria();

        // PRE: -
        // POST: Devuelve el jugador
        Jugador obtenerJugador();

        // PRE: -
        // POST: Devuelve las letras erroneas
        string obtenerLetrasErroneas();

        void elegirCategoria();

        void elegirPalabraAleatoriaSegunCategoria();

        void resetearJuego();

        // PRE: -
        // POST: Si el usuario ingresa s, devuelve true, de lo contrario false
        bool deseaJugarDeNuevo();

        // PRE: -
        // POST: Muestra por pantalla el logo
        void mostrarLogo();

        // PRE: -
        // POST: Muestra por pantalla las instrucciones
        void mostrarInstrucciones();

        // PRE: -
        // POST: Muestra por pantalla las categorias disponibles
        void mostrarCategorias();

        // PRE: El estadoJuego debe ser igual a GANO_JUEGO o PERDIO_JUEGO
        // POST: Muestra por pantalla el mensaje correspondiente de acuerdo a si el jugador gano o perdio
        void mostrarMensajeGanoOPerdio();

        // PRE: -
        // POST: Muestra por pantalla un mensaje de despedida
        void mostrarDespedida();

        // PRE: caracter debe ser una letra [a-z]
        // POST: -
        void arriesgar(char caracter);

        // PRE: palabra debe ser un string válido que solo contenga letras [a-z]
        // POST: -
        void arriesgar(string palabra);

        // PRE: -
        // POST: muestra por pantalla el dibujo del ahorcado y la palabra secreta actualizados
        void actualizarAhorcado();

        // PRE: 0 <= fallos <= 7
        // POST: muestra el dibujo
        void mostrarDibujoAhorcado();

        // PRE: -
        // POST: Comienza un nuevo juego
        void nuevoJuego();
};

#endif //TRABAJOPRACTICO2AHORCADO_AHORCADO_H
