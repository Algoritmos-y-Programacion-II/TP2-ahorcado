//
// Created by Valentina on 8/5/2020.
//

#include "utils.h"

string PALABRAS[] = { "monopatin",
                      "auto",
                      "moto",
                      "camion",
                      "cuatriciclo",
                      "barco",
                      "bicicleta",
                      "avioneta",
                      "patineta",
                      "avion" };

int CANT_PALABRAS = (PALABRAS->length() + 1);

bool deseaCrearUsuario() {
    char opcion;
    cout << "¿Queres crear un usuario y elegir la cantidad de vidas? [s/n]\n"
            "(De lo contrario se te asignara un nombre y una cantidad de vidas predeterminadas)\n";
    cin >> opcion;
    return opcion == 's';
}

string elegirPalabraAleatoria() {
    srand(time(NULL));
    int random = rand() % (CANT_PALABRAS - 1);
    return PALABRAS[random];
}

int pedirVidas() {
    int vidas;
    cout << "\nIngrese la cantidad de vidas que desea: ";
    cin >> vidas;
    return vidas;
}

string pedirNombre() {
    string nombre;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    return nombre;
}