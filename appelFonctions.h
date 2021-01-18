//affichage tableau, plateau
void displayBoard(Jeton *Board[8][8]);

//initialisation des joueurs, jetons
void initJoueur(Jeu *jeu, Joueur *j1, Joueur *j2);
Jeton *initJeton(Jeton *Board[8][8], Joueur joueurActif, int posY, int posX);

//partie
Jeton *nouveauJeton(Jeton *Board[8][8], Joueur joueurActif);

//fonctions capture
void captureJetons(Jeton *Board[8][8], Joueur joueurActif, Joueur Passif, Jeton nouveauJeton);
void captureDroite(Jeton *Board[8][8], Joueur joueurActif, Joueur Passif, Jeton nouveauJeton);
void captureGauche(Jeton *Board[8][8], Joueur joueurActif, Joueur Passif, Jeton nouveauJeton);
void captureHaut(Jeton *Board[8][8], Joueur joueurActif, Joueur Passif, Jeton nouveauJeton);
void captureBas(Jeton *Board[8][8], Joueur joueurActif, Joueur Passif, Jeton nouveauJeton);