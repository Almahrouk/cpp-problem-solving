
class Solution {
public:
    int findLHS(std::vector<int>& vec) {
        std::unordered_map<int, int> freqMap;
        for (int num : vec) {
            freqMap[num]++;
        }

        int maxLen = 0;
        for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
            auto next = freqMap.find(it->first + 1);
            if (next != freqMap.end()) {
                maxLen = std::max(maxLen, it->second + next->second);
            }
        }

        return maxLen;
    }
};


/*

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Example 2:

Input: nums = [1,2,3,4]
Output: 2
Example 3:

Input: nums = [1,1,1,1]
Output: 0

*/