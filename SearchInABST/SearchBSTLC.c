/* Davey Getchell
 * CS5008 Spring 2023
 * 700. Search in a Binary Search Tree - Easy 1 pt
 * Tags: Tree, Binary Search Tree, Binary Tree
 * https://leetcode.com/problems/search-in-a-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *       int val;
 *        struct TreeNode *left;
 *         struct TreeNode *right;
 *      };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val){
    while (root!=NULL){
        if(val > root->val){
            root = root->right;
        }
        else if(val< root->val){
            root = root->left;
        }
        else{
            return root;
        }
    }
    return NULL;
}
