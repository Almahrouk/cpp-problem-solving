#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        
        //Iterative binary search
        while(left<=right)    // 2nd loop => left = 4 , right = 6 => Yes          3rd loop => 4<=4 Yes
        {
            mid = (left+right)/2;   // 2nd loop mid=(4+6)/2 => 5                 3rd loop => (4+4)/2 => 4
            //cout<<nums[mid]<<"\n";
            if(nums[mid]==target) return mid;   // 3rd loop Yessss Finalllllly

            // nums = [4,5,6,7,0,1,2], target = 0

            else if(nums[mid]>=nums[left]){    // 7 >= 0 => Yes              2nd loop => 1>=0 Yes
                if(target<=nums[mid] && target>=nums[left])  // (0 <= 7   &&   0 >= 4)  => N0         2nd loop (0<=1 && 0>=0) Yessss
                    right = mid-1;  // 2nd loop Yes => 5-1=4 
                else  // Yes
                    left = mid+1;   // left = 3 + 1 => 4
            }
            else{
                if(target>=nums[mid] && target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};