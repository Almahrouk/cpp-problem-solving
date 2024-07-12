
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            } else if (count > 0) {
                nums[i - count] = nums[i];
                nums[i] = 0;
            }
        }
    }
};


/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int count;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                count++;
            }
        }
        for(int i=0; i<count; i++){
            nums.pop_back();
        }
        sort(nums.begin(), nums.end());
    }
};
*/

/*

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


*/