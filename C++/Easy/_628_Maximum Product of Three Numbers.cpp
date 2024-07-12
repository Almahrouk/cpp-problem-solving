/*

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6

*/

class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return std::max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};