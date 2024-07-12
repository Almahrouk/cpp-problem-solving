
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=nums[i]+pre[i-1];
        }
        for(int i=0;i<pre.size();i++){
            if(i==0){
                if(pre[pre.size()-1]-pre[i]==0) return 0;
                continue;
            }
            if(pre[i-1]==pre[pre.size()-1]-pre[i]) return i;
        }
        return -1;
    }
};

/*


Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0


*/