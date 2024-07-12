
#include <vector>
#include <algorithm>

using namespace std;

class Solution {  // Very Imp
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Sort the input array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // dp[i] stores the size of the largest divisible subset ending with nums[i]
        vector<int> dp(n, 1);

        // parent[i] stores the index of the previous element in the largest divisible subset ending with nums[i]
        vector<int> parent(n, -1);

        int max_len = 1; // length of the largest divisible subset
        int max_idx = 0; // ending index of the largest divisible subset

        // Dynamic Programming to find the largest divisible subset
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;

                    if(dp[i] > max_len) {
                        max_len = dp[i];
                        max_idx = i;
                    }
                }
            }
        }

        // Reconstruct the largest divisible subset
        vector<int> result;
        while(max_idx != -1) {
            result.push_back(nums[max_idx]);
            max_idx = parent[max_idx];
        }

        reverse(result.begin(), result.end()); // Reverse the result

        return result;
    }
};


/*

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


*/