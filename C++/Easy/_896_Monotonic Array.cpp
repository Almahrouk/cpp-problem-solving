
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                decreasing = false; // If we find an increasing element, it's not decreasing
            }
            if(nums[i] < nums[i - 1]) {
                increasing = false; // If we find a decreasing element, it's not increasing
            }
        }

        return increasing || decreasing; // If either increasing or decreasing is true, it's monotonic
    }
};



/*


Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false

*/