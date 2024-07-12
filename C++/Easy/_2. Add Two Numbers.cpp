/**
 * 
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
 * 
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

using namespace std;

class Solution {
public:
    struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* result = new ListNode(0);
        ListNode* curr = result;
        while(l1 || l2 || carry){
            int d1 = l1 ? l1->val : 0;
            int d2 = l2 ? l2->val : 0;
            int sum = d1 + d2 + carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            carry = sum/10;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return result->next;
    }
};