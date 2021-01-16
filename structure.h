struct Jeton
{
    char color;
    int x;
    int y;
};

struct Joueur
{
    char name[20];
    int nbJetons;
};

struct Jeu
{
    Joueur j1;
    Joueur j2;
    char Board[8][8];
};