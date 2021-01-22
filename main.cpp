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

    while (finPartie(j1, j2))
    {
        //cout << j2.nbJetons << endl;
        nouveauTour((&jeu1)->Board, &j1, &j2);
        joueurSuivant(&j1, &j2);
    }
    resultatsJeu(j1, j2);
    return 0;
}
