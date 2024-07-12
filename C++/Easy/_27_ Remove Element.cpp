
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0; // Use j to keep track of the position to overwrite elements without val
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};