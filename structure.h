typedef struct Jeton {
    char color;
    int x;
    int y;
} jeton;

typedef struct Joueur {
    char name[20];
    int nbJetons;
} joueur;

typedef struct Jeu {
    Joueur j1;
    Joueur j2;
} jeu;