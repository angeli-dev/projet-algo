#include <iostream>
#include "structure.h"
#include "capturer.h"
using namespace std;

void displayBoard(char Board[8][8]);
void nouveauJeton(char Board[8][8]);

int main()
{
    Jeu *jeu;
    char A, B; //tableau de 64 cases
    int i(0), j(0);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            jeu->Board[i][j] = ' ';
    }
    cout << "Enter Your Token Symbol: ";
    cin >> A;
    cout << "Enter Opponent's Token Symbol: ";
    cin >> B;
    jeu->Board[3][3] = A;
    jeu->Board[3][4] = B;
    jeu->Board[4][3] = B;
    jeu->Board[4][4] = A;
    displayBoard(jeu->Board);
    nouveauJeton(jeu->Board);
    displayBoard(jeu->Board);
}
void displayBoard(char Board[8][8])
{
    cout << "     A   B   C   D   E   F   G   H" << endl;
    for (int row = 0; row < 8; row++)
    {
        cout << "   +---+---+---+---+---+---+---+---+" << endl;
        cout << row + 1 << "  | ";
        for (int col = 0; col < 8; col++)
        {
            cout << Board[row][col] << " | ";
        }
        cout << endl;
    }
    cout << "   +---+---+---+---+---+---+---+---+" << endl;
}