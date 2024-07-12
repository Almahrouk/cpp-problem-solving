
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> common;
        std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(common));

        if (common.empty()) {
            return -1; // Return -1 if there are no common elements
        } else {
            return *std::min_element(common.begin(), common.end());
        }
    }
};



        // unique(nums1.begin(), nums1.end());
        // nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        // // find dublicated
        // sort(nums1.begin(), nums1.end());

        // std::vector<int> re;
        // for(int i=0; i<nums1.size(); i++){
        //     if(nums1[i] == nums1[i+1]){
        //         re.push_back(nums1[i]);
        //     }
        // }
        // for(int i=0; i<nums1.size(); i++){
        //     for(int j=0; j<nums2.size(); j++){
        //         if(nums1[i] == nums2[j]){
        //             comm.push_back(nums1[i]);
        //         }
        //     }
        // }
        // int min=INT_MAX;
        // for(int i=0; i<comm.size(); i++){
        //     if(min > comm[i]){
        //         min = comm[i];
        //     }
        // // }
        // return min;
//         return *min_element(re.begin(), re.end());
//     }
// };

/*
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.



Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.

*/