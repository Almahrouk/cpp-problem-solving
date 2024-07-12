/*

Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.


*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0}, maxF=0, f=0;
        for (int x: nums){
            freq[x]++;
            f+=(freq[x]==maxF);
            if (freq[x]> maxF) f=1, maxF=freq[x];
        }
        return f*maxF;
    }
};