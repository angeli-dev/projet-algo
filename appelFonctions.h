/*
Paramètres d'entrées : Tableau de jeu, Joueur 1 , Joueur 2
But : Initialise les cases du tableau à null et place les pions de départ des joueurs 
*/
void initBoard(Jeton *Board[8][8], Joueur j1, Joueur j2);

/*
Paramètres d'entrées : Tableau de jeu
But : Affiche le tableau de jeu 
*/
void displayBoard(Jeton *Board[8][8]);

/*
Paramètres d'entrées : Jeu
But : Initialise les joueurs en demandant le nom et la couleur qu'ils veulent. Initialise le nombre de jetons
*/
void initJoueur(Jeu *jeu);

/*
Paramètres d'entrées : Tableau de jeu, Joueur concerné, Coordonnée X et Coordonnée Y
But : Initialise un jeton avec les coordonnées passées et la couleur du joueur
Sortie : Jeton
*/
Jeton *initJeton(Jeton *Board[8][8], Joueur joueurActif, int posY, int posX);

/*
Paramètres d'entrées : Tableau de jeu, Joueur concerné, Joueur secondaire
But : Crée un tableau de cases jouables, regarde si tour possible, crée un jeton, fait la capture et affiche le tableau de jeu avec les changements
*/
void nouveauTour(Jeton *Board[8][8], Joueur *joueurActif, Joueur *joueurPassif);

/*
Paramètres d'entrées : Tableau de jeu, Joueur concerné, Tableau des cases jouables
But : Créer un nouveux jeton pour le joueur
Sortie : Jeton
*/
Jeton *nouveauJeton(Jeton *Board[8][8], Joueur *joueurActif, Jeton *tableauJouables[30]);

/*
Paramètres d'entrées : Joueur 1 , Joueur 2
But : Changer de joueur actif
*/
void joueurSuivant(Joueur *j1, Joueur *j2);

/*
Paramètres d'entrées : Tableau de jeu, Joueur concerné, Joueur secondaire, Tableau de cases jouables
But : Trouve les cases jouables par le joueur concerné
*/
void casesJouables(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, Jeton *tableauJouables[30]);

/*
Paramètres d'entrées : Entier n
But : Transforme le numéro de la colonne passé en paramètre en lettre
Sortie : Lettre de la colonne
*/
char colonneLettre(int n);

/*
Paramètres d'entrées : Tableau des cases jouables
But : Trouver le nombre de cases jouables
Sortie : Taille du tableau
*/
int tailleTableau(Jeton *tableauJouables[30]);

/*
Paramètres d'entrées : Position X, Position Y
But : Récupérer les coordonnées du nouveau jeton
*/
void coordJeton(int *posX, int *posY);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Position X, Position Y
But : Tester si des pions sont capturables à droite
Sortie : 0 Capture de pions impossible | 1 Capture de pions possible
*/
int testDroite(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Position X, Position Y
But : Tester si des pions sont capturables à gauche
Sortie : 0 Capture de pions impossible | 1 Capture de pions possible
*/
int testGauche(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Position X, Position Y
But : Tester si des pions sont capturables en haut
Sortie : 0 Capture de pions impossible | 1 Capture de pions possible
*/
int testHaut(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Position X, Position Y
But : Tester si des pions sont capturables en bas
Sortie : 0 Capture de pions impossible | 1 Capture de pions possible
*/
int testBas(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Position X, Position Y
But : Tester si des pions sont capturables en diagonale droite en bas
Sortie : 0 Capture de pions impossible | 1 Capture de pions possible
*/
int testDiagonaleDB(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Position X, Position Y
But : Tester si des pions sont capturables en diagonale gauche en bas
Sortie : 0 Capture de pions impossible | 1 Capture de pions possible
*/
int testDiagonaleGB(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Position X, Position Y
But : Tester si des pions sont capturables en diagonale droite en haut
Sortie : 0 Capture de pions impossible | 1 Capture de pions possible
*/
int testDiagonaleDH(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Position X, Position Y
But : Tester si des pions sont capturables en diagonale gauche en haut
Sortie : 0 Capture de pions impossible | 1 Capture de pions possible
*/
int testDiagonaleGH(Jeton *Board[8][8], Joueur joueurActif, Joueur joueurPassif, int posY, int posX);

/*
Paramètres d'entrées : Position X, Position Y, Tableau de cases jouables
But : Stocke la case jouable dans le tableau
*/
void testReussi(int posX, int posY, Jeton *tableauJouables[30]);

/*
Paramètres d'entrées : Position X, Position Y, Tableau de cases jouables
But : Tester si le jeton est jouable
Sortie : 0 Jeton non jouable | 1 Jeton jouable
*/
int testJeton(int posX, int posY, Jeton *tableauJouables[30]);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Jeton
But : Capturer les jetons du joueur passif
*/
void captureJetons(Jeton *Board[8][8], Joueur *joueurActif, Joueur *Passif, Jeton nouveauJeton);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Jeton
But : Capturer les jetons du joueur passif situés à droite
*/
void captureDroite(Jeton *Board[8][8], Joueur *joueurActif, Joueur *Passif, Jeton nouveauJeton);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Jeton
But : Capturer les jetons du joueur passif situés à gauche
*/
void captureGauche(Jeton *Board[8][8], Joueur *joueurActif, Joueur *Passif, Jeton nouveauJeton);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Jeton
But : Capturer les jetons du joueur passif situés en haut
*/
void captureHaut(Jeton *Board[8][8], Joueur *joueurActif, Joueur *Passif, Jeton nouveauJeton);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Jeton
But : Capturer les jetons du joueur passif situés en bas
*/
void captureBas(Jeton *Board[8][8], Joueur *joueurActif, Joueur *Passif, Jeton nouveauJeton);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Jeton
But : Capturer les jetons du joueur passif situé en diagonale droite en haut
*/
void captureDiagonaleDH(Jeton *Board[8][8], Joueur *joueurActif, Joueur *Passif, Jeton nouveauJeton);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Jeton
But : Capturer les jetons du joueur passif situé en diagonale droite en bas
*/
void captureDiagonaleDB(Jeton *Board[8][8], Joueur *joueurActif, Joueur *Passif, Jeton nouveauJeton);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Jeton
But : Capturer les jetons du joueur passif situé en diagonale gauche en haut
*/
void captureDiagonaleGH(Jeton *Board[8][8], Joueur *joueurActif, Joueur *Passif, Jeton nouveauJeton);

/*
Paramètres d'entrées : Tableau de jeu, Joueur Actif, Joueur Passif, Jeton
But : Capturer les jetons du joueur passif situé en diagonale gauche en haut
*/
void captureDiagonaleGB(Jeton *Board[8][8], Joueur *joueurActif, Joueur *Passif, Jeton nouveauJeton);

/*
Paramètres d'entrées : Tableau de jeu, Joueur 1, Joueur 2
But : Vérifiez si la partie est terminée
Sortie : 0 Partie terminée | 1 Partie non terminée
*/
int finPartie(Jeton *Board[8][8], Joueur j1, Joueur j2);

/*
Paramètres d'entrées : Joueur 1, Joueur 2
But : Afficher le résultat de la partie
*/
void resultatsJeu(Joueur j1, Joueur j2);