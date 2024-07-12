#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> x;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i+=3) {
            if ((nums[i + 2] - nums[i]) > k) {
                return {};
            }
            x.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return x;
    }
};




class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> x;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() / 3; i++) {
            if ((nums[3*i + 2] - nums[3*i]) > k) {
                return {}; // Return empty vector if the difference exceeds k
            }
            x.push_back({nums[3*i], nums[3*i + 1], nums[3*i + 2]});
        }
        return x;
    }
};
