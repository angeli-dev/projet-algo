typedef struct Jeton {
    char color;
    int x;
    int y;
};

typedef struct Joueur {
    char name[20];
    int nbJetons;
};

typedef struct Jeu {
    Joueur j1;
    Joueur j2;
};