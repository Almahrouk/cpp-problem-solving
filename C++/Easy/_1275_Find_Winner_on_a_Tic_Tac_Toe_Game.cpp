
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Lines[8][3]={
            {0, 1, 2},{3, 4, 5},{6, 7, 8},
            {0, 3, 6},{1, 4, 7},{2, 5, 8},
            {0, 4, 8},{2, 4, 6}};
    char Board[10]="012345678";
    int check_win(){
        for(int* l: Lines){
            int x0=(Board[l[0]]=='X')?1:(Board[l[0]]=='O')?2:0;
            int x1=(Board[l[1]]=='X')?1:(Board[l[1]]=='O')?2:0;
            int x2=(Board[l[2]]=='X')?1:(Board[l[2]]=='O')?2:0;
            int result=x0*x1+x1*x2+x2*x1;
            if (result==3) return 1;
            else if (result==12) return 2;
        }
        return 0;
    }
    void print(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout<<Board[3*i+j];
            }
            cout<<endl;
        }
        cout<<"=====\n";
    }
    string tictactoe(vector<vector<int>>& moves) {
        int n=moves.size();
        for(int i=0; i<n; i++){
            int idx=3*moves[i][0]+moves[i][1];
            if (i&1) Board[idx]='O';
            else Board[idx]='X';
        }
        if (check_win()==1) return "A";
        else if (check_win()==2) return "B";
        if (n==9) return "Draw";
        else return "Pending";
    }
};

int main() {
    Solution game;
    vector<vector<int>> moves1 = {{0, 0}, {1, 1}, {0, 1}, {1, 0}, {2, 2}};
    vector<vector<int>> moves2 = {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
    vector<vector<int>> moves3 = {{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}};
    vector<vector<int>> moves4 = {{0, 0}, {1, 1}, {2, 0}, {1, 0}, {1, 2}, {2, 1}, {0, 1}, {0, 2}, {2, 2}};


    cout << "Game result: " << game.tictactoe(moves1) << endl;
    cout << "Game result: " << game.tictactoe(moves2) << endl;
    cout << "Game result: " << game.tictactoe(moves3) << endl;
    cout << "Game result: " << game.tictactoe(moves4) << endl;

    return 0;
}

/*
X12
3X5
OOX
=====
"A"

-------
XXO
XO5
O78
=====
"B"

-------
XXO
OOX
XOX
=====
"Draw"
*/


/*

Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

Players take turns placing characters into empty squares ' '.
The first player A always places 'X' characters, while the second player B always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never on filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.



Example 1:


Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
Example 2:


Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.
Example 3:


Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.

*/