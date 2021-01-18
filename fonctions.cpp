#include <iostream>
#include <cstdio>
using namespace std;
#include "structure.h"
#include "appelFonctions.h"

void initBoard(Jeton *Board[8][8], Joueur j1, Joueur j2)
{
    int i(0), j(0);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            Board[i][j] = NULL;
        }
    }
    //Initialise les jetons présents sur le plateau
    initJeton(Board, j1, 3, 3);
    initJeton(Board, j2, 3, 4);
    initJeton(Board, j2, 4, 3);
    initJeton(Board, j1, 4, 4);
}
void displayBoard(Jeton *Board[8][8])
{
    cout << "          ---PLATEAU ACTUEL---" << endl;

    cout << "     A   B   C   D   E   F   G   H" << endl;
    for (int row = 0; row < 8; row++)
    {
        cout << "   +---+---+---+---+---+---+---+---+" << endl;
        cout << row + 1 << "  | ";
        for (int col = 0; col < 8; col++)
        {
            if (Board[row][col])
            {
                cout << Board[row][col]->color[0] << " | ";
            }
            else
                cout << " "
                     << " | ";
        }
        cout << endl;
    }
    cout << "   +---+---+---+---+---+---+---+---+" << endl;
}

void initJoueur(Jeu *jeu, Joueur *j1, Joueur *j2)
{
    cout << "Quel est le nom du premier joueur : ";
    cin >> j1->name;
    cout << "Choisisez votre couleur : ";
    cin >> j1->color;
    j1->nbJetons = 2;
    jeu->j1 = *j1;

    cout << "Quel est le nom du second joueur : ";
    cin >> j2->name;
    cout << "Choisisez votre couleur : ";
    cin >> j2->color;
    j2->nbJetons = 2;
    jeu->j2 = *j2;
}

Jeton *initJeton(Jeton *Board[8][8], Joueur joueurActif, int posY, int posX)
{
    Jeton *nouveauJeton = (Jeton *)malloc(sizeof(*nouveauJeton));
    nouveauJeton->x = posX;
    nouveauJeton->y = posY;
    //Récupérer couleur du joueur
    nouveauJeton->color[0] = (&joueurActif)->color[0];
    //Placer  jeton

    Board[nouveauJeton->y][nouveauJeton->x] = nouveauJeton;
    return nouveauJeton;
}

void nouveauTour(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif)
{
    Jeton *jeton = nouveauJeton(Board, joueurActif);
    displayBoard(Board);
    //capture
    captureJetons(Board, joueurActif, joueurPassif, *jeton);
}

Jeton *nouveauJeton(Jeton *Board[8][8], Joueur joueurActif)
{

    char pos[2];
    int posX, posY;

    //nombre de pions du joueur actuel+1
    (&joueurActif)->nbJetons += 1;

    //demande placement jeton
    cout << "Ou voulez vous placez votre jeton : (Ex: B4, G2...) ";
    cin >> pos;

    //Position X
    if (pos[0] == 'A' || pos[0] == 'a')
    {
        posX = 0;
    }
    else if (pos[0] == 'B' || pos[0] == 'b')
    {
        posX = 1;
    }
    else if (pos[0] == 'C' || pos[0] == 'c')
    {
        posX = 2;
    }
    else if (pos[0] == 'D' || pos[0] == 'd')
    {
        posX = 3;
    }
    else if (pos[0] == 'E' || pos[0] == 'e')
    {
        posX = 4;
    }
    else if (pos[0] == 'F' || pos[0] == 'f')
    {
        posX = 5;
    }
    else if (pos[0] == 'G' || pos[0] == 'g')
    {
        posX = 6;
    }
    else if (pos[0] == 'H' || pos[0] == 'h')
    {
        posX = 7;
    }

    //Position Y
    if (pos[1] == '1')
    {
        posY = 0;
    }
    else if (pos[1] == '2')
    {
        posY = 1;
    }
    else if (pos[1] == '3')
    {
        posY = 2;
    }
    else if (pos[1] == '4')
    {
        posY = 3;
    }
    else if (pos[1] == '5')
    {
        posY = 4;
    }
    else if (pos[1] == '6')
    {
        posY = 5;
    }
    else if (pos[1] == '7')
    {
        posY = 6;
    }
    else if (pos[1] == '8')
    {
        posY = 7;
    }

    //creer et place le nouveau jeton
    Jeton *nouveauJeton = initJeton(Board, joueurActif, posY, posX);

    //retourne le nouveau jeton
    return nouveauJeton;
}

void captureJetons(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
{
    captureDroite(Board, joueurActif, joueurPassif, nouveauJeton);
    captureGauche(Board, joueurActif, joueurPassif, nouveauJeton);
    captureHaut(Board, joueurActif, joueurPassif, nouveauJeton);
    captureBas(Board, joueurActif, joueurPassif, nouveauJeton);
    captureDiagonaleDB(Board, joueurActif, joueurPassif, nouveauJeton);
    captureDiagonaleDH(Board, joueurActif, joueurPassif, nouveauJeton);
    captureDiagonaleGB(Board, joueurActif, joueurPassif, nouveauJeton);
    captureDiagonaleGH(Board, joueurActif, joueurPassif, nouveauJeton);
}

void captureDroite(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;

    if (Board[posY][posX + 1])
    {
        while (Board[posY][posX + 1]->color[0] == (&joueurPassif)->color[0])
        {
            nbJetonsACapturer += 1;
            posX += 1;
        }
    };

    for (int i = 0; i < nbJetonsACapturer; i++)
    {

        Board[posY][posX]->color[0] = (&joueurActif)->color[0];
        posX -= 1;
    };
}

void captureGauche(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;

    if (Board[posY][posX - 1])
    {
        while (Board[posY][posX - 1]->color[0] == (&joueurPassif)->color[0])
        {

            nbJetonsACapturer += 1;
            posX -= 1;
        }
    };

    for (int i = 0; i < nbJetonsACapturer; i++)
    {
        Board[posY][posX]->color[0] = (&joueurActif)->color[0];
        posX += 1;
    }
}

void captureHaut(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;

    if (Board[posY + 1][posX])
    {
        while (Board[posY + 1][posX]->color[0] == (&joueurPassif)->color[0])
        {

            nbJetonsACapturer += 1;
            posY += 1;
        }
    };

    for (int i = 0; i < nbJetonsACapturer; i++)
    {
        Board[posY][posX]->color[0] = (&joueurActif)->color[0];
        posY += 1;
    }
}

void captureBas(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;

    if (Board[posY - 1][posX])
    {
        while (Board[posY - 1][posX]->color[0] == (&joueurPassif)->color[0])
        {

            nbJetonsACapturer += 1;
            posY -= 1;
        }
    };

    for (int i = 0; i < nbJetonsACapturer; i++)
    {
        Board[posY][posX]->color[0] = (&joueurActif)->color[0];
        posY += 1;
    }
}

void captureDiagonaleDB(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;

    if (Board[posY + 1][posX + 1])
    {
        while (Board[posY + 1][posX + 1]->color[0] == (&joueurPassif)->color[0])
        {

            nbJetonsACapturer += 1;
            posX += 1;
            posY += 1;
        }
    };

    for (int i = 0; i < nbJetonsACapturer; i++)
    {
        Board[posY - 1][posX - 1]->color[0] = (&joueurActif)->color[0];
        posX -= 1;
        posY -= 1;
    }
}
void captureDiagonaleDH(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;

    if (Board[posY - 1][posX + 1])
    {
        while (Board[posY - 1][posX + 1]->color[0] == (&joueurPassif)->color[0])
        {

            nbJetonsACapturer += 1;
            posX += 1;
            posY -= 1;
        }
    };

    for (int i = 0; i < nbJetonsACapturer; i++)
    {
        Board[posY + 1][posX - 1]->color[0] = (&joueurActif)->color[0];
        posX -= 1;
        posY += 1;
    }
}
void captureDiagonaleGB(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;

    if (Board[posY + 1][posX - 1])
    {
        while (Board[posY + 1][posX - 1]->color[0] == (&joueurPassif)->color[0])
        {

            nbJetonsACapturer += 1;
            posX -= 1;
            posY += 1;
        }
    };

    for (int i = 0; i < nbJetonsACapturer; i++)
    {
        Board[posY - 1][posX + 1]->color[0] = (&joueurActif)->color[0];
        posX += 1;
        posY -= 1;
    }
}
void captureDiagonaleGH(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;

    if (Board[posY - 1][posX - 1])
    {
        while (Board[posY + 1][posX + 1]->color[0] == (&joueurPassif)->color[0])
        {

            nbJetonsACapturer += 1;
            posX -= 1;
            posY -= 1;
        }
    };

    for (int i = 0; i < nbJetonsACapturer; i++)
    {
        Board[posY + 1][posX + 1]->color[0] = (&joueurActif)->color[0];
        posX += 1;
        posY += 1;
    }
}