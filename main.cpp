#include <iostream>
#include "structure.h"
#include "appelFonctions.h"

using namespace std;

int main(int argc, char *argv[])
{

    Jeu jeu1;
    Joueur j1, j2;
    //initialise les joueurs
    initJoueur(&jeu1);
    j1 = jeu1.j1;
    j2 = jeu1.j2;
    initBoard((&jeu1)->Board, j1, j2);
    displayBoard((&jeu1)->Board);
    //fonction joueur actuel (par defaut j1)
    while (1) //réalise 2 tours de jeux ?
    {
        cout << "nom" << j1.name << endl;
        nouveauTour((&jeu1)->Board, &j1, j2);
    }
    return 0;
}
