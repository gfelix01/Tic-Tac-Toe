#include <iostream>
using namespace std;

// Tablero de 3x3 inicializado con números del 1 al 9
char tablero[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char marcador_actual;
int jugador_actual;

void dibujarTablero()
{
    cout << " " << tablero[0][0] << " | " << tablero[0][1] << " | " << tablero[0][2] << endl;
    cout << "---|---|---\n";
    cout << " " << tablero[1][0] << " | " << tablero[1][1] << " | " << tablero[1][2] << endl;
    cout << "---|---|---\n";
    cout << " " << tablero[2][0] << " | " << tablero[2][1] << " | " << tablero[2][2] << endl;
}

bool colocarMarcador(int casilla)
{
    int fila = (casilla - 1) / 3;
    int columna = (casilla - 1) % 3;

    if (tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O')
    {
        tablero[fila][columna] = marcador_actual;
        return true;
    }
    else
    {
        return false;
    }
}

int verificarGanador()
{
    // Verificar filas y columnas
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
            return jugador_actual;
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
            return jugador_actual;
    }
    // Verificar diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        return jugador_actual;
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        return jugador_actual;

    return 0;
}

void cambiarJugador()
{
    jugador_actual = (jugador_actual == 1) ? 2 : 1;
    marcador_actual = (marcador_actual == 'X') ? 'O' : 'X';
}

void juego()
{
    cout << "Jugador 1, elige tu marcador (X o O): ";
    cin >> marcador_actual;
    jugador_actual = 1;

    int ganador;

    for (int i = 0; i < 9; i++)
    {
        dibujarTablero();
        cout << "Turno del jugador " << jugador_actual << ". Ingresa una casilla (1-9): ";
        int casilla;
        cin >> casilla;

        if (casilla < 1 || casilla > 9 || !colocarMarcador(casilla))
        {
            cout << "¡Casilla inválida! Intenta de nuevo.\n";
            i--;
            continue;
        }

        ganador = verificarGanador();

        if (ganador == 1)
        {
            cout << "¡Jugador 1 ha ganado!\n";
            break;
        }
        else if (ganador == 2)
        {
            cout << "¡Jugador 2 ha ganado!\n";
            break;
        }

        cambiarJugador();
    }

    if (ganador == 0)
        cout << "¡Empate!\n";

    dibujarTablero();
}

int main()
{
    juego();
    return 0;
}
