/*
448. Find All Numbers Disappeared in an Array

Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:
....
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
....
Input: nums = [1,1]
Output: [2]


*/


#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int j=abs(nums[i])-1;
            if(nums[j]>0)
            nums[j]*=-1;
        } // make any number from nums=[1 to n] as negative value 
          // the index that not make his value as negative >> Tha missing index is ans 
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            ans.push_back(i+1);
        }// push the index 
        return ans;
    }
};

/*
nums = [4,3,2,7,8,2,3,1];
ans=[];

1) First loop :
    8 loop :
    1] j=|4|-1 => 3
    if nums[3]>0 >>> nums[3] = -7;

    2] j=|3|-1 => 2
    if nums[2]>0 >>> nums[2] = -2;
....
index nums = [ 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 ] >> positave value >> [0,5,6]
nums =       [ 4 ,-3 ,-2 ,-7 ,-8 , 2 , 3 ,-1 ] >> positave value >> [4,2,3]

The ans is => index nums => positave value >> [0,5,6]
*/