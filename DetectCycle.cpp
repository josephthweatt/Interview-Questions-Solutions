/*
* Written by: Joseph Thweatt
* Runtime: Unknown
*
* Detect a cycle in a linked list. Note that the head
* pointer may be 'NULL' if the list is empty.
* A Node is defined as:
*     struct Node {
*         int data;
*         struct Node* next;
*     }
*/
#include <set>

// set solution
bool has_cycle(Node* head) {
    if (head == NULL) return 0;

    set<Node*> past;
    past.insert(head);
    head = head->next;
    while (head != NULL) {
        if (past.find(head) != past.end()) {
            return 1;
        }
        past.insert(head);
        head = head->next;
    }
    return 0;
}

// fast-slow solution (better answer)
bool has_cycle(Node* head) {
    if (head == NULL) return 0;

    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && slow != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return 1;
        }
    }
    return 0;
}
