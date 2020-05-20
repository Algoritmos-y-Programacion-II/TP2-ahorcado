//
// Created by Valentina on 17/5/2020.
//

#include "CharDinamico.h"
#include <iostream>

// ------------------------------ METODOS PUBLICOS ----------------------------------//

// <--------------------- constructores y destructor
CharDinamico:: CharDinamico(int tamanioOut) {
    tamanio = tamanioOut;
    palabra = new char[tamanio];
    for (int i = 0; i < tamanio ; i++) {
        insertarCaracter(NULO, i);
    }
    cout << "\n--CONSTRUCTOR 1 AVISO-- El vector dinamico se almacena en: " << static_cast<void *>(palabra);
}

CharDinamico:: CharDinamico(string palabraOut, int tamanioOut) {
    tamanio = tamanioOut;
    palabra = new char[tamanio];
    asignarPalabra(palabraOut);
    cout << "\n--CONSTRUCTOR 2 AVISO-- El vector dinamico se almacena en: " << static_cast<void *>(palabra);
}

CharDinamico:: CharDinamico(const CharDinamico &palabraOut) {
    tamanio = palabraOut.tamanio;
    if (tamanio > 0) {
        palabra = new char[tamanio];
        copiarDatos(palabraOut.palabra, 1, tamanio);
    } else palabra = 0;
    cout << "\n--CONSTRUCTOR DE COPIA AVISO-- El vector dinamico se almacena en: " << static_cast<void *>(palabra);
}

CharDinamico:: ~CharDinamico() {
    if (tamanio > 0)
        delete [] palabra;
    cout << "\n--DESTRUCTOR AVISO-- Se libero la memoria almacenada en: " << static_cast<void *>(palabra);
}
// -------------------------------->


// <--------------------- getters
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
// -------------------------------->


// <--------------------- setters
void CharDinamico:: asignarPalabra(string palabraOut) {
    redimensionar(palabraOut.size());
    for (int i = 0; i < tamanio; i++) {
        palabra[i] = palabraOut[i];
    }
}
// -------------------------------->


// <--------------------- otros metodos
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
        cout << "\n--REDIMENSIONAR AVISO-- El puntero auxiliar apunta al vector dinamico que se almacena en: " << static_cast<void *>(palabra);
        palabra = new char[tamanioNuevo];
        cout << "\n--REDIMENSIONAR AVISO-- El vector dinamico ahora se almacena en: " << static_cast<void *>(palabra);
        copiarDatos(auxiliar, 0, tamanioNuevo);
        delete []auxiliar;
        cout << "\n--REDIMENSIONAR AVISO-- Se libero la memoria a la que apuntaba auxiliar almacenada en: " << static_cast<void *>(auxiliar) << "\n";
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
// -------------------------------->