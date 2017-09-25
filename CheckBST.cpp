/*
* Written by: Joseph Thweatt
* Runtime: Unknown
* 
* Given the root node of a binary tree, can you determine if it's 
* also a binary search tree?
* 
* The Node struct is defined as follows:
*    struct Node {
*       int data;
*       Node* left;
*       Node* right;
*    }
*/
#include <climits>

bool checkBST(Node* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}

bool checkBST(Node* root, int min, int max) {
    return (root == NULL) ||
           (!(root->data <= min || root->data >= max) &&
            checkBST(root->left, min, root->data) &&
            checkBST(root->right, root->data, max));
}
