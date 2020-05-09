//
// Created by Valentina on 8/5/2020.
//

#include "Ahorcado.h"

Ahorcado:: Ahorcado(int vidasOut, string nombre, string palabraAleatoria, int tamanioPalabra) : palabraAAdivinar(palabraAleatoria, tamanioPalabra) {
    estadoJuego = EMPEZO_JUEGO;
    jugador = Jugador(vidasOut, nombre);
    intentosFallidos = 0;
}

void Ahorcado:: mostrarLogo() {
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
}

int Ahorcado:: obtenerEstadoJuego() {
    return estadoJuego;
}

void Ahorcado:: arriesgar(char caracter) {
    bool coincidio = palabraAAdivinar.checkCaracterEnPalabra(caracter);
    if (coincidio) {
        actualizarAhorcado(caracter);
    } else {
        intentosFallidos++;
        jugador.quitarVidas(1);
        cout << "Ooops! Incorrecto\nLe quedan " << jugador.obtenerVidas() << " vidas\n";
        actualizarDibujoAhorcado(intentosFallidos);
    }
}

void Ahorcado:: arriesgar(string palabra) {
    if (palabraAAdivinar.obtenerPalabra() == palabra) {
        actualizarAhorcado(palabra);
        estadoJuego = GANO_JUEGO;
    } else {
        intentosFallidos++;
        jugador.quitarVidas(2);
        cout << "Ooops! Incorrecto\nLe quedan " << jugador.obtenerVidas() << " vidas\n";
        actualizarDibujoAhorcado(intentosFallidos);
    }
}

void Ahorcado:: nuevoJuego() {
    mostrarLogo();
    palabraAAdivinar.mostrarPalabra();
    string palabraAdivinada;
    while (obtenerEstadoJuego() == EMPEZO_JUEGO && jugador.obtenerVidas() > 0) {
        cout << "Ingresa una letra o palabra: ";
        cin >> palabraAdivinada;
        if (palabraAdivinada.length() > 1)
            arriesgar(palabraAdivinada);
        else arriesgar(palabraAdivinada[0]);
    }
    if (jugador.obtenerVidas() < 0)
        estadoJuego = PERDIO_JUEGO;
    mostrarMensajeGanoOPerdio();
}

void Ahorcado:: actualizarAhorcado(char caracter) {
    actualizarDibujoAhorcado(intentosFallidos);
    // TODO: mostrar *** y letras
    cout << "+==================================+\n";
}

void Ahorcado:: actualizarAhorcado(string palabra) {
    // TODO: falta implementar
    actualizarDibujoAhorcado(intentosFallidos);
    cout << palabra << "\n+==================================+\n";
}

void Ahorcado:: mostrarMensajeGanoOPerdio() {
    string nombre = jugador.obtenerNombre();
    if (estadoJuego == GANO_JUEGO)  {
        cout << "Muy bien " << nombre << ", ganaste!\n";
    } else if (estadoJuego == PERDIO_JUEGO) {
        cout << "Lo siento " << nombre << ", esta vez perdiste :(\nLa palabra era: ";
        palabraAAdivinar.mostrarPalabra();
    }
}

bool Ahorcado:: deseaJugarDeNuevo() {
    char si = 's', opcion;
    cout << "¿Desea volver a jugar? [s/n] ";
    cin >> opcion;
    return si == opcion;
}

void Ahorcado:: mostrarDespedida() {
    cout << "Gracias por haber jugado al ahorcado "
         << jugador.obtenerNombre() << "!\nNos vemos la próxima :)\n";
}

void Ahorcado:: actualizarDibujoAhorcado(int fallos) {

    switch (fallos) {
        case 0:
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
        case 1:
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
        case 2:
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
        case 3:
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
        case 4:
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
        case 5:
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
        case 6:
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
        case 7:
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