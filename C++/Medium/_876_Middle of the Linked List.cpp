/*

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.


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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* curr = head;

        // Calculate the length of the list
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        // Move curr back to the head
        curr = head;

        // Move curr to the middle node
        for (int i = 0; i < len / 2; i++) {
            curr = curr->next;
        }

        // Return the middle node
        return curr;
    }
};
