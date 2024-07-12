#include <vector>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool zero = false;
        int negative = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                zero = true;
                break; // If there's a zero, the product will always be zero
            }
            else if(nums[i] < 0) {
                negative++;
            }
        }
        if(zero) {
            return 0; // If there's a zero in the array, product is always 0
        } else {
            return negative % 2 == 0 ? 1 : -1; // If the count of negative numbers is even, product is positive, otherwise negative
        }
    }
};
