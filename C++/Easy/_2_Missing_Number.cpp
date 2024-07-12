/*

Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.


Example 1:
...
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, 
so all numbers are in the range [0,3]. 
2 is the missing number in the range since it does not appear in nums.


Example 2:
...
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, 
so all numbers are in the range [0,2]. 
2 is the missing number in the range since it does not appear in nums.


Example 3:
...
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, 
so all numbers are in the range [0,9]. 
8 is the missing number in the range since it does not appear in nums.


Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ;
        int sum = n * (n + 1)/2 ;
        for (int i = 0 ; i < n ; i ++)
        {
            sum = sum - nums[i] ;
        }
        return sum ;
    }
};

/*
nums = [2,3,0];
n=3
sum = 3*(3+1)/2 = 6;

2 loop :
1] sum = 6-2 = 4;
2] sum = 4-3 = 1;
3] sum = 1-0 = 1;
*/

/*
if nums = [1,0];
n=2
sum = 2 * (2+1) / 2 >> 3

loop 2 time :
1] sum = 3 - 1 >> 2;

2] sum = 2 - 0 >> 2;

/*************************************

**************** invalide case 

if nums = [1,0,4];
n=3
sum = 3 * (3+1) / 2 >> 6

loop 3 time :
1] sum = 6 - 1 >> 5;

2] sum = 5 - 0 >> 5;

3] sum = 5 - 4 >> 1;
*/

/************************************************************/




class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {   // doing xor of the number in nums and in range[0,n]
            // together 
            ans=(ans^i^nums[i]);
        }
        // since n will we outofbound so handeled seperately
        ans=ans^n;
        return ans;
    }
};

int main() {
    /*
    vector y1 = {1,2,3,4}, z = {0};
    Solution x1;
    cout << x1.containsDuplicate(y1);

    cin >> z[0] >> z[1] >> z[2];
    cout << x1.containsDuplicate(z);
    
    exit(0);
    */
    return 0;
    
}

/*



nums = []
class Solution:
    def missingNumber(self, nums) : # List[int] -> bool
        for i in range(len(nums)+1):       
            if nums.count(i) == 0 :
                return i
            else:
                continue
        return "No Missing Num"


*/



