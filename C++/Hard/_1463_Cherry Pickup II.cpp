// https://leetcode.com/problems/cherry-pickup-ii/description/?envType=daily-question&envId=2024-02-11

#include <vector>

using namespace std;
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];

        int ans = 0;
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) { // robotA
                for(int k = j+1; k < n; ++k) { // robotB
                    for(int x = -1; x <= 1; ++x) { // x and y all possible combinations
                        for(int y = -1; y <= 1; ++y) {
                            int nj = j + x, nk = k + y;
                            if(nj >= 0 && nj < n && nk >= 0 && nk < n) {
                                int prev = dp[i-1][nj][nk];
                                if(prev != -1) {
                                    dp[i][j][k] = max(dp[i][j][k], prev + grid[i][j] + (j != k ? grid[i][k] : 0));
                                }
                            }
                        }
                    }
                    if(ans < dp[i][j][k]) ans = dp[i][j][k];
                }
            }
        }

        return ans;
    }
};



/*

You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.


Example 1:


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
Example 2:


Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.



*/