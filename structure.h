typedef struct Jeton
{
    char color[1];
    int x;
    int y;
} jeton;

typedef struct Joueur
{
    char name[20];
    int nbJetons;
} joueur;

typedef struct Jeu
{
    Joueur j1;
    Joueur j2;
    char Board[8][8];
} jeu;