/* Davey Getchell
 * CS5008 Spring 2023
 * 1315. Sum of Nodes with Even-Valued Grandparent - Medium 2 points
 * Tags: Tree, DFS, BFS, Binary Tree
 * https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
 */


/**
 * Definition for a binary tree node.
 *     struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumEvenGrandparent(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int sum = 0;
    if (root->val%2==0){
        if(root->left!=NULL && root->left->left!=NULL)
            sum+=root->left->left->val;
        if(root->left!=NULL && root->left->right!=NULL)
            sum+=root->left->right->val;
        if(root->right!=NULL && root->right->right!=NULL)
            sum+=root->right->right->val;
        if(root->right!=NULL && root->right->left!=NULL)
            sum+=root->right->left->val;
    }
    sum+= sumEvenGrandparent(root->left);
    sum+= sumEvenGrandparent(root->right);
    return sum;
}
