#include <iostream>
/*
Implemente la función GetEstado en contenido en el archivo solucion.cpp
*/
#include "constantes.h"
#include "solucion.h"
#include "logica.h"

using namespace std;

int main()
{
    IniciarTablero();
    do
    {
        DesplegarTablero();
        CapturarJugada();
    }while (GetEstado() == JUEGO_EN_CURSO);
    switch(GetEstado())
    {
        case GANO_X:
            cout << endl << "Ha ganado el jugador X" << endl;
        break;
        case GANO_O:
            cout << endl << "Ha ganado el jugador O" << endl;
        break;
        case EMPATE:
            cout << endl << "Se ha producido un empate" << endl;
        break;
    }
    cout << endl << endl;
    DesplegarTablero();
    cout << endl << endl;
    return 0;
}
