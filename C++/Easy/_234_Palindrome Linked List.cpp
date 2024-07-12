/*

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        std::vector<int> vec;
        while (curr != nullptr) {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        int start = 0;
        int end = vec.size() - 1;
        while (start < end) {
            if (vec[start] != vec[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};