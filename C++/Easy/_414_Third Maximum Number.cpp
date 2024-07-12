/*

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.

*/

class Solution {
public:
    int thirdMax(std::vector<int>& vec) {
        std::sort(vec.begin(), vec.end(), std::greater<int>()); // desc order
        vec.erase(std::unique(vec.begin(), vec.end()), vec.end()); // remove deplocated
        if (vec.size() >= 3) {
            return vec[2];
        } else {
            return vec[0]; // If there are fewer than 3 unique elements, return the maximum element
        }
    }
};