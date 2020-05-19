//
// Created by Valentina on 17/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_UTILS_H
#define TRABAJOPRACTICO2AHORCADO_UTILS_H

#include <iostream>
#include <ctime> // Numero "random"
#include <regex> // Validaciones

using namespace std;

namespace Utils {

   bool validarSiONo(char opcion);

    // PRE: -
    // POST: devuelve una palabra aleatoria segun la categoria elegida por el usuario
   string elegirPalabraAleatoriaSegunCategoria();

    // PRE: -
    // POST: Verifica que num este entre min y max, devuelve el numero validado
   void validarNumero(int min, int max, int &num);

    // PRE: -
    // POST: Verifica que la palabra solo contenga letras, devuelve la palabra validada
   void validarPalabra(string &palabra);

    // PRE: -
    // POST: Devuelve una palabra ingresada por el usuario pero en mayusculas
   string obtenerPalabraEnMayusculas();

   int numeroRandom(int min, int max);
}

#endif //TRABAJOPRACTICO2AHORCADO_UTILS_H
