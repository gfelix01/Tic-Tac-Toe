#include <iostream>
#include "logica.h"

using namespace std;
char** tablero = NULL;
char jugadorActual = 'X';

char** GetTablero()
{
    return tablero;
}

void IniciarTablero()
{
    tablero = new char*[3];
    for(int i = 0 ; i < 3; i++)
    {
        tablero[i] = new char[3];
        for(int j = 0 ; j < 3; j++)
        {
            tablero[i][j] = '_';
        }
    }
}

void Jugar(char jugador, int fila, int columna)
{
    if(tablero[fila][columna] != '_')
    {
        cout << "\nEsta casilla no está disponible\n" << endl;
        return;
    }
    tablero[fila][columna] = jugador;
    jugadorActual = jugadorActual == 'X' ? 'O' : 'X';
}

void DesplegarTablero()
{
    for(int i = 0 ; i < 3; i++)
    {
        for(int j = 0 ; j < 3; j++)
        {
            cout << tablero[i][j] << "\t";
        }
        cout << endl;
    }
}

void CapturarJugada()
{
    int fila, columna;
    cout << endl << "Introduzca la fila (de 0 a 2) donde jugará el jugador " << jugadorActual << endl;
    cin >> fila;
    cout << "Introduzca la columna (de 0 a 2) donde jugará el jugador " << jugadorActual << endl;
    cin >> columna;
    Jugar(jugadorActual, fila, columna);

}
