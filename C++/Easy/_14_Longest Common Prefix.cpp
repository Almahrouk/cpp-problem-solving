#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution { // Not Very Good
public:
    string longestCommonPrefix(vector<string> strs) {
        string s = strs[0];
        int count = 0;
        for (int i=0; i<strs.size(); i++) {
            if (strs[0][i] == strs[1][i] && strs[0][i] == strs[2][i]){
                count++;
            }
        }
        return count == 0 ? "" : s.substr(0, count);
    }
};


class Solution { // So Better
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix = strs[0]; // 1st string
        int count = prefix.size(); // length of 1st string

        // Iterate through each character at the same position in all strings
        for (int i = 0; i < count; ++i) {
            for (int j = 1; j < strs.size(); ++j) { // loop for each ele on vector string
                // Check if character at position i is equal across all strings
                if (i >= strs[j].size() || prefix[i] != strs[j][i]) {
                    return prefix.substr(0, i);
                }
            }
        }
        return prefix;
    }
};


/*
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/