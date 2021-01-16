#include <iostream>
#include "structure.h"
#include "capturer.h"
using namespace std;

void initJoueur(Jeu *jeu, Joueur *j1, Joueur *j2)
{
    cout << "Quel est le nom du premier joueur : ";
    cin >> j1->name;
    j1->nbJetons = 2;

    cout << "Quel est le nom du second joueur : ";
    cin >> j2->name;
    j2->nbJetons = 2;
}

//demande le placement du nouveau jeton et l'ajoute au bon endroit dans le tableau
void nouveauJeton(char Board[8][8]) //ajouter la paramètre Joueur joueur pour la couleur du jeton
{
    Jeton *nouveauJeton;

    //détermine couleur jeton en fonction du joueur actuel
    //(à faire, par défaut A)
    char A;
    nouveauJeton->color = A;

    //demande placement jeton
    cin >> "x:" >> nouveauJeton->x >> "y" >> nouveauJeton->y;

    //place le jeton dans le tableau
    Board[nouveauJeton->x][nouveauJeton->y] = nouveauJeton->color;
}