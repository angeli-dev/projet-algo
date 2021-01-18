#include <iostream>
#include "structure.h"
#include "appelFonctions.h"
#include "capturer.h"
using namespace std;

int main(int argc, char *argv[])
{
    char A, B;
    Jeu *jeu;
    Joueur j1, j2;
    int i(0), j(0);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            jeu->Board[i][j] = NULL;
    }
    A = 'A';
    B = 'B';
    jeu->Board[3][3] = A;
    jeu->Board[3][4] = B;
    jeu->Board[4][3] = B;
    jeu->Board[4][4] = A;
    displayBoard(jeu->Board);
    initJoueur(jeu, &j1, &j2);
    displayBoard(jeu->Board);
    nouveauJeton(jeu->Board);
    displayBoard(jeu->Board);
    return 0;
}