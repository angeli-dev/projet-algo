#include <iostream>
using namespace std;

void displayBoard(char Board[8][8]);

int main() {
    char Board[8][8];
    int i(0),j(0);
    for(i=0;i<8;i++) 
    { 
        for(j=0;j<8;j++) 
        Board[i][j]=' '; 
    } 
    displayBoard(Board);

}
void displayBoard(char Board[8][8]){
    cout << "     A   B   C   D   E   F   G   H" << endl;
    for (int row = 0; row < 8; row++)
    {
        cout << "   +---+---+---+---+---+---+---+---+" << endl;
        cout << row+1 << "  | ";
        for (int col = 0; col < 8; col++)
        {
            cout << Board[row][col] << " | ";
        }
        cout << endl;
    }
    cout << "   +---+---+---+---+---+---+---+---+" << endl;
}