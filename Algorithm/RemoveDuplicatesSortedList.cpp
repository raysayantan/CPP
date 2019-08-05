/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pPrev = NULL;
        ListNode *prev = NULL;
        ListNode *curr = NULL;
        ListNode *dupStart = NULL;
        
        curr = head;
        while(curr != NULL){
            if(curr->next != NULL && curr->next->val == curr->val){
               if(dupStart == NULL){
                   pPrev = prev;
                   dupStart = curr;
               }
               
            } else if(dupStart != NULL){
               if(dupStart == head){
                  head = curr->next; 
               } else {
                   pPrev->next = curr->next;
               }
               curr = curr->next;
               dupStart = NULL;
               prev = pPrev;
               continue;
           }
           prev = curr;
           curr = curr->next;
        }
        return head;
    }
};
