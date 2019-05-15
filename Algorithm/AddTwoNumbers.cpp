/*
Just given the function body, need to write the complete running code with headers and client code

Problem Statement
-------------------
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *start = NULL;
        ListNode *p = NULL;
        
        int sum = 0;
        int carry = 0;
        int res = 0;
        
        while(l1 && l2){
            res = l1->val + l2->val + carry;
            sum = (res)%10;
            carry = (res)/10;
            
            if(start == NULL){
                start = new ListNode(sum);
                p = start;
            } else {
                p->next = new ListNode(sum);
                p = p->next;
            } 
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            res = l1->val + carry;
            sum = (res)%10;
            carry = (res)/10;
            
            if(start == NULL){
                start = new ListNode(sum);
                p = start;
            } else {
                p->next = new ListNode(sum);
                p = p->next;
            }  
            l1 = l1->next;
        }
        
        while(l2){
            res = l2->val + carry;
            sum = (res)%10;
            carry = (res)/10;
            
            if(start == NULL){
                start = new ListNode(sum);
                p = start;
            } else {
                p->next = new ListNode(sum);
                p = p->next;
            }  
            
            l2 = l2->next;
        }
        
        if(carry > 0) p->next = new ListNode(carry);
        
        return start;
