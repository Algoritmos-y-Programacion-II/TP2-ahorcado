//
// Created by Valentina on 17/5/2020.
//

#include "Ahorcado.h"
#include <iostream>

// Categorias
const int VERDURAS = 0;
const int FRUTAS = 1;
const int PAISES = 2;
const int NOMBRES_FEMENINOS = 3;
const int NOMBRES_MASCULINOS = 4;
const int COLORES = 5;
const int LENGUAJES_PROGRAMACION = 6;
const int INGLES = 7;
const int CUALQUIER_COSA = 8;

// Posibles palabras aleatorias
const int CANT_PALABRAS = 10;
const int CANT_CATEGORIAS = 9;
const string PALABRAS[CANT_CATEGORIAS][CANT_PALABRAS] = { {"PAPA", "ACELGA", "TOMATE", "ZANAHORIA", "REMOLACHA", "BATATA", "ESPINACA", "ZUCCINI", "BERENJENA", "CEBOLLA"},
                                                          {"BANANA", "MANZANA", "MANDARINA", "NARANJA", "HIGO", "DATIL", "MELON", "SANDIA", "ANANA", "CIRUELA"},
                                                          {"ARGENTINA", "PARAGUAY", "URUGUAY", "CHILE", "BOLIVIA", "PERU", "ECUADOR", "VENEZUELA", "MEXICO", "GUATEMALA"},
                                                          {"TOMAS", "PEDRO", "JUAN", "HERNAN", "ALEJANDRO", "TOBIAS", "MATEO", "THEO", "JORGE", "ANDRES"},
                                                          {"VALERIA", "AGUSTINA", "ALEXA", "MARTINA", "MAGALI", "VERONICA", "FLORENCIA", "JOSELINA", "ANDREA", "INES"},
                                                          {"AMARILLO", "AZUL", "NARANJA", "ROJO", "VERDE", "VIOLETA", "NEGRO", "BLANCO", "GRIS", "CELESTE"},
                                                          {"JAVASCRIPT", "R", "PYTHON", "PHP", "SQL", "PASCAL", "COBOL", "PERL", "RUBY", "C"},
                                                          {"DESKTOP", "FORK", "TABLESPOON", "OUTSIDE", "HIGHSCHOOL", "PENCILCASE", "CINEMA", "THEATRE", "REASON", "RUNNING"},
                                                          {"NUTELLA", "HELADERA", "OTORRINOLARINGOLOGIA", "ALMOHADA", "FONOAUDIOLOGIA", "BOMBERO", "ANDROID", "PANQUEQUERA", "ORNITORRINCO", "COSO"} };


// ------------------------------------------------ METODOS PUBLICOS ------------------------------------------------//

// <--------------------- constructores
Ahorcado:: Ahorcado() {
    estadoJuego = EMPEZO_JUEGO;
    letrasErroneas = "";
}

Ahorcado:: Ahorcado(Jugador jugadorOut) {
    jugador = jugadorOut;
    jugador.asignarVidas(CANT_VIDAS);
    estadoJuego = EMPEZO_JUEGO;
}
// -------------------------------->


// <--------------------- setters
void Ahorcado:: asignarNombreJugador(string nombreJugador) {
    jugador.asignarNombre(nombreJugador);
}

void Ahorcado:: asignarPalabraSecreta(int tamanioOut) {
    palabraSecreta.redimensionar(tamanioOut);
    for (int i = 0; i < tamanioOut; i++) {
        palabraSecreta.insertarCaracter('_', i);
    }
}

void Ahorcado:: asignarPalabraAAdivinar(string palabra) {
    palabraAAdivinar.asignarPalabra(palabra);
    estadoJuego = EMPEZO_JUEGO;
}

void Ahorcado:: asignarCategoria(int opcion) {
    categoria = opcion;
}
// -------------------------------->


// <--------------------- getters
int Ahorcado:: obtenerEstadoJuego() {
    return estadoJuego;
}

int Ahorcado:: obtenerCategoria() {
    return categoria;
}

Jugador Ahorcado:: obtenerJugador() {
    return jugador;
}

string Ahorcado:: obtenerLetrasErroneas() {
    return letrasErroneas;
}
// -------------------------------->


// <--------------------- metodos para NO implementar la logica en la funcion principal
void Ahorcado:: main() {

    bool jugarDeNuevo;

    mostrarInstrucciones();

    if(jugador.deseaCrearUsuario()) {
        jugador.asignarNombre(jugador.pedirNombre());
    }

    jugador.asignarVidas(CANT_VIDAS);

    do {
        mostrarCategorias();
        elegirCategoria();
        elegirPalabraAleatoriaSegunCategoria();

        nuevoJuego();

        jugarDeNuevo = deseaJugarDeNuevo();

        if (jugarDeNuevo)
            resetearJuego();

    } while (jugarDeNuevo);

    mostrarDespedida();
}

void Ahorcado:: nuevoJuego() {

    string palabraIngresada;
    actualizarAhorcado();

    while (estadoJuego == EMPEZO_JUEGO && jugador.obtenerVidas() > 0) {

        cout << "Ingresa una letra o palabra: ";
        palabraIngresada = Utils::obtenerPalabraEnMayusculas();
        Utils::validarPalabra(palabraIngresada);

        if (palabraIngresada.length() > 1)
            arriesgar(palabraIngresada); // Metodo que recibe string

        else
            arriesgar(palabraIngresada[0]); // Metodo que recibe caracter

        actualizarAhorcado();
    }

    mostrarMensajeGanoOPerdio();
}
// -------------------------------->


// <--------------------- metodos para elegir
void Ahorcado:: elegirCategoria() {
    cout << "\nCategoria elegida: ";
    cin >> categoria;
    Utils::validarNumero(1, CANT_CATEGORIAS, categoria);
    categoria -= 1;
}

void Ahorcado:: elegirPalabraAleatoriaSegunCategoria() {

    int random = Utils::numeroRandom(0, CANT_PALABRAS);
    string palabra;

    switch (categoria) {

        case VERDURAS:
            palabra = PALABRAS[VERDURAS][random];
            break;

        case FRUTAS:
            palabra = PALABRAS[FRUTAS][random];
            break;

        case PAISES:
            palabra = PALABRAS[PAISES][random];
            break;

        case NOMBRES_FEMENINOS:
            palabra = PALABRAS[NOMBRES_FEMENINOS][random];
            break;

        case NOMBRES_MASCULINOS:
            palabra = PALABRAS[NOMBRES_MASCULINOS][random];
            break;

        case COLORES:
            palabra = PALABRAS[COLORES][random];
            break;

        case LENGUAJES_PROGRAMACION:
            palabra = PALABRAS[LENGUAJES_PROGRAMACION][random];
            break;

        case INGLES:
            palabra = PALABRAS[INGLES][random];
            break;

        case CUALQUIER_COSA:
            palabra = PALABRAS[CUALQUIER_COSA][random];
            break;
    }

    palabraAAdivinar.asignarPalabra(palabra);
    asignarPalabraSecreta(palabraAAdivinar.obtenerTamanio());
}
// -------------------------------->


// <--------------------- metodos para arriesgar
void Ahorcado:: arriesgar(char caracter) {
    string palabraAux;

    if (palabraAAdivinar.checkCaracterEnPalabra(caracter)) {

        for (int i = 0; i < palabraAAdivinar.obtenerTamanio(); i++) {

            if (caracter == palabraAAdivinar.obtenerElemento(i))
                palabraSecreta.insertarCaracter(caracter, i);
        }

        if (palabraSecreta.obtenerPalabra() == palabraAAdivinar.obtenerPalabra())
            estadoJuego = GANO_JUEGO;
    }
    else {
        jugador.quitarVidas(1);

        if (jugador.obtenerVidas() <= 0)
            estadoJuego = PERDIO_JUEGO;

        letrasErroneas = letrasErroneas + caracter + " ";
    }
}

void Ahorcado:: arriesgar(string palabra) {

    if (palabraAAdivinar.obtenerPalabra() == palabra) {
        palabraSecreta.asignarPalabra(palabra);
        estadoJuego = GANO_JUEGO;
    }

    else {
        jugador.quitarVidas(2);

        if (jugador.obtenerVidas() <= 0)
            estadoJuego = PERDIO_JUEGO;
    }
}
// -------------------------------->


// <---------------------  otros metodos
void Ahorcado:: actualizarAhorcado() {
    mostrarDibujoAhorcado();
    cout << "           ";
    palabraSecreta.mostrarCaracteres();
    cout << "\n+==================================+\n";
    cout << "Letras ingresadas que no forman parte de la palabra:\n" << letrasErroneas << "\n\n";
}

void Ahorcado:: resetearJuego() {
    jugador.asignarVidas(CANT_VIDAS);
    estadoJuego = EMPEZO_JUEGO;
    letrasErroneas = "";
}

bool Ahorcado:: deseaJugarDeNuevo() {
    char opcion;
    bool crear;
    cout << "\nQueres jugar de nuevo? [s/n] ";
    cin >> opcion;
    crear = Utils::validarSiONo(opcion);
    return crear;
}
// -------------------------------->


// <--------------------- mostrar mensajes
void Ahorcado:: mostrarLogo() {

    cout << "\n\n    _   _  _  ___  ___  ___   _   ___   ___  \n"
            "   /_\\ | || |/ _ \\| _ \\/ __| /_\\ |   \\ / _ \\ \n"
            "  / _ \\| __ | (_) |   / (__ / _ \\| |) | (_) |\n"
            " /_/ \\_\\_||_|\\___/|_|_\\\\___/_/ \\_\\___/ \\___/ \n\n";
}

void Ahorcado:: mostrarInstrucciones() {

    cout << "COMO JUGAR:\n"
            "            1. Decida si desea o no crear un usuario con su nombre\n"
            "            2. Elija la categoria a la cual pertenecera la palabra a adivinar\n"
            "            3. Intente adivinar la palabra antes de quedarse sin vidas (tendra 7)\n"
            "               Puede arriesgar una letra o toda la palabra\n"
            "               Si la letra no esta en la palabra PERDERA UNA vida\n"
            "               Si la palabra no es correcta PERDERA DOS vidas\n"
            "               Buena suerte!\n";
}

void Ahorcado:: mostrarCategorias() {

    cout << "\nElegi la tematica de las palabras a adivinar:\n"
            "1. Verduras\n"
            "2. Frutas\n"
            "3. Paises\n"
            "4. Nombres femeninos\n"
            "5. Nombres masculinos\n"
            "6. Colores\n"
            "7. Lenguajes de programacion varios\n"
            "8. Palabras random en ingles\n"
            "9. Cualquier cosa\n";
}

void Ahorcado:: mostrarMensajeGanoOPerdio() {

    string nombre = jugador.obtenerNombre();

    if (estadoJuego == GANO_JUEGO)
        cout << "Esta vez me ganaste " << nombre << "! Ya vas a ver la proxima...\n";

    else if (estadoJuego == PERDIO_JUEGO) {

        cout << "   ___   _   __  __ ___    _____   _____ ___ \n"
                "  / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\\n"
                " | (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /\n"
                "  \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\\n\n";

        cout << "Que pena " << nombre << ", esta vez perdiste. Quizas la proxima me ganas.\nLa palabra era: ";

        palabraAAdivinar.mostrarCaracteres();
        cout << "\n";
    }
}

void Ahorcado:: mostrarDespedida() {

    cout << "\nGracias por haber jugado al ahorcado "
         << jugador.obtenerNombre() << "!\nNos vemos la proxima :D\n";
}

void Ahorcado:: mostrarDibujoAhorcado() {

    if (jugador.obtenerVidas() > 0)
        cout << "\nTe quedan " << jugador.obtenerVidas() << " vidas\n";

    switch (jugador.obtenerVidas()) {
        case 7:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 6:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 5:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 4:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |        |                 |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 3:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |       /|                 |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 2:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |       /|\\                |\n"
                    "|       |        |                 |\n"
                    "|       |                          |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 1:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |       /|\\                |\n"
                    "|       |        |                 |\n"
                    "|       |       /                  |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;
        case 0:
            cout << "+==================================+\n"
                    "|              AHORCADO            |\n"
                    "+==================================+\n"
                    "|       +--------+                 |\n"
                    "|       |        |                 |\n"
                    "|       |       ( )                |\n"
                    "|       |       /|\\                |\n"
                    "|       |        |                 |\n"
                    "|       |       / \\                |\n"
                    "|       |                          |\n"
                    "|   +-------+                      |\n"
                    "|   |||||||||                      |\n"
                    "|   +-------+                      |\n"
                    "+==================================+\n"
                    "|    A B C D E F G H I J K L M N   |\n"
                    "|      O P Q R S T U V W X Y Z     |\n"
                    "+==================================+\n";
            break;

    }
}
// -------------------------------->