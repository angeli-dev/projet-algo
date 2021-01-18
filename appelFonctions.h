void displayBoard(char Board[8][8]);
void initJoueur(Jeu *jeu, Joueur *j1, Joueur *j2);
Jeton *initJeton(Jeton *Board[8][8], Joueur joueurActif, int posY, int posX);
Jeton *nouveauJeton(Jeton *Board[8][8], Joueur joueurActif);
void captureJetons(Jeton *Board[8][8], Joueur joueurActif, Joueur Passif, Jeton nouveauJeton);
void captureDroite(Jeton *Board[8][8], Joueur joueurActif, Joueur Passif, Jeton nouveauJeton);
void captureGauche(Jeton *Board[8][8], Joueur joueurActif, Joueur Passif, Jeton nouveauJeton);
void captureHaut(Jeton *Board[8][8], Joueur joueurActif, Joueur Passif, Jeton nouveauJeton);
