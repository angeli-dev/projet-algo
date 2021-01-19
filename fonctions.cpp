#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
#include <cstring>
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

void initJoueur(Jeu *jeu)
{
    Joueur *jou1 = (Joueur *)malloc(sizeof(*jou1));
    Joueur *jou2 = (Joueur *)malloc(sizeof(*jou2));
    while (1)
    {
        cout << "Quel est le nom du premier joueur : ";
        cin >> jou1->name;
        cout << jou1->name;
        cout << "Quel est le nom du second joueur : ";
        cin >> jou2->name;
        int verif = strcmp(jou1->name, jou2->name);
        if (!verif)
        {
            cout << "Les deux noms sont identiques. Veuillez en prendre des différents." << endl;
        }
        else
        {
            break;
        }
    }

    //Initialisation du nombre de jetons
    jou1->nbJetons = 2;
    jou2->nbJetons = 2;

    //Initialisation de la couleur et vérification que les deux sont bien différentes
    while (1)
    {
        cout << "Joueur 1 choisisez votre couleur : ";
        cin >> jou1->color;
        cout << "Joueur 2 choisisez votre couleur : ";
        cin >> jou2->color;
        if (jou1->color[0] == jou2->color[0])
        {
            cout << "Les deux couleurs sont identiques. Veuillez en prendre des différentes." << endl;
        }
        else
        {
            break;
        }
    }
    (jeu)->j1 = *jou1;
    (jeu)->j2 = *jou2;
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

void nouveauTour(Jeton *Board[8][8], Joueur *joueurActif, Joueur joueurPassif)
{
    casesJouables(Board, *joueurActif, joueurPassif);
    Jeton *jeton = nouveauJeton(Board, joueurActif);
    cout << "coucou " << (joueurActif)->name << " de jouer" << endl;
    //capture
    captureJetons(Board, *joueurActif, joueurPassif, *jeton);
    displayBoard(Board);
}

Jeton *nouveauJeton(Jeton *Board[8][8], Joueur *joueurActif)
{
    char pos[2];
    int posX, posY;

    //Anonce du joueur
    cout << "C'est au tour de " << (joueurActif)->name << " de jouer" << endl;
    cout << "Nombre de jetons : " << (joueurActif)->nbJetons << endl;
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
    (joueurActif)->nbJetons += 1;
    return initJeton(Board, *joueurActif, posY, posX);
}

void casesJouables(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif)
{
    cout << "-----------------------------------------------------------" << endl;
    cout << "Cases jouables : ";
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (Board[row][col] == NULL) // la case est libre
            {
                /*---TEST POUR UNE CAPTURE A DROITE--*/
                if (Board[row][col + 1] && col < 7) //vérifie si la case à droite a un jeton et fait partie du tablau
                {
                    if (testDroite(Board, joueurActif, joueurPassif, row, col + 1) == 1)
                    {
                        cout << colonneLettre(col) << row + 1 << " ";
                    }
                }
                /*---TEST POUR UNE CAPTURE A GAUCHE--*/
                if (Board[row][col - 1] && col > 0)
                {
                    if (testGauche(Board, joueurActif, joueurPassif, row, col - 1) == 1)
                    {
                        cout << colonneLettre(col) << row + 1 << " ";
                    }
                }
                /*---TEST POUR UNE CAPTURE EN BAS--*/
                if (Board[row + 1][col] && row < 7)
                {
                    if (testBas(Board, joueurActif, joueurPassif, row + 1, col) == 1)
                    {
                        cout << colonneLettre(col) << row + 1 << " ";
                    }
                }
                /*---TEST POUR UNE CAPTURE EN HAUT--*/
                if (Board[row - 1][col] && row > 0)
                {
                    if (testHaut(Board, joueurActif, joueurPassif, row - 1, col) == 1)
                    {
                        cout << colonneLettre(col) << row + 1 << " ";
                    }
                }
                /*---TEST POUR UNE CAPTURE EN DIAGONALE DROITE HAUT--*/
                if (Board[row - 1][col + 1] && row > 0 && col < 7)
                {
                    if (testDiagonaleDH(Board, joueurActif, joueurPassif, row - 1, col + 1) == 1)
                    {
                        cout << colonneLettre(col) << row + 1 << " ";
                    }
                }
                /*---TEST POUR UNE CAPTURE EN DIAGONALE GAUCHE HAUT--*/
                if (Board[row - 1][col - 1] && row > 0 && col > 0)
                {
                    if (testDiagonaleGH(Board, joueurActif, joueurPassif, row - 1, col - 1) == 1)
                    {
                        cout << colonneLettre(col) << row + 1 << " ";
                    }
                }
                /*---TEST POUR UNE CAPTURE EN DIAGONALE GAUCHE BAS--*/
                if (Board[row + 1][col - 1] && row < 7 && col > 0)
                {
                    if (testDiagonaleGB(Board, joueurActif, joueurPassif, row + 1, col - 1) == 1)
                    {
                        cout << colonneLettre(col) << row + 1 << " ";
                    }
                }
                /*---TEST POUR UNE CAPTURE EN DIAGONALE DROITE BAS--*/
                if (Board[row + 1][col + 1] && row < 7 && col < 7)
                {
                    if (testDiagonaleDB(Board, joueurActif, joueurPassif, row + 1, col + 1) == 1)
                    {
                        cout << colonneLettre(col) << row + 1 << " ";
                    }
                }
            }
        }
    }
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
}

char colonneLettre(int n)
{
    char lettre[1];
    if (n == 0)
    {
        lettre[0] = 'A';
    }
    else if (n == 1)
    {
        lettre[0] = 'B';
    }
    else if (n == 2)
    {
        lettre[0] = 'C';
    }
    else if (n == 3)
    {
        lettre[0] = 'D';
    }
    else if (n == 4)
    {
        lettre[0] = 'E';
    }
    else if (n == 5)
    {
        lettre[0] = 'F';
    }
    else if (n == 6)
    {
        lettre[0] = 'G';
    }
    else if (n == 7)
    {
        lettre[0] = 'H';
    }
    return *lettre;
}

int testDroite(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX)
{
    int nbJetonsACapturer = 0;

    while (Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
    {
        nbJetonsACapturer += 1;

        posX += 1;
        if (Board[posY][posX] == NULL)
        {
            nbJetonsACapturer = 0;
            return 0;
        };
        if (Board[posY][posX]->color[0] == (&joueurActif)->color[0])
        {
            return 1;
        };
    }
    return 0;
}

int testGauche(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX)
{
    int nbJetonsACapturer = 0;

    while (Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
    {
        nbJetonsACapturer += 1;
        posX -= 1;
        if (Board[posY][posX] == NULL)
        {
            nbJetonsACapturer = 0;
            return 0;
        };
        if (Board[posY][posX]->color[0] == (&joueurActif)->color[0])
        {
            return 1;
        };
    }
    return 0;
}

int testBas(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX)
{
    int nbJetonsACapturer = 0;

    while (Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
    {
        nbJetonsACapturer += 1;
        posY += 1;
        if (Board[posY][posX] == NULL)
        {
            nbJetonsACapturer = 0;
            return 0;
        };
        if (Board[posY][posX]->color[0] == (&joueurActif)->color[0])
        {
            return 1;
        };
    }
    return 0;
}
int testHaut(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX)
{
    int nbJetonsACapturer = 0;

    while (Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
    {
        nbJetonsACapturer += 1;
        posY -= 1;
        if (Board[posY][posX] == NULL)
        {
            nbJetonsACapturer = 0;
            return 0;
        };
        if (Board[posY][posX]->color[0] == (&joueurActif)->color[0])
        {
            return 1;
        };
    }
    return 0;
}
int testDiagonaleDH(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX)
{
    int nbJetonsACapturer = 0;

    while (Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
    {
        nbJetonsACapturer += 1;
        posX += 1;
        posY -= 1;
        if (Board[posY][posX] == NULL)
        {
            nbJetonsACapturer = 0;
            return 0;
        };
        if (Board[posY][posX]->color[0] == (&joueurActif)->color[0])
        {
            return 1;
        };
    }
    return 0;
}
int testDiagonaleGH(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX)
{
    int nbJetonsACapturer = 0;

    while (Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
    {
        nbJetonsACapturer += 1;
        posY -= 1;
        posX -= 1;
        if (Board[posY][posX] == NULL)
        {
            nbJetonsACapturer = 0;
            return 0;
        };
        if (Board[posY][posX]->color[0] == (&joueurActif)->color[0])
        {
            return 1;
        };
    }
    return 0;
}
int testDiagonaleGB(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX)
{
    int nbJetonsACapturer = 0;

    while (Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
    {
        nbJetonsACapturer += 1;
        posY += 1;
        posX -= 1;
        if (Board[posY][posX] == NULL)
        {
            nbJetonsACapturer = 0;
            return 0;
        };
        if (Board[posY][posX]->color[0] == (&joueurActif)->color[0])
        {
            return 1;
        };
    }
    return 0;
}
int testDiagonaleDB(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX)
{
    int nbJetonsACapturer = 0;

    while (Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
    {
        nbJetonsACapturer += 1;
        posY += 1;
        posX += 1;
        if (Board[posY][posX] == NULL)
        {
            nbJetonsACapturer = 0;
            return 0;
        };
        if (Board[posY][posX]->color[0] == (&joueurActif)->color[0])
        {
            return 1;
        };
    }
    return 0;
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
int finPartie(Joueur j1, Joueur j2)
{
    if (j1.nbJetons == 0 || j2.nbJetons == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
