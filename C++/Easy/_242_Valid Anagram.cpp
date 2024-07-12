#include <iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<s.size(); i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};

/*

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


*/