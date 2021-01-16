#include <iostream>
using namespace std;
#include "structure.h"
#include "appelFonctions.h"

void displayBoard(char Board[8][8]){
    cout << "     A   B   C   D   E   F   G   H" << endl;
    for (int row = 0; row < 8; row++)
    {
        cout << "   +---+---+---+---+---+---+---+---+" << endl;
        cout << row+1 << "  | ";
        for (int col = 0; col < 8; col++)
        {
            cout << Board[row][col] << " | ";
        }
        cout << endl;
    }
    cout << "   +---+---+---+---+---+---+---+---+" << endl;
}

void initJoueur(Jeu *jeu, Joueur *j1, Joueur *j2){
    cout << "Quel est le nom du premier joueur : ";
    cin >> j1->name;
    j1->nbJetons = 2;

    cout << "Quel est le nom du second joueur : ";
    cin >> j2->name;
    j2->nbJetons = 2;
}