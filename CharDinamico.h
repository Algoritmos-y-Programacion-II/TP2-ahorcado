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
        CharDinamico();
        CharDinamico(string palabra, int tamanioOut);
        CharDinamico(const CharDinamico& palabra);
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
