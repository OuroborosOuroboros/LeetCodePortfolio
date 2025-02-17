/* Davey Getchell
 * CS 5008 Spring 2023
 * 2181. Merge Nodes in Between Zeroes
 * Tags: Linked List
 * https://leetcode.com/problems/merge-nodes-in-between-zeros/
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *    int val;
 *    struct ListNode *next;
 * };
 */

struct ListNode* mergeNodes(struct ListNode* head){
    if (head == NULL || head->next == NULL){
        return NULL;
    }
    struct ListNode* temp = head->next;
    int sum = 0;
    while(temp->val!=0){
        sum += temp->val;
        temp = temp->next;
    }
    head->next->val = sum;
    head->next->next = mergeNodes(temp);

    return head->next;
}
