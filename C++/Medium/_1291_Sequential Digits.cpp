/*
Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> a;

        for (int i = 1; i <= 9; ++i) {
            int num = i;
            int nextDigit = i + 1;

            while (num <= high && nextDigit <= 9) {
                num = num * 10 + nextDigit;
                if (low <= num && num <= high) a.push_back(num);
                ++nextDigit;
            }
        }

        sort(a.begin(), a.end());
        return a;
    }
};


