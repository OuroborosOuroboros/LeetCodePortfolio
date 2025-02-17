/* Davey Getchell 
 * CS5008 Spring2023
 * 876. Middle of the Linked List - Easy 1 point
 * Tags: Linked List
 * https://leetcode.com/problems/middle-of-the-linked-list/
 */


/**
 * Definition for singly-linked list.
 * struct ListNode{
 * 	int val;
 * 	struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    int i;
    struct ListNode* temp = head->next;
    int count = 0;
    while(temp!=NULL){
        count ++;
        temp = temp->next;
    }
    temp = head;
    if (count%2==0){
        for (i=0;i<count/2;i++){
            temp = temp->next;
            }
    }else {
        for(i=0;i<(count/2)+1;i++){
            temp = temp->next;
        }
    }    
    return temp;
}
