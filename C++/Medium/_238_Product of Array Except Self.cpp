/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         std::vector<int> re;
//         int pro;
//         int size = nums.size();
//         for(int i=0; i<size; i++){
//             pro = 1;
//             for(int j=0; j<size; j++){
//                 if(i==j){
//                     continue;
//                 }
//                 pro *= nums[j];
//             }
//             re.push_back(pro);
//         }
//         return re;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int pre=1;
       int n=nums.size();
       vector<int>res(n,1);
       int j=0;
       for(auto i:nums){
           res[j] = pre;
           j++;
           pre*=i;
       }
       pre=1;
       for(auto k=nums.rbegin();k!=nums.rend();k++){
           j--;
           res[j] *= pre;
           pre*=(*k);
       }
       return res;
    }
};