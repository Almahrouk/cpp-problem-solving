class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int& x : arr) {
            mp[x]++;
        }

        vector<int> freq;
        for (auto& pair : mp) {
            freq.push_back(pair.second);
        }

        sort(begin(freq), end(freq));

        int count = 0;
        for (int& f : freq) {
            if (k >= f) {
                k -= f;
                count++;
            } else {
                break;
            }
        }

        return freq.size() - count;
    }
};



/*
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.



Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

*/