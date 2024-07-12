/*

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        std::vector<int> vec;
        while (curr != nullptr) {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        std::reverse(vec.begin(), vec.end());
        int re = 0;
        for (int i = 0; i < vec.size(); i++) {
            re += vec[i] * pow(2, i);
        }
        return re;
    }
};