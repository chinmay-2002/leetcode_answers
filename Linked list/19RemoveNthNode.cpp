/*
19. Remove Nth Node From End of List
Medium

13682

565

Add to List

Share
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int c = 0;
        while(temp!=NULL){
            c++;
            temp = temp->next;
        }
        if(c==0) return head;
        if(c==1 && n==1){
            head = NULL;
            return head;
        }
        c = c - n ;
        if(c==0){
            return head->next;
        }
        temp = head;
        for(int i=1; i<c; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};

// Another one]

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode prehead(-1, head);
        ListNode* prev = &prehead;
        for (int i = 0; i < n; ++i) {
            head = head->next;
        }
        while (head) {
            head = head->next;
            prev = prev->next;
        }
        ListNode* rip = prev->next;
        prev->next = prev->next->next;
        // Don't be that person that leaks memory. :)
        delete rip;
        return prehead.next;
    }