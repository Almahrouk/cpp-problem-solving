#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> nums1;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        nums1.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        // Remove duplicates
        sort(nums1.begin(), nums1.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());

        return nums1;
    }
};





class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array first

        vector<vector<int>> result;

        // Fix the first element and use two pointers approach for the rest
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicate values
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for the second and third elements
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }

                    ++left;
                    --right;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = solution.threeSum(nums1);

    cout << "Example 1:" << endl;
    for (const auto& triplet : result1) {
        cout << "[";
        for (int num : triplet) {
            cout << num << ",";
        }
        cout << "]";
    }
    cout << endl;

    // Add more examples if needed

    return 0;
}


/*


Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


*/