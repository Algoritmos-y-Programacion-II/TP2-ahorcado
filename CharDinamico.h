//
// Created by Valentina on 8/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_CHARDINAMICO_H
#define TRABAJOPRACTICO2AHORCADO_CHARDINAMICO_H

#include <iostream>

using namespace std;

class CharDinamico {
    // -------------------------- ATRIBUTOS -------------------------- //
    private:
        int tamanio;
        char* palabra;

    // -------------------------- METODOS -------------------------- //
    public:

        // PRE: palabraOut tiene que ser distinto de "" y tamanioOut mayor que 1
        // POST: Crea un vector de tipo char con la palabra palabraOut de tamaño tamanioOut
        //       Muestra por pantalla en que lugar se reservo la memoria
        CharDinamico(string palabraOut, int tamanioOut);

        CharDinamico(const CharDinamico& palabra);

        // PRE: -
        // POST: Libera la memoria
        ~CharDinamico();

        int obtenerTamanio();

        string obtenerPalabra();

        char obtenerElemento(int pos);

        void mostrarPalabra();

        void asignarPalabra(string palabraOut);

        void insertar(char caracter, int pos);

        void redimensionar(int tamanioNuevo);

        bool checkCaracterEnPalabra(char c);

    private:
        void asignarNuloAlVector(int inicio, int final);
        void copiarDatos(char* palabraOut, int inicio, int final);
};


#endif //TRABAJOPRACTICO2AHORCADO_CHARDINAMICO_H
