#include <iostream>
#include "structure.h"
using namespace std;

void initJoueur(Jeu *jeu, Joueur *j1, Joueur *j2){
    cout << "Quel est le nom du premier joueur : ";
    cin >> j1->name;
    j1->nbJetons = 2;

    cout << "Quel est le nom du second joueur : ";
    cin >> j2->name;
    j2->nbJetons = 2;
}