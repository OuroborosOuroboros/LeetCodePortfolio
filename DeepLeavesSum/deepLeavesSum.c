/* Davey Getchell
 * CS5008 Spring 2023
 * 1302. Deepest Leaves Sum - Medium 2 points
 * Tags: Tree, DFS, BFS, Binary Tree
 * https://leetcode.com/problems/deepest-leaves-sum/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *    int val;
 *    struct TreeNode *left;
 *    struct TreeNode *right;
 * };
 */


void dfs(struct TreeNode* root, int currDepth, int* maxDepth, int* sum){
    if (root == NULL) return;

    if (currDepth>*maxDepth){
        *maxDepth = currDepth;
        *sum = root->val;
    } else if (currDepth == *maxDepth){
        *sum += root->val;
    }
    dfs(root->left, currDepth+1, maxDepth, sum);
    dfs(root->right, currDepth+1, maxDepth, sum);
}

int deepestLeavesSum(struct TreeNode* root){
    int maxDepth = 0;
    int sum = 0;
    
    dfs(root, 0, &maxDepth, &sum);
    
    return sum;
}

