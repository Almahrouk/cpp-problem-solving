
#include <vector>
#include <algorithm> // for max function

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        vector<int> re;

        // Separate positive and negative numbers
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                positive.push_back(nums[i]);
            }
            if(nums[i] < 0){
                negative.push_back(nums[i]);
            }
        }

        // Determine the maximum size among positive and negative vectors
        int maxSize = max(positive.size(), negative.size());

        // Interleave positive and negative numbers
        for(int i = 0; i < maxSize; i++){
            if(i < positive.size()){
                re.push_back(positive[i]);
            }
            if(i < negative.size()){
                re.push_back(negative[i]);
            }
        }

        return re;
    }
};



/*



Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.
Example 2:

Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].


*/