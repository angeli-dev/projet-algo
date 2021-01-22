#include <iostream>
#include <cstdio>
#include <cstring>
//#include <string.h>
using namespace std;

#include "structure.h"
#include "appelFonctions.h"

//initialise le plateau de jeu
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

//affiche le plateau de jeu
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

//initialise les joueurs du jeu
void initJoueur(Jeu *jeu)
{
    Joueur *jou1 = (Joueur *)malloc(sizeof(*jou1));
    Joueur *jou2 = (Joueur *)malloc(sizeof(*jou2));
    while (1)
    {
        cout << "Quel est le nom du premier joueur : ";
        cin >> jou1->name;
        cout
            << "Quel est le nom du second joueur : ";
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

//initaialise un jeton et le place sur la grille
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

//effectue un tour de jeu
void nouveauTour(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif)
{
    //créé un tableau de cases jouables
    Jeton *tableau[30];
    for (int i = 0; i < 30; i++)
    {
        tableau[i] = NULL;
    }

    //remplit le tableau
    casesJouables(Board, *joueurActif, *joueurPassif, tableau);

    if (tailleTableau(tableau) == 0) //si le tableau est vide, pas de cases jouables
    {
        cout << "aucune" << endl;
        cout << "Tu passes ton tour" << endl;
        //fin du tour, passe au joueur suivant
    }
    else //il y a des cases jouables
    {
        //place le nouveau jeton
        Jeton *jeton = nouveauJeton(Board, joueurActif, tableau);

        //capture les jetons
        captureJetons(Board, joueurActif, joueurPassif, *jeton);
        displayBoard(Board);
    }
}

//définit le joueur actuel
void joueurSuivant(Joueur *j1, Joueur *j2)
{
    Joueur temps = *j1;
    *j1 = *j2;
    *j2 = temps;
}

//récupère les coordonnées du nouveau jeton et les vérifie (s'il s'agit bien d'une case jouable)
Jeton *nouveauJeton(Jeton *Board[8][8], Joueur *joueurActif, Jeton *tableauJouables[30])
{

    int posX = -1;
    int posY = -1;

    //Anonce du joueur
    cout << "C'est au tour de " << (joueurActif)->name << " de jouer" << endl;
    cout << "Nombre de jetons : " << (joueurActif)->nbJetons << endl;

    /*----------TEST VALIDITE JETON--------------------------------*/
    int validite = 0;
    while (validite == 0) //tant que le jeton n'est pas jouable
    {
        //demande et récupère les coordonnées du jeton
        coordJeton(&posX, &posY);
        validite = testJeton(posX, posY, tableauJouables);
    }

    //ajoute un jeton supplémentaire au nombre de jeton du joueur actif
    (joueurActif)->nbJetons += 1;

    //place le jeton dans le tableau
    return initJeton(Board, *joueurActif, posY, posX);
}

void coordJeton(int *posX, int *posY)
{
    char pos[2];

    //demande placement jeton
    cout << "Ou voulez vous placez votre jeton : (Ex: B4, G2...) ";
    cin >> pos;

    //Position X
    if (pos[0] == 'A' || pos[0] == 'a')
    {
        *posX = 0;
    }
    else if (pos[0] == 'B' || pos[0] == 'b')
    {
        *posX = 1;
    }
    else if (pos[0] == 'C' || pos[0] == 'c')
    {
        *posX = 2;
    }
    else if (pos[0] == 'D' || pos[0] == 'd')
    {
        *posX = 3;
    }
    else if (pos[0] == 'E' || pos[0] == 'e')
    {
        *posX = 4;
    }
    else if (pos[0] == 'F' || pos[0] == 'f')
    {
        *posX = 5;
    }
    else if (pos[0] == 'G' || pos[0] == 'g')
    {
        *posX = 6;
    }
    else if (pos[0] == 'H' || pos[0] == 'h')
    {
        *posX = 7;
    }

    //Position Y
    if (pos[1] == '1')
    {
        *posY = 0;
    }
    else if (pos[1] == '2')
    {
        *posY = 1;
    }
    else if (pos[1] == '3')
    {
        *posY = 2;
    }
    else if (pos[1] == '4')
    {
        *posY = 3;
    }
    else if (pos[1] == '5')
    {
        *posY = 4;
    }
    else if (pos[1] == '6')
    {
        *posY = 5;
    }
    else if (pos[1] == '7')
    {
        *posY = 6;
    }
    else if (pos[1] == '8')
    {
        *posY = 7;
    }
}

//test si le jeton est jouable
int testJeton(int posX, int posY, Jeton *tableauJouables[30])
{
    int n = 0;
    while (tableauJouables[n])
    {
        if (tableauJouables[n]->x == posX && tableauJouables[n]->y == posY)
        {
            //le jeton est jouable
            return 1;
        }
        n++;
    }
    //le jeton n'est pas jouable
    return 0;
}

//stocke la case jouable dans un tableau
void testReussi(int posX, int posY, Jeton *tableauJouables[30])
{
    int i = 0;
    int presence = 0;
    while (tableauJouables[i])
    {
        if (tableauJouables[i]->x == posX && tableauJouables[i]->y == posY)
        {
            //la case est déjà dans le tableau
            presence = 1;
        }
        i++;
    }
    if (presence == 0)
    //la case n'est pas déjà dans le tableau
    {
        //pointe la dernière case du tableau
        int n = 0;
        n = tailleTableau(tableauJouables);

        //affiche la case jouable
        cout << colonneLettre(posX) << posY + 1 << " ";

        //créé un jeton identique à celui que pourrait jouer le joueur
        Jeton *nouveauJeton = (Jeton *)malloc(sizeof(*nouveauJeton));
        nouveauJeton->x = posX;
        nouveauJeton->y = posY;

        //met la case jouable dans le tableau
        tableauJouables[n] = nouveauJeton;
    }
}

/*--------------------------PARCOURS LES CASES DU TABLEAU ET DETERMINE SI ELLE CAPTURE SONT JOUABLES----------------------------------*/

void casesJouables(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton *tableauJouables[60])
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
                if (Board[row][col + 1] && col < 6) //vérifie si la case à droite a un jeton et fait partie du tablau
                {
                    //cout << col << row;
                    //cout << "testd" << endl;

                    if (testDroite(Board, joueurActif, joueurPassif, row, col + 1) == 1)
                    {
                        testReussi(col, row, tableauJouables);
                    }
                }
                /*---TEST POUR UNE CAPTURE A GAUCHE--*/
                if (Board[row][col - 1] && col > 1)
                {
                    //cout << "testg" << endl;
                    if (testGauche(Board, joueurActif, joueurPassif, row, col - 1) == 1)
                    {
                        testReussi(col, row, tableauJouables);
                    }
                }
                /*---TEST POUR UNE CAPTURE EN BAS--*/
                if (Board[row + 1][col] && row < 6)
                {
                    //cout << "testb" << endl;
                    if (testBas(Board, joueurActif, joueurPassif, row + 1, col) == 1)
                    {
                        testReussi(col, row, tableauJouables);
                    }
                }
                /*---TEST POUR UNE CAPTURE EN HAUT--*/
                if (Board[row - 1][col] && row > 1)
                {
                    //cout << "testh" << endl;
                    if (testHaut(Board, joueurActif, joueurPassif, row - 1, col) == 1)
                    {
                        testReussi(col, row, tableauJouables);
                    }
                }
                /*---TEST POUR UNE CAPTURE EN DIAGONALE DROITE HAUT--*/
                if (Board[row - 1][col + 1] && row > 1 && col < 6)
                {
                    //cout << "testdh" << endl;
                    if (testDiagonaleDH(Board, joueurActif, joueurPassif, row - 1, col + 1) == 1)
                    {
                        testReussi(col, row, tableauJouables);
                    }
                }

                /*---TEST POUR UNE CAPTURE EN DIAGONALE GAUCHE HAUT--*/
                if (Board[row - 1][col - 1] && row > 1 && col > 1)
                {
                    //cout << "testgh" << endl;
                    if (testDiagonaleGH(Board, joueurActif, joueurPassif, row - 1, col - 1) == 1)
                    {
                        testReussi(col, row, tableauJouables);
                    }
                }
                /*---TEST POUR UNE CAPTURE EN DIAGONALE GAUCHE BAS--*/
                if (Board[row + 1][col - 1] && row < 6 && col > 1)
                {
                    //cout << "testgb" << endl;
                    if (testDiagonaleGB(Board, joueurActif, joueurPassif, row + 1, col - 1) == 1)
                    {
                        testReussi(col, row, tableauJouables);
                    }
                }
                /*---TEST POUR UNE CAPTURE EN DIAGONALE DROITE BAS--*/
                if (Board[row + 1][col + 1] && row < 6 && col < 6)
                {
                    //cout << "testdb" << endl;
                    if (testDiagonaleDB(Board, joueurActif, joueurPassif, row + 1, col + 1) == 1)
                    {
                        testReussi(col, row, tableauJouables);
                    }
                }
            }
        }
    }

    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
}

//retourne la taille du tableau passé en paramètre
int tailleTableau(Jeton *tableauJouables[30])
{
    int taille = 0;
    int i = 0;
    while (tableauJouables[i] != NULL)
    {

        taille += 1;
        i++;
    }
    return taille;
}

//transforme le numéro de la colonne passé en paramètre en lettre
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

/*----------------------------------TEST CASES JOUABLES---------------------------------------------------*/

int testDroite(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX)
{
    int nbJetonsACapturer = 0;

    while (posX < 7 && Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
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

    while (posX > 0 && Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
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

    while (posY < 7 && Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
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

    while (posY > 0 && Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
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

    while (posX < 7 && posY > 0 && Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
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

    while (posX > 0 && posY > 0 && Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
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

    while (posY < 7 && posY > 0 && Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
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

    while (posX < 7 && posY < 7 && Board[posY][posX]->color[0] == (&joueurPassif)->color[0])
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

/*----------------------------------CAPTURE JETONS---------------------------------------------------*/

void captureJetons(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton)
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

void captureDroite(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton)
{
    //coordonées du pointeur de jeton
    //inialisé sur le jeton suivant
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;
    if (posX < 6)
    {
        posX += 1;
        while (posX < 6 && Board[posY][posX] && Board[posY][posX]->color[0] == (joueurPassif)->color[0])
        //à l'interieur du tableau ET sur case non vide ET avec un jeton adverse
        {
            nbJetonsACapturer += 1;
            posX += 1; //on teste le jeton suivant
        }

        //On doit vérifier que le pointeur n'a pas pu continuer la boucle while car il pointe un jeton adverse
        if (Board[posY][posX] && Board[posY][posX]->color[0] == (joueurActif)->color[0])
        //sur une case non vide ET avec un jeton du joueur actif -> condition de capture 2
        {
            for (int i = 0; i <= nbJetonsACapturer; i++)
            {
                Board[posY][posX]->color[0] = (joueurActif)->color[0];
                posX -= 1;
            }
        }
        // cout << nbJetonsACapturer << endl;
        (joueurActif)->nbJetons += nbJetonsACapturer;
        (joueurPassif)->nbJetons -= nbJetonsACapturer;
    }
}

void captureGauche(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;
    if (posX > 1)
    {
        posX -= 1;
        while (posX > 1 && Board[posY][posX] && Board[posY][posX]->color[0] == (joueurPassif)->color[0])
        {
            nbJetonsACapturer += 1;
            posX -= 1;
        }
        if (Board[posY][posX] && Board[posY][posX]->color[0] == (joueurActif)->color[0])
        {
            for (int i = 0; i <= nbJetonsACapturer; i++)
            {
                Board[posY][posX]->color[0] = (joueurActif)->color[0];
                posX += 1;
            }
            (joueurActif)->nbJetons += nbJetonsACapturer;
            (joueurPassif)->nbJetons -= nbJetonsACapturer;
        }
    }
}

void captureBas(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;
    if (posY < 6)
    {
        posY += 1;
        while (posY < 6 && Board[posY][posX] && Board[posY][posX]->color[0] == (joueurPassif)->color[0])
        {
            nbJetonsACapturer += 1;
            posY += 1;
        }
        if (Board[posY][posX] && Board[posY][posX]->color[0] == (joueurActif)->color[0])
        {
            for (int i = 0; i <= nbJetonsACapturer; i++)
            {
                Board[posY][posX]->color[0] = (joueurActif)->color[0];
                posY -= 1;
            }
            (joueurActif)->nbJetons += nbJetonsACapturer;
            (joueurPassif)->nbJetons -= nbJetonsACapturer;
        }
    }
}

void captureHaut(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton)
{
    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;
    if (posY > 1)
    {
        posY -= 1;
        while (posY > 1 && Board[posY][posX] && Board[posY][posX]->color[0] == (joueurPassif)->color[0])
        {
            nbJetonsACapturer += 1;
            posY -= 1;
        }
        if (Board[posY][posX] && Board[posY][posX]->color[0] == (joueurActif)->color[0])
        {
            for (int i = 0; i <= nbJetonsACapturer; i++)
            {
                Board[posY][posX]->color[0] = (joueurActif)->color[0];
                posY += 1;
            }
            (joueurActif)->nbJetons += nbJetonsACapturer;
            (joueurPassif)->nbJetons -= nbJetonsACapturer;
        }
    }
}

void captureDiagonaleDB(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton)
{

    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;
    if (posY < 6 && posX < 6)
    {
        posY += 1;
        posX += 1;
        while (posY < 6 && posX < 6 && Board[posY][posX] && Board[posY][posX]->color[0] == (joueurPassif)->color[0])
        {
            nbJetonsACapturer += 1;
            posX += 1;
            posY += 1;
        }
        if (Board[posY][posX] && Board[posY][posX]->color[0] == (joueurActif)->color[0])
        {
            cout << "db" << endl;
            for (int i = 0; i <= nbJetonsACapturer; i++)
            {
                Board[posY][posX]->color[0] = (joueurActif)->color[0];
                posX -= 1;
                posY -= 1;
            }
            (joueurActif)->nbJetons += nbJetonsACapturer;
            (joueurPassif)->nbJetons -= nbJetonsACapturer;
        }
    }
}
void captureDiagonaleDH(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton)
{

    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;
    if (posY > 1 && posX < 6)
    {
        posY -= 1;
        posX += 1;
        while (posY > 1 && posX < 6 && Board[posY][posX] && Board[posY][posX]->color[0] == (joueurPassif)->color[0])
        {
            nbJetonsACapturer += 1;
            posX += 1;
            posY -= 1;
        }
        if (Board[posY][posX] && Board[posY][posX]->color[0] == (joueurActif)->color[0])
        {
            cout << "dh" << endl;
            for (int i = 0; i <= nbJetonsACapturer; i++)
            {
                Board[posY][posX]->color[0] = (joueurActif)->color[0];
                posX -= 1;
                posY += 1;
            }
            (joueurActif)->nbJetons += nbJetonsACapturer;
            (joueurPassif)->nbJetons -= nbJetonsACapturer;
        }
    }
}
void captureDiagonaleGB(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton)
{

    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;
    if (posY < 6 && posX > 1)
    {
        posY += 1;
        posX -= 1;
        while (posY < 6 && posX > 1 && Board[posY][posX] && Board[posY][posX]->color[0] == (joueurPassif)->color[0])
        {
            nbJetonsACapturer += 1;
            posX -= 1;
            posY += 1;
        }
        if (Board[posY][posX] && Board[posY][posX]->color[0] == (joueurActif)->color[0])
        {
            cout << "gb" << endl;
            for (int i = 0; i <= nbJetonsACapturer; i++)
            {
                Board[posY][posX]->color[0] = (joueurActif)->color[0];
                posX += 1;
                posY -= 1;
            }
            (joueurActif)->nbJetons += nbJetonsACapturer;
            (joueurPassif)->nbJetons -= nbJetonsACapturer;
        }
    }
}
void captureDiagonaleGH(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton)
{

    int posY = (&nouveauJeton)->y;
    int posX = (&nouveauJeton)->x;
    int nbJetonsACapturer = 0;
    if (posX > 1 && posY > 1)
    {
        posY -= 1;
        posX -= 1;
        while (posX > 1 && posY > 1 && Board[posY][posX] && Board[posY][posX]->color[0] == (joueurPassif)->color[0])
        {
            nbJetonsACapturer += 1;
            posX -= 1;
            posY -= 1;
        }
        if (Board[posY][posX] && Board[posY][posX]->color[0] == (joueurActif)->color[0])
        {
            cout << "gh" << endl;
            for (int i = 0; i <= nbJetonsACapturer; i++)
            {
                Board[posY][posX]->color[0] = (joueurActif)->color[0];
                posX += 1;
                posY += 1;
            }
            (joueurActif)->nbJetons += nbJetonsACapturer;
            (joueurPassif)->nbJetons -= nbJetonsACapturer;
        }
    }
}

/*----------------------------------FIN PARTIE---------------------------------------------------*/

int finPartie(Joueur j1, Joueur j2)
{
    if (j1.nbJetons == 0 || j2.nbJetons == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void resultatsJeu(Joueur j1, Joueur j2)
{
    if (j1.nbJetons > j2.nbJetons)
    {
        cout << j1.name << " a gagne la partie ! " << endl;
    }
    else if (j1.nbJetons < j2.nbJetons)
    {
        cout << j2.name << " a gagne la partie ! " << endl;
    }
    else
    {
        cout << "Egalite entre les deux joueurs ! " << endl;
    }
}
