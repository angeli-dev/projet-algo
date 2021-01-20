typedef struct Jeton
{
    char color[1];
    int x;
    int y;
} jeton;

typedef struct Joueur
{
    char name[20];
    char color[1];
    int nbJetons;
} joueur;

typedef struct Jeu
{
    Joueur j1;
    Joueur j2;
    Jeton *Board[8][8];
} jeu;