class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int index=nums[i]%n;
            nums[index]+=n;
        }
        for(int i=0;i<n;i++){
            if((nums[i]/n)>=2) return i;
        }
        return -1;
    }
};