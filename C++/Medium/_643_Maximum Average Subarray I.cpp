
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = INT_MIN; // Initialize with smallest possible value
        for (int i = 0; i <= nums.size() - k; i++) { // Loop through possible start indices of subarrays
            double sum = 0;
            for (int j = i; j < i + k; j++) { // Calculate sum of current subarray
                sum += nums[j];
            }
            maxAverage = max(maxAverage, sum / k); // Update maxAverage if the average of current subarray is greater
        }
        return maxAverage;
    }
};

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = INT_MIN; // Initialize with smallest possible value
        double windowSum = 0;

        // Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        maxAverage = max(maxAverage, windowSum / k);

        // Slide the window to the right
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i] - nums[i - k]; // Add the next element and remove the first element of the window
            maxAverage = max(maxAverage, windowSum / k);
        }

        return maxAverage;
    }
};


/*



Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

*/