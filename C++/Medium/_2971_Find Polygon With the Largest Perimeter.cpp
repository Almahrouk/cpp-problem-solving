class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = -1;
        long long sum = nums[0]+nums[1];
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] < sum)
                ans = nums[i] + sum;
            sum += nums[i];
        }
        return ans;
    }
};