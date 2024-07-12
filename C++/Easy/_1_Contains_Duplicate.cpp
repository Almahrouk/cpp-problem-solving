#include <iostream>
#include <vector>

using namespace std;


// Brute Force
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool flag = false;
        for(int i =0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] == nums[j]) return true;
            }
        }
        return flag;
    }
};


/* OR
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i=0; i<nums.size(); i+=2){
            for(int j=0; j<i; j++){
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
        
        
    }
};

*/


/*           Use Map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> CounMap;
        for (int i=0; i<nums.size(); i++){
            if (CounMap[nums[i]]) return true;
            CounMap[nums[i]]++;
        }
        return false;
    }
};



=======> Using Set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> SetNums(nums.begin(), nums.end());
        return (nums.size() == SetNums.size())? false : true;
    }
};

*/

int main() {
    vector y1 = {1,2,3,4}, z = {0};
    Solution x1;
    cout << x1.containsDuplicate(y1);

    cin >> z[0] >> z[1] >> z[2];
    cout << x1.containsDuplicate(z);
    
    exit(0);
    return 0;
    
}