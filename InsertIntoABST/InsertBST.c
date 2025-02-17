/* Davey Getchell
 * CS5008 Spring 2023
 * 701. Insert into a Binary Search Tree - Medium 2 points
 * Tags: Tree, Binary Search Tree, Binary Tree 
 * https://leetcode.com/problems/insert-into-a-binary-search-tree/
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 *};
 */    

struct TreeNode* insertHelper(struct TreeNode* current, struct TreeNode* temporary){
        if(temporary->val < current->val){
            if(current->left == NULL){
                current->left = temporary;
                return current;
        } else {
            return insertHelper(current->left, temporary);
            }
        } else if(temporary->val > current->val){
            if(current->right == NULL){
                current->right = temporary;
                return current;
            } else{
                return insertHelper(current->right, temporary);
            }
        }
        else{
            return NULL;
        }
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode* temp = malloc(sizeof (struct TreeNode));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    if (root==NULL){
        root = temp;
        return root;
    }
    insertHelper(root, temp);
    return root;
}
