/*

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        for(int j=0; j<nums1.size(); j++){   // Insert All nums1 in nums2
//            nums2.push_back(nums1[j]);
//        }
//        int mid = (nums2.size()-1)/2;
//      if (nums2.size()%2 != 0) return nums2[mid];
//    else return (nums2[mid]+nums2[mid+1])/2;


        vector<int> nums;
        for(int i=0; i<nums1.size(); i++){
            nums.push_back(nums1[i]);
        }
        for(int j=0; j<nums2.size(); j++){
            nums.push_back(nums2[j]);
        }
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return  len%2 ? nums[len/2] : (nums[len/2-1]+nums[len/2])/2.0 ;
    }
};

