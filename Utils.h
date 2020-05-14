//
// Created by Valentina on 8/5/2020.
//

#ifndef TRABAJOPRACTICO2AHORCADO_UTILS_H
#define TRABAJOPRACTICO2AHORCADO_UTILS_H

#include <iostream>
#include <ctime> // Numero "random"
#include <regex> // Validaciones

using namespace std;

const int VERDURAS = 1;
const int FRUTAS = 2;
const int PAISES = 3;
const int NOMBRES_FEMENINOS = 4;
const int NOMBRES_MASCULINOS = 5;
const int COLORES = 6;

const int CANT_PALABRAS = 10;

const string PALABRAS_VERDURAS[CANT_PALABRAS] = {"PAPA", "ACELGA", "TOMATE", "ZANAHORIA", "REMOLACHA", "BATATA", "ESPINACA", "ZUCCINI", "BERENJENA", "CEBOLLA" };
const string PALABRAS_FRUTAS[CANT_PALABRAS] = {"BANANA", "MANZANA", "MANDARINA", "NARANJA", "HIGO", "DATIL", "MELON", "SANDIA", "ANANA", "CIRUELA"};
const string PALABRAS_PAISES[CANT_PALABRAS] = {"ARGENTINA", "PARAGUAY", "URUGUAY", "CHILE", "BOLIVIA", "PERU", "ECUADOR", "VENEZUELA", "MEXICO", "GUATEMALA"};
const string PALABRAS_NOMBRES_M[CANT_PALABRAS] = {"TOMAS", "PEDRO", "JUAN", "hernan", "ALEJANDRO", "TOBIAS", "MATEO", "THEO", "JORGE", "ANDRES"};
const string PALABRAS_NOMBRES_F[CANT_PALABRAS] = {"VALERIA", "AGUSTINA", "ALEXA", "MARTINA", "MAGALI", "VERONICA", "FLORENCIA", "JOSELINA", "ANDREA", "INES"};
const string PALABRAS_COLORES[CANT_PALABRAS] = {"AMARILLO", "AZUL", "NARANJA", "ROJO", "VERDE", "VIOLETA", "NEGRO", "BLANCO", "GRIS", "CELESTE"};

class Utils {

    public:

        static bool validarSiONo(char opcion);

        // PRE: -
        // POST: devuelve una palabra aleatoria segun la categoria elegida por el usuario
        static string elegirPalabraAleatoriaSegunCategoria();

        // PRE: -
        // POST: Verifica que num este entre min y max, devuelve el numero validado
        static int validarNumero(int min, int max, int num);

        // PRE: -
        // POST: Verifica que la palabra solo contenga letras, devuelve la palabra validada
        static string validarPalabra(string palabra);

        // PRE: -
        // POST: Devuelve una palabra ingresada por el usuario pero en mayusculas
        static string obtenerPalabraEnMayusculas();

    private:
        static int numeroRandom(int min, int max);
        static void mostrarCategorias();
};

#endif //TRABAJOPRACTICO2AHORCADO_UTILS_H
