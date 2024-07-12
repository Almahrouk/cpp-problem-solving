/*
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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



class Solution { // My Solution
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = NULL;
        ListNode*current = NULL;
        auto fun1 = [&](){
            if(result == NULL) {
                result = list1;
                current = list1;
            }
            else {
                current -> next = list1;
                current = list1;
            }
            list1 = list1-> next;
        };
        auto fun2 = [&](){
            if(result == NULL) {
                result = list2;
                current = list2;
            }
            else {
                current -> next = list2;
                current = list2;
            }
            list2 = list2-> next;
        };
        while(list1 != NULL && list2  != NULL) {
            if(list1->val < list2->val) { fun1(); }
            else { fun2(); }
        }
        while(list1!= NULL) { fun1(); }
        while(list2!= NULL) { fun2(); }
        return result;
    }
};





class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;  // if list1 empty -> return list2
        if(!list2) return list1;  // if list2 empty -> return list1
        if(list1->val <= list2->val){ // if value of Li1 <= value of Li2
            list1->next = mergeTwoLists(list1->next,list2); // the next value of Li1 = call the function agine (where calling the next of list 1)
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

/*
Approach
By recursively merging the smaller node at each step, algorithm builds the merged list while maintaining the sorted order. The base cases ensure that the recursion stops when one of the lists becomes empty.

If list1 is NULL, then return list2, as there is nothing to merge.
If list2 is NULL, then return list1, as there is nothing to merge.

If the value of the current node in list1 is less than or equal to the value of the current node in list2, then:
-- Set the next pointer of list1 to the result of merging the remaining nodes of list1 and list2.
-- Return list1 as the new head of the merged list.

If the value of the current node in list2 is less than the value of the current node in list1list1list1, then:
-- Set the next pointer of list2 to the result of merging the remaining nodes of list1 and list2.
-- Return list2 as the new head of the merged list.
*/




class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
           return list1;
        }
        ListNode* head=NULL;
        if(list1->val<list2->val){
            head=list1;
            list1=list1->next;
        }
        else{
           head=list2;
            list2=list2->next;
        }
         ListNode* curr=head;
        while(list1&&list2){
         if(list1->val<=list2->val){
           curr->next=list1;
            list1=list1->next;
        }
        else{
             curr->next=list2;
            list2=list2->next;
        }
        curr=curr->next;
        }
        if(!list1){
            curr->next=list2;
        }
        else{
             curr->next=list1;
        }
        return head;
    }
};



