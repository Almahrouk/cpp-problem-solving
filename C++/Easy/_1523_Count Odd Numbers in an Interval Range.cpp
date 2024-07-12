
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
            if(i%2 == 1){
                count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int countOdds(int l, int h) {
        return ((h + 1) / 2) - (l / 2);
    }
};

/*


Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].

*/