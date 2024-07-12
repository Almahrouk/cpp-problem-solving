

#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        double need = nums.size() / 2.0;
        double count = 0.0;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            count = 1;
            for(int j=i; j<nums.size(); j++){
                if( j!=i && nums[i] == nums[j]){
                    count++;
                }
            }
            if(count >= need) {
                return nums[i];
            }
        }
        return 0;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int res = 0;
        int majority = 0;

        for (int n : nums) {
            hash[n] = 1 + hash[n];
            if (hash[n] > majority) {
                res = n;
                majority = hash[n];
            }
        }

        return res;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size() / 2;


        for (auto a : nums) {
            mp[a]++;
        }

        int ans = 0;

        for (auto a : mp) {
            if (a.second > n) {
                ans = a.first;
            }
        }

        return ans;
    }
};




/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/