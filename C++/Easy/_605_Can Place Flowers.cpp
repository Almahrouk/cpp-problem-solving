#include <vector>
#include <iostream>
using namespace std;

class Solution { // No
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int max=0;
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i+2] == 0){
                max++;
            }
        }
        return max >= n ? true : false;
    }
};



#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int max = 0;
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                if ((i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)) {
                    max++;
                    flowerbed[i] = 1; // Mark the place where a flower is planted
                }
            }
        }

        return max >= n;
    }
};

/*

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
*/