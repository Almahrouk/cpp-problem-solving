/*
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int k = 1; // Initialize the count of unique elements to 1
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Overwrite the next unique element
                k++;
            }
        }

        return k;
    }
};