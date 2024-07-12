// class Solution {
// public:
//         vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
//         string word;
//     int dfs(int x,int y,vector<vector<char>>& board,int pos)
//     {
//         if(pos==word.length()-1)
//         return 1;
//         char temp=board[x][y];
//     //mark the current cell visited
//         board[x][y]='#';
//     //For each of the adjacent cell, call the function recursively
//         for(auto u:v)
//         if(x+u.first>=0&&x+u.first<board.size()&&y+u.second>=0&&y+u.second<board[0].size())
//         {
//             int res=0;
//             if(board[x+u.first][y+u.second]==word[pos+1])
//             res=dfs(x+u.first,y+u.second,board,pos+1);
//         //return true if a word match is found in one of the neighbours
//             if(res==1)
//             return 1;
//         }
//     //mark the current cell unvisited
//         board[x][y]=temp;
//         return 0;
//     }

//     bool exist(vector<vector<char>>& board, string word1) {
//         word=word1;
//         vector<int> v(board[0].size(),0);
//         for(int i=0;i<board.size();i++)
//         {
//             for(int j=0;j<board[0].size();j++)
//             {
//                 if(board[i][j]==word[0]&&dfs(i,j,board,0))
//                 return 1;
//             }
//         }
//         return 0;
//     }
// };
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;
        if (board.empty() || board[0].empty())
            return false;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int index,
             int row, int col) {
        if (index == word.length())
            return true;
        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() || board[row][col] != word[index])
            return false;

        char temp = board[row][col];
        board[row][col] = '#'; // Mark as visited

        bool found = dfs(board, word, index + 1, row + 1, col) ||
                     dfs(board, word, index + 1, row - 1, col) ||
                     dfs(board, word, index + 1, row, col + 1) ||
                     dfs(board, word, index + 1, row, col - 1);

        board[row][col] = temp; // Restore the original character
        return found;
    }
};