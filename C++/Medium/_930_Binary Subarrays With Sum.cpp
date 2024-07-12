/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.



Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

*/

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int res = 0;
//         for (int start = 0; start < nums.size(); ++start) {
//             int sum = 0;
//             for (int end = start; end < nums.size(); ++end) {
//                 sum += nums[end];
//                 if (sum == goal)
//                     ++res;
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefSumFreqMp;
        int prefSum = 0;
        prefSumFreqMp[0] = 1;
        int subArrayCnt = 0;
        for (int num : nums) {
            prefSum += num;
            if (prefSumFreqMp.find(prefSum - goal) != prefSumFreqMp.end()) {
                subArrayCnt += prefSumFreqMp[prefSum - goal];
            }
            prefSumFreqMp[prefSum]++;
        }
        return subArrayCnt;
    }
};