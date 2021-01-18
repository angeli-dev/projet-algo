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

    if (pos[0] == 'A')
    {
        nouveauJeton->x = 0;
    }
    else if (pos[0] == 'B')
    {
        nouveauJeton->x = 1;
    }
    else if (pos[0] == 'C')
    {
        nouveauJeton->x = 2;
    }
    else if (pos[0] == 'D')
    {
        nouveauJeton->x = 3;
    }
    else if (pos[0] == 'E')
    {
        nouveauJeton->x = 4;
    }
    else if (pos[0] == 'F')
    {
        nouveauJeton->x = 5;
    }
    else if (pos[0] == 'G')
    {
        nouveauJeton->x = 6;
    }
    else if (pos[0] == 'H')
    {
        nouveauJeton->x = 7;
        == == == =
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
        == == == =
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

        //création du jeton
        Jeton *nouveauJeton = initJeton(Board, joueurActif, posY, posX);

        //retourne le nouveau jeton
        return nouveauJeton;
    }

    void captureJetons(Jeton * Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
    {
        captureDroite(Board, joueurActif, joueurPassif, nouveauJeton);
        captureGauche(Board, joueurActif, joueurPassif, nouveauJeton);
        captureHaut(Board, joueurActif, joueurPassif, nouveauJeton);
    }

    void captureDroite(Jeton * Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
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

    void captureGauche(Jeton * Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
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

    void captureHaut(Jeton * Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton nouveauJeton)
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