/**
 * Written by: Joseph Thweatt
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain
 * a single digit. Add the two numbers and return it as a linked list.
 *
 * The code seems to run right, but leetcode seems to have a problem
 * with one of the test cases (although when I run the code it works fine)
 * Basically, I can't get the running time, but everything seems to match
 * what others have done. 
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * node;

    if (l1 == NULL && l2 == NULL) {
        node = NULL;
    } else {
        node = malloc(sizeof (struct ListNode));
        node->val = 0;
        if (l1 != NULL) {
            node->val += l1->val;
        }
        if (l2 !=NULL) {
            node->val += l2->val;
        }
        // carry over one to the next digit in the list
        if (node->val > 9) {
		    if (l1->next != NULL) {
	        	l1->next->val++;
			} else if (l2->next != NULL) {
				l2->next->val++;
			} else {
				l1->next = malloc(sizeof (struct ListNode));
				l1->next->val = 1;
			}
            node->val -= 10;
        }
        // chose which variables can get passed on
        if (l1 != NULL && l2 != NULL) {
            node->next = addTwoNumbers(l1->next, l2->next);   
        } else if (l1 != NULL) {
            node->next = addTwoNumbers(l1->next, NULL);
        } else if (l2 != NULL) {
            node->next = addTwoNumbers(NULL, l2->next); 
        }
    }
    return node;
}
