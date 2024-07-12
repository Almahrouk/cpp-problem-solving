/*
You are given an integer array nums.

In one move, you can choose one element of nums and change it to any value.

Return the minimum difference between the largest and smallest value of nums after performing at most three moves.



Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.


Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.


Example 3:

Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
*/

/*
Expline: Aryan => https://www.youtube.com/watch?v=S3CJ0dcCXOY

we are given intger array nums, and in one move, you can choose one element of nums and change it to any value.
so I have to find the minimum difference between the largest and smallest value of nums after performing at most three moves.

and in every move I can change any value.

so I have to always keep on checking what is the largest what is the smallest,
and what is their difference

1] at first I always have to find the largest what is the smallest !!!
what is that algorithm or || data structure which will help us in that case =>> (sorting)

case 1: (array size = 4 or less)
[5, 3, 2, 4] => [2, 3, 4, 5]

step 1:
min = 2  max = 5 => change 5 to (2 | 3 | 4) || change 2 to (3 | 4 | 5)
let change 5 to 4
[2, 3, 4, 4]

step 2:
min = 2  max = 4 => change 4 to (2 | 3 | 4) || change 2 to (3 | 4 | 4)
let change 4 to 3
[2, 3, 3, 4]

step 3:
min = 2  max = 4 => change 4 to (2 | 3 | 4) || change 2 to (3 | 4 | 4)
let change 4 to 3
[2, 3, 3, 3]

min = 2 max = 3
3 - 2 = 1

finish.... (but this is not the best performance)

************************************

other algorithm... by doing the same step as before => let don't change the (max | min) to random value
we will change it to the same it oppoisit value

max value will change to min value || min value will change to max value

case 1:
[5, 3, 2, 4] => [2, 3, 4, 5]

step 1:
min = 2  max = 5 => max(5) to min(2)
[2, 3, 4, 2]

step 2:
min = 2  max = 4 => max(4) to min(2)
[2, 3, 2, 2]

step 3:
min = 2  max = 4 => max(3) to min(2)
[2, 2, 2, 2]

min = 2 max = 2
2 - 2 = 0

this is best performance to find the [Minimum Difference Between Largest and Smallest Value in Three Moves]
so in any case if array nums size() <= 4, it will return 0
*/

/*
case 2: other
[5, 3, 2, 4] => [2, 3, 4, 5] ==> [2, ?, ?, ?] => 2 - 2 = 0 always
[1, 5, 0, 10, 14] => [0, 1, 5, 10, 14] ==> [0, 1, ?, ?, ?] => 1 - 0 = 1

[9, 24, 10, 1, 29] => [1, 9, 10, 24, 29] ==> [1, 9, ?, ?, ?] => 9 - 1 = 8
[9, 24, 10, 1, 29] => [1, 9, 10, 24, 29] ==> [?, 9, 10, ?, ?] => 9 - 10 = 1

so we can't use the same algorithm to solve this case.... think??

algorithm 1: easy to understand | low speed
1. sort the array [9, 24, 10, 1, 29] => [1, 9, 10, 24, 29].
2. there are 4 cases...

let consume a large array [a(0), a(1), a(2), a(3), ..., a(n-4), a(n-3), a(n-2), a(n-1)]

a] delete the first 3 values
[?, ?, ?, a(3), ..., a(n-4), a(n-3), a(n-2), a(n-1)] =====> a(n-1) - a(3)

b] delete the first 2 values and last value
[?, ?, a(2), a(3), ..., a(n-4), a(n-3), a(n-2), ?] =====> a(n-2) - a(2)

c] delete the first value and last 2 values
[?, a(1), a(2), a(3), ..., a(n-4), a(n-3), ?, ?] =====> a(n-3) - a(1)

d] delete the last 3 values
[a(0), a(1), a(2), a(3), ..., a(n-4), ?, ?, ?] =====> a(n-4) - a(0)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int return_min_value = INT_MAX;
        int n = nums.size();
        if(n <= 4) return 0;

        return min({
        nums[n-1] - nums[3],
        nums[n-2] - nums[2],
        nums[n-3] - nums[1],
        nums[n-4] - nums[0]});
    }
};

/*

ex: [11, 0, 70, 22, 76, 19]
1] sort => [0, 11, 19, 32, 70, 76]

a. [?, ?, ?, 32, 70, 76] ==> 76 - 32 = 44
b. [?, ?, 19, 32, 70, ?] ==> 70 - 19 = 51
c. [?, 11, 19, 32, ?, ?] ==> 32 - 11 = 21
d. [0, 11, 19, ?, ?,  ?] ==> 19 - 0 = 9

ans = 9


*/