//
// Created by Valentina on 8/5/2020.
//

#include "CharDinamico.h"

CharDinamico:: CharDinamico(string palabraOut, int tamanioOut) {
    tamanio = tamanioOut;
    palabra = new char[tamanio];
    asignarPalabra(palabraOut);
}

CharDinamico:: CharDinamico(const CharDinamico& palabraOut) {
    tamanio = palabraOut.tamanio;
    if (tamanio > 0) {
        palabra = new char[tamanio];
        copiarDatos(palabraOut.palabra, 1, tamanio);
    } else palabra = 0;
}

CharDinamico:: ~CharDinamico() {
    delete [] palabra;
}

void CharDinamico:: asignarPalabra(string palabraOut) {
    for (int i = 0; i < tamanio; i++) {
        palabra[i] = palabraOut[i];
    }
}

string CharDinamico:: obtenerPalabra() {
    string palabra;
    for (int i = 0; i < tamanio; i++) {
        palabra += this->palabra[i];
    }
    return palabra;
}

int CharDinamico:: obtenerTamanio() {
    return tamanio;
}

void CharDinamico:: mostrarPalabra() {
    for(int i = 0; i < tamanio; i++) {
        cout << palabra[i];
    }
    cout << endl;
}

void CharDinamico:: insertar(char caracter, int pos) {
    palabra[pos] = caracter;
}

void CharDinamico:: redimensionar(int tamanioNuevo) {
    if (tamanioNuevo != tamanio) {
        char* auxiliar = palabra;
        palabra = new char[tamanioNuevo];
        copiarDatos(auxiliar, 0, tamanioNuevo);
        delete []auxiliar;
        if (tamanioNuevo > tamanio)
            asignarNuloAlVector(tamanio + 1, tamanioNuevo);
        tamanio = tamanioNuevo;
    }
}

void CharDinamico:: asignarNuloAlVector(int inicio, int final) {
    for (int i = inicio; i <= final; i++)
        palabra[i] = ' ';
}

void CharDinamico:: copiarDatos(char* vec, int inicio, int final) {
    for (int i = inicio; i <= final; i++)
        palabra[i] = vec[i];
}

bool CharDinamico:: checkCaracterEnPalabra(char c) {
    bool charEstaEnString = false;
    for (int i = 0; i < tamanio; i++) {
        if (c == palabra[i])
            charEstaEnString = true;
    }
    return charEstaEnString;
}