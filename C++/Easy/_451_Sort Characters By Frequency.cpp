
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


// imp
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        vector<pair<int, char>> v;
        string ans = "";

        // count character frequency
        for(auto ch: s){
            mp[ch]++;
        }

        // push from map to vector
        for(auto i: mp){
            v.push_back({i.second, i.first});
        }

        // sort the vector in decreasing order
        sort(v.begin(), v.end(), greater<pair<int, char>>());

        // add to final answer string
        for(auto i: v){
            while(i.first--) ans += i.second;
        }
        return ans;
    }
};

/*

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/