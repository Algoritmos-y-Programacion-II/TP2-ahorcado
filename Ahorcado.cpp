//
// Created by Valentina on 8/5/2020.
//

#include "Ahorcado.h"
// ------------------------------ METODOS PUBLICOS ----------------------------------//
//
Ahorcado:: Ahorcado(Jugador jugadorOut, string palabraAleatoria, int tamanioPalabra) : palabraAAdivinar(palabraAleatoria, tamanioPalabra),
                                                                                       palabraSecreta("",0) {
    estadoJuego = EMPEZO_JUEGO;
    intentosFallidos = 0;
    jugador = jugadorOut;
    palabraSecreta.redimensionar(tamanioPalabra);
    for (int i = 0; i < tamanioPalabra ; i++) {
        palabraSecreta.insertarCaracter('_', i);
    }
}

void Ahorcado:: nuevoJuego() {

    string palabraAdivinada;
    actualizarAhorcado();

    while (estadoJuego == EMPEZO_JUEGO && jugador.obtenerVidas() > 0) {

        cout << "Ingresa una letra o palabra: ";
        palabraAdivinada = obtenerPalabraEnMayusculas();
        palabraAdivinada = validarPalabra(palabraAdivinada);

        if (palabraAdivinada.length() > 1)
            arriesgar(palabraAdivinada);

        else arriesgar(palabraAdivinada[0]);
    }

    if (jugador.obtenerVidas() <= 0)
        estadoJuego = PERDIO_JUEGO;

    mostrarMensajeGanoOPerdio();
}

bool Ahorcado:: deseaJugarDeNuevo() {
    char opcion;
    cout << "\nQueres jugar de nuevo? [s/n] ";
    cin >> opcion;
    return ('s' == opcion || 'S' == opcion);
}

void Ahorcado:: mostrarMensajeGanoOPerdio() {
    string nombre = jugador.obtenerNombre();
    if (estadoJuego == GANO_JUEGO)  {
        cout << "Esta vez me ganaste " << nombre << "! Ya vas a ver la proxima...\n";
    } else if (estadoJuego == PERDIO_JUEGO) {
        cout << "Que pena " << nombre << ", esta vez perdiste. Quizas la proxima me ganas.\nLa palabra era: ";
        palabraAAdivinar.mostrarCaracteresSeparadosPorEspacio();
        cout << "\n";
    }
}

void Ahorcado:: mostrarDespedida() {
    cout << "\nGracias por haber jugado al ahorcado "
         << jugador.obtenerNombre() << "!\nNos vemos la proxima :D\n";
}

// ------------------------------ METODOS PRIVADOS ----------------------------------//

void Ahorcado:: arriesgar(char caracter) {
    bool coincidio = palabraAAdivinar.checkCaracterEnPalabra(caracter);
    string palabraAux;

    if (coincidio) {
        for (int i = 0; i < palabraAAdivinar.obtenerTamanio(); i++) {
            if (caracter == palabraAAdivinar.obtenerElemento(i))
                palabraSecreta.insertarCaracter(caracter, i);
            }
        if (palabraSecreta.obtenerPalabra() == palabraAAdivinar.obtenerPalabra())
            estadoJuego = GANO_JUEGO;
        actualizarAhorcado();
    } else {
        intentosFallidos++;
        jugador.quitarVidas(1);
        actualizarAhorcado();
    }
}

void Ahorcado:: arriesgar(string palabra) {
    if (palabraAAdivinar.obtenerPalabra() == palabra) {
        palabraSecreta.asignarPalabra(palabra);
        actualizarAhorcado();
        estadoJuego = GANO_JUEGO;
    } else {
        intentosFallidos += 2;
        jugador.quitarVidas(2);
        actualizarAhorcado();
    }
}

void Ahorcado:: actualizarAhorcado() {
    mostrarDibujoAhorcado();
    cout << "             ";
    palabraSecreta.mostrarCaracteresSeparadosPorEspacio();
    cout << "\n+==================================+\n\n";
}

void Ahorcado:: mostrarDibujoAhorcado() {

    switch (intentosFallidos) {
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