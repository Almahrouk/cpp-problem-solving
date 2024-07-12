#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int i = 0;
        while(i < s.size()){
            if(s[i] != t[i])
                return (char)t[i];
            i++;
        }
        return (char)t[t.size() - 1];
    }
};

/*


Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.


Example 2:

Input: s = "", t = "y"
Output: "y"

*/