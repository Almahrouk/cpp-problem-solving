/*

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

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
    ListNode* removeElements(ListNode* head, int val) {
        // Handle the case where the head node itself has the value to be removed
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            // If the next node's value is equal to val, remove it
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {


       // bc
       if(head==NULL)
        return NULL;
        // rr
        // 2 3 4 5 4
        head->next=removeElements(head->next,val);
        // task
        if(head->val==val){
            return head->next;
        }
        return head;
    }
};



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *curr = temp;
        while(curr->next != NULL ){
            if(curr->next->val == val) curr->next = curr->next->next;
            else curr = curr->next;
        }
        return temp->next;
    }
};