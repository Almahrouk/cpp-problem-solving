#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if (target == matrix[i][j]) return true;
            }
        }
        return false;
    }
};