//#include <iostream>
#include "structure.h"
#include "appelFonctions.h"
//using namespace std;

int main(int argc, char *argv[])
{

    Jeu jeu1;
    Joueur j1, j2;
    int i(0), j(0);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            (&jeu1)->Board[i][j] = ' ';
    }
    (&j1)->color[0] = 'A';
    (&j2)->color[0] = 'B';
    (&jeu1)->Board[3][3] = (&j1)->color[0];
    (&jeu1)->Board[3][4] = (&j2)->color[0];
    (&jeu1)->Board[4][3] = (&j2)->color[0];
    (&jeu1)->Board[4][4] = (&j1)->color[0];
    initJoueur(&jeu1, &j1, &j2);
    displayBoard((&jeu1)->Board);
    //fonction joueur actuel (par defaut j1)
    nouveauJeton((&jeu1)->Board, j1);

    return 0;
}