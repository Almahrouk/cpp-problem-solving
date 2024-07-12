#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        // int n = s.size();
        if (s.size() <= 1) return s;

        // if (s.size() <= 1) return (s.size() == 2) ? ((s[0] == s[1]) ? s : "No") : "Not Applicable";


        int start = 0, maxLength = 1;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left;
                ++right;
            }
            return right - left - 1;
        };

        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandAroundCenter(i - 1, i + 1); // odd length palindrome
            int len2 = expandAroundCenter(i, i + 1); // even length palindrome

            int currentLength = max(len1, len2);
            if (currentLength > maxLength) {
                start = i - (currentLength - 1) / 2;
                maxLength = currentLength;
            }
        }

        return s.substr(start, maxLength);
    }
};








class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }

        // Create a table to store whether substrings are palindromes
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
        }

        int start = 0; // Start index of the longest palindrome
        int maxLength = 1; // Length of the longest palindrome

        // Check substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check substrings of length 3 or more
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;

                if (isPalindrome[i + 1][j - 1] && s[i] == s[j]) {
                    isPalindrome[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    Solution solution;
    string s1 = "babad";
    string result1 = solution.longestPalindrome(s1);
    cout << "Example 1: " << result1 << endl;

    string s2 = "cbbd";
    string result2 = solution.longestPalindrome(s2);
    cout << "Example 2: " << result2 << endl;

    string s3 = "acdedaded";
    string result3 = solution.longestPalindrome(s3);
    cout << "Example 2: " << result3 << endl;

    return 0;
}


#include <stack>
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() <= 1)
            return s;

        int start = 0, maxLength = 1;
        std::stack<char> charStack;

        for (int i = 0; i < s.size(); ++i) {
            // Function to expand around the center using stack
            auto expandAroundCenter = [&](int left, int right) {
                while (left >= 0 && right < s.size() && s[left] == s[right]) {
                    --left;
                    ++right;
                }
                return right - left - 1;
            };

            // Use stack to find the longest palindromic substring
            charStack.push(s[i]);
            if (charStack.size() > 1 && s[i] == charStack.top()) {
                int len = expandAroundCenter(i - charStack.size() + 1, i);
                if (len > maxLength) {
                    maxLength = len;
                    start = i - len / 2;
                }
            } else {
                // Pop elements from the stack to maintain uniqueness
                while (!charStack.empty()) {
                    charStack.pop();
                }
                charStack.push(s[i]);
            }
        }

        return s.substr(start, maxLength);
    }
};


int main() {
    vector<int> vec = {2, 3, 1, 5};

    auto it = find_if(vec.begin(), vec.end(), [](int i) -> bool {return (i > 4);});

    cout << *it;

    for_each(vec.begin(), vec.end(), [](int i){cout << i << endl;});
    return 0;
}



/*
Given a string s, return the longest palindromic
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

*/