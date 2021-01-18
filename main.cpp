#include <iostream>
#include "structure.h"
#include "appelFonctions.h"

using namespace std;

int main(int argc, char *argv[])
{

    Jeu jeu1;
    Joueur j1, j2;
    int i(0), j(0);

    //initialise les joueurs
    (&j1)->color[0] = 'A';
    (&j2)->color[0] = 'B';
    initJoueur(&jeu1, &j1, &j2);

    //initialise le plateau
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            (&jeu1)->Board[i][j] = NULL;
        }
    }
    //initialise les jetons présents sur le plateau
    initJeton((&jeu1)->Board, j1, 3, 3);
    initJeton((&jeu1)->Board, j2, 3, 4);
    initJeton((&jeu1)->Board, j2, 4, 3);
    initJeton((&jeu1)->Board, j1, 4, 4);

    displayBoard((&jeu1)->Board);
    //fonction joueur actuel (par defaut j1)
    Jeton jeton = *nouveauJeton((&jeu1)->Board, j1);
    displayBoard((&jeu1)->Board);
    captureJetons((&jeu1)->Board, j1, j2, jeton);
    displayBoard((&jeu1)->Board);
    return 0;
}
