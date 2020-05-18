//
// Created by Valentina on 8/5/2020.
//

#include "CharDinamico.h"
// ------------------------------ METODOS PUBLICOS ----------------------------------//
// Constructor con 1 parametro
CharDinamico:: CharDinamico(int tamanioOut) {
    tamanio = tamanioOut;
    palabra = new char[tamanio];
    for (int i = 0; i < tamanio ; i++) {
        insertarCaracter(NULO, i);
    }
    cout << "\n--AVISO-- El vector dinamico se almacena en: " << static_cast<void *>(palabra);
}

// Constructor con 2 parametros
CharDinamico:: CharDinamico(string palabraOut, int tamanioOut) {
    tamanio = tamanioOut;
    palabra = new char[tamanio];
    asignarPalabra(palabraOut);
    cout << "\n--AVISO-- El vector dinamico se almacena en: " << static_cast<void *>(palabra);
}

// Constructor de copia
CharDinamico:: CharDinamico(const CharDinamico& palabraOut) {
    tamanio = palabraOut.tamanio;
    if (tamanio > 0) {
        palabra = new char[tamanio];
        copiarDatos(palabraOut.palabra, 1, tamanio);
    } else palabra = 0;
}

// Destructor
CharDinamico:: ~CharDinamico() {
    if (tamanio > 0)
        delete [] palabra;
    cout << "\n--AVISO-- Se libero la memoria almacenada en: " << static_cast<void *>(palabra);
}

string CharDinamico:: obtenerPalabra() {
    string palabraStr;
    for (int i = 0; i < tamanio; i++) {
        palabraStr += toupper(palabra[i]);
    }
    return palabraStr;
}

char CharDinamico:: obtenerElemento(int pos) {
    return palabra[pos];
}

int CharDinamico:: obtenerTamanio() {
    return tamanio;
}

void CharDinamico:: asignarPalabra(string palabraOut) {
    redimensionar(palabraOut.size());
    for (int i = 0; i < tamanio; i++) {
        palabra[i] = palabraOut[i];
    }
}

void CharDinamico:: insertarCaracter(char caracter, int pos) {
    palabra[pos] = caracter;
}

void CharDinamico:: mostrarCaracteres() {
    for(int i = 0; i < tamanio; i++) {
        cout << palabra[i] << " ";
    }
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

bool CharDinamico:: checkCaracterEnPalabra(char c) {
    bool charEstaEnString = false;
    for (int i = 0; i < tamanio; i++) {
        if (c == palabra[i])
            charEstaEnString = true;
    }
    return charEstaEnString;
}

// ------------------------------ METODOS PRIVADOS ----------------------------------//
void CharDinamico:: asignarNuloAlVector(int inicio, int final) {
    if (tamanio > 0)
        for (int i = inicio; i < final; i++)
            palabra[i] = ' ';
}

void CharDinamico:: copiarDatos(char* vec, int inicio, int final) {
    if (tamanio > 0)
        for (int i = inicio; i < final; i++)
            palabra[i] = vec[i];
}