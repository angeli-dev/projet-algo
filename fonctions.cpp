#include <iostream>
#include <cstdio>
using namespace std;
#include "structure.h"
#include "appelFonctions.h"

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

void initJoueur(Jeu *jeu, Joueur *j1, Joueur *j2)
{
    cout << "Quel est le nom du premier joueur : ";
    cin >> j1->name;
    j1->nbJetons = 2;
    jeu->j1 = *j1;

    cout << "Quel est le nom du second joueur : ";
    cin >> j2->name;
    j2->nbJetons = 2;
    jeu->j2 = *j2;
}

void nouveauJeton(char Board[8][8], Joueur joueurActuel) //ajouter la paramètre Joueur Joueur pour la couleur du jeton
{
    Jeton *nouveauJeton = (Jeton *)malloc(sizeof(*nouveauJeton));
    char pos[2];
    //détermine couleur jeton en fonction du joueur actuel (à faire, par défaut A)
    nouveauJeton->color[0] = (&joueurActuel)->color[0];
    //nombre de pions du joueur actuel+1
    (&joueurActuel)->nbJetons += 1;
    //demande placement jeton
    cout << "Ou voulez vous placez votre jeton : (Ex: B4, G2...) ";
    cin >> pos;
    //Position X
    if (pos[0] == 'A' || pos[0] == 'a')
    {
        nouveauJeton->x = 0;
    }
    else if (pos[0] == 'B' || pos[0] == 'b')
    {
        nouveauJeton->x = 1;
    }
    else if (pos[0] == 'C' || pos[0] == 'c')
    {
        nouveauJeton->x = 2;
    }
    else if (pos[0] == 'D' || pos[0] == 'd')
    {
        nouveauJeton->x = 3;
    }
    else if (pos[0] == 'E' || pos[0] == 'e')
    {
        nouveauJeton->x = 4;
    }
    else if (pos[0] == 'F' || pos[0] == 'f')
    {
        nouveauJeton->x = 5;
    }
    else if (pos[0] == 'G' || pos[0] == 'g')
    {
        nouveauJeton->x = 6;
    }
    else if (pos[0] == 'H' || pos[0] == 'h')
    {
        nouveauJeton->x = 7;
    }
    //Position Y
    if (pos[1] == '1')
    {
        nouveauJeton->y = 0;
    }
    else if (pos[1] == '2')
    {
        nouveauJeton->y = 1;
    }
    else if (pos[1] == '3')
    {
        nouveauJeton->y = 2;
    }
    else if (pos[1] == '4')
    {
        nouveauJeton->y = 3;
    }
    else if (pos[1] == '5')
    {
        nouveauJeton->y = 4;
    }
    else if (pos[1] == '6')
    {
        nouveauJeton->y = 5;
    }
    else if (pos[1] == '7')
    {
        nouveauJeton->y = 6;
    }
    else if (pos[1] == '8')
    {
        nouveauJeton->y = 7;
    }
    //place le jeton dans le tableau
    Board[nouveauJeton->y][nouveauJeton->x] = 'A';
    displayBoard(Board);
}