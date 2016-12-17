/**
 * Written By: Joseph Thweatt
 * Runtime: 0 ms
 * 
 * Given a linked list, swap every two 
 * adjacent nodes and return its head. For example,
 *
 * Given 1->2->3->4, you should return the list 
 * 		 	as 2->1->4->3
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head && head->next) {
        struct ListNode *temp = head;
        
        if (head->next->next) {
            head->next->next = swapPairs(head->next->next);
            head = head->next;
            temp->next = head->next;
            head->next = temp;
        } else {
            head = head->next;
            head->next = temp;
            temp->next = NULL;
        }
    }
    
    return head;
}
