#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=0;
        int ans;

        for(int i=0; i<nums.size(); i++) {
            int starting=i+1;
            int ending=nums.size()-1;
            while(starting<ending) {
                sum=nums[i]+nums[starting]+nums[ending];
                if(sum==target) { return sum; }
                if(sum<target) { starting++; }
                else { ending--; }

                if(abs(sum-target)<abs(ans-target)) { ans=sum; }
            }
        }
        return ans;
    }
};


/*



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

*/