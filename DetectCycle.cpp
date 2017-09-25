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
