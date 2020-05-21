//
// Created by Valentina on 17/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_CHARDINAMICO_H
#define TRABAJOPRACTICO2AHORCADO_CHARDINAMICO_H

#include <string>

using namespace std;

const char NULO = '_';

class CharDinamico {
    // -------------------------- ATRIBUTOS -------------------------- //
    private:
        int tamanio;
        char* palabra;

    // -------------------------- METODOS -------------------------- //
    public:

        // PRE: tamanioOut tiene que ser mayor o igual a 0
        // POST: Construye un vector dinamico de tipo char con tamanioOut cantidad de NULOS
        //       Muestra por pantalla en que lugar se reservo la memoria
        CharDinamico(int tamanioOut);

        // PRE: palabraOut tiene que ser distinto de "" y tamanioOut mayor o igual a 0
        // POST: Construye un vector dinamico de tipo char con la palabra palabraOut de
        //       tamaño tamanioOut.
        //       Muestra por pantalla en que lugar se reservo la memoria
        CharDinamico(string palabraOut, int tamanioOut);

        // PRE: -
        // POST: Copia los datos de palabraOut
        CharDinamico(const CharDinamico &palabraOut);

        // PRE: -
        // POST: Libera la memoria
        //       Muestra por pantalla de que lugar se libero la memoria
        ~CharDinamico();

        // PRE: -
        // POST: Devuelve el tamanio del vector
        int obtenerTamanio();

        // PRE: -
        // POST: Devuelve la palabra
        string obtenerPalabra();

        // PRE: pos >= 0
        // POST: Devuelve la letra en la posicion pos
        char obtenerElemento(int pos);

        // PRE: palabraOut debe ser un string valido, solo puede contener [a-zA-Z] (excluyendo la ñ)
        // POST: Le asigna palabraOut a palabra
        void asignarPalabra(string palabraOut);

        // PRE: -
        // POST: Muestra por pantalla la palabra separados por un espacio
        void mostrarCaracteres();

        // PRE: caracter debe ser una letra [a-zA-Z] (excluyendo la ñ) valida, 0 <= pos < tamanio
        // POST: Inserta caracter en palabra[pos]
        void insertarCaracter(char caracter, int pos);

        // PRE: tamanioNuevo > 0
        // POST: Redimensiona el vector
        void redimensionar(int tamanioNuevo);

        // PRE: c debe ser una letra [a-zA-Z] (excluyendo la ñ)
        // POST: Devuelve true si c esta en palabra
        bool checkCaracterEnPalabra(char c);

    private:

        // PRE: 0 <= inicio <= final <= tamanio
        // POST: Asigna NULO al vector desde inicio hasta final
        void asignarNuloAlVector(int inicio, int final);

        // PRE: 0 <= inicio <= final <= tamanio
        // POST: en palabra coloca los valores del vector palabraOut
        void copiarDatos(char* palabraOut, int inicio, int final);
};

#endif //TRABAJOPRACTICO2AHORCADO_CHARDINAMICO_H
