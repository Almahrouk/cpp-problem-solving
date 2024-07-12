// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//         long long ans=0;
//         int n=size(nums);
//         int st=-1,mini=-1,maxi=-1;
//         for(int i=0;i<n;i++){
//             if(nums[i]<minK || nums[i]>maxK)st=i;
//             if(nums[i]==minK)mini=i;
//             if(nums[i]==maxK)maxi=i;
//             int temp=min(mini,maxi)-st;
//             ans+=(temp<0)?0:temp;
//         }
//         return ans;
//     }
// };
// this approach is right and work well but the TC : O(n^2).

// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         long long ans =0;

//         for(int i=0; i<n; i++)
//         {
//             for(int j =i; j<n; j++)
//             {
//                 if(nums[i] == minK && nums[j] == maxK)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int minPosition = -1;
        int maxPosition = -1;
        int leftBound   = -1;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] < minK || nums[i] > maxK)
                leftBound = i;

            if(nums[i] == minK)
                minPosition = i;
            if(nums[i] == maxK)
                maxPosition = i;

            int count = min(maxPosition, minPosition) - leftBound;

            ans += (count <= 0) ? 0 : count;

        }

        return ans;
    }
};