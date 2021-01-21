//affichage tableau, plateau
void initBoard(Jeton *Board[8][8], Joueur j1, Joueur j2);

//initialisation tableau, plateau
void displayBoard(Jeton *Board[8][8]);

//initialisation des joueurs, jetons
void initJoueur(Jeu *jeu);
Jeton *initJeton(Jeton *Board[8][8], Joueur joueurActif, int posY, int posX);

//partie
Jeton *nouveauJeton(Jeton *Board[8][8], Joueur *joueurActif, Jeton *tableauJouables[30]);
void nouveauTour(Jeton *Board[8][8], Joueur *joueurActif, Joueur joueurPassif);
void joueurSuivant(Joueur *j1, Joueur *j2);
void casesJouables(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton *tableauJouables[30]);
char colonneLettre(int n);
int tailleTableau(Jeton *tableauJouables[30]);
void coordJeton(int *posX, int *posY);

//fonctions test
int testDroite(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);
int testGauche(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);
int testHaut(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);
int testBas(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);
int testDiagonaleDB(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);
int testDiagonaleGB(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);
int testDiagonaleDH(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);
int testDiagonaleGH(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);
void testReussi(int posX, int posY, Jeton *tableauJouables[30]);
int testJeton(int posX, int posY, Jeton *tableauJouables[30]);

//fonctions capture
void captureJetons(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton);
void captureDroite(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton);
void captureGauche(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton);
void captureHaut(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton);
void captureBas(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton);
void captureDiagonaleDH(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton);
void captureDiagonaleDB(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton);
void captureDiagonaleGH(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton);
void captureDiagonaleGB(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif, Jeton nouveauJeton);

//Fin du jeu
int finPartie(Joueur j1, Joueur j2);
void resultatsJeu(Joueur j1, Joueur j2);
