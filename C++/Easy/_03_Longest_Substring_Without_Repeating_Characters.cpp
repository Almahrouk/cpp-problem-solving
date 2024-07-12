#include <iostream>
//#include <vector>
#include <set>
using namespace std;
/*
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> Set;
        int start=0;
        int end=0;
        int Max=0;
        while(start < s.size()){
            auto it = Set.find(s[start]);
            if (it==Set.end()){
                if(start - end + 1>Max){
                    Max = start - end + 1;
                }
                Set.insert(s[start]);
                start++;
            }
            else{
                Set.erase(s[end]);
                end++;
            }
        }
        return Max;

    }
};