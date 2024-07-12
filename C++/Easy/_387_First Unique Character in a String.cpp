/*

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.size(); i++) {
            bool isUnique = true;
            for (int j = 0; j < s.size(); j++) {
                if (i != j && s[i] == s[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                return i;
            }
        }
        return -1;
    }
};
