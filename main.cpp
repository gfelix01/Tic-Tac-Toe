#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    else
    {
        return false;
    }
}

int checkWinner()
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

void swapPlayer()
{
    current_player = (current_player == 1) ? 2 : 1;
    current_marker = (current_marker == 'X') ? 'O' : 'X';
}

void game()
{
    cout << "Player 1, choose your marker: ";
    cin >> current_marker;
    current_player = 1;

    int player_won;

    for (int i = 0; i < 9; i++)
    {
        drawBoard();
        cout << "It's player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot))
        {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        player_won = checkWinner();

        if (player_won == 1)
        {
            cout << "Player 1 wins!\n";
            break;
        }
        else if (player_won == 2)
        {
            cout << "Player 2 wins!\n";
            break;
        }

        swapPlayer();
    }

    if (player_won == 0)
        cout << "It's a tie!\n";

    drawBoard();
}

int main()
{
    game();
    return 0;
}
