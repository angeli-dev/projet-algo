//#include <iostream>
#include "structure.h"
#include "appelFonctions.h"
//using namespace std;

int main(int argc, char *argv[])
{
    char A, B;
    Jeu jeu1;
    Joueur j1, j2;
    int i(0), j(0);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            (&jeu1)->Board[i][j] = ' ';
    }
    A = 'A';
    B = 'B';
    (&jeu1)->Board[3][3] = A;
    (&jeu1)->Board[3][4] = B;
    (&jeu1)->Board[4][3] = B;
    (&jeu1)->Board[4][4] = A;
    initJoueur(&jeu1, &j1, &j2);
    displayBoard((&jeu1)->Board);
    nouveauJeton((&jeu1)->Board);

    return 0;
}