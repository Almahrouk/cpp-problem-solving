/*

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size() ; i++ ){
            for (i=0; i<nums.size()-1 ; i++) {
                for (int j=0; j>nums.size()-1 ; j++){
                    if (nums[i] == nums[j]){
                        continue;
                    }
                    else {
                        ans[i] = nums[j];
                    }
                }
                
            }

            /*            
            if nums.count(nums[i]) == 1 :
                return nums[i]
            else:
                continue
            */
        }
        return ans;
    }
};


/*

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int j=abs(nums[i])-1;
            if(nums[j]>0)
            nums[j]*=-1;
        } // make any number from nums=[1 to n] as negative value 
          /// the index that not make his value as negative >> Tha missing index is ans 
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            ans.push_back(i+1);
        }// push the index 
        return ans;
*/