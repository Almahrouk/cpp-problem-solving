/*

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    vec.push_back(nums1[i]);
                }
            }
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec;
    }
};


class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> nums1Set(nums1.begin(), nums1.end());
        std::vector<int> intersectionVec;
        for (int num : nums2) {
            if (nums1Set.count(num)) {
                intersectionVec.push_back(num);
                nums1Set.erase(num); // Remove the element from set to avoid duplicates
            }
        }
        return intersectionVec;
    }
};