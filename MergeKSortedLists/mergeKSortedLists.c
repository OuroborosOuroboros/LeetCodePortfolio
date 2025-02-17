// Name: mergeTwoLists
// Input(s):
//     (1) 'a' is the head node of the first sorted linked list.
//     (2) 'b' is the head node of the second sorted linked list.
// Output: Returns the head node of the merged sorted linked list.
struct ListNode* mergeTwoLists(struct ListNode* a, struct ListNode* b){
    // Create a temporary node to serve as a placeholder for the merged list
    struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tail = temp;

    // Iterate through both lists while they still have elements
    while(a && b){
        // Compare the current values and select the smaller one
        if (a->val < b->val){
            tail -> next = a;
            a = a->next;
        }
        else{
            tail->next = b;
            b = b->next;
        }
        // Move the tail pointer of the merged list
        tail = tail->next;
    }
    // Add any remaining elements from either of the lists
    if (a != NULL){
        tail -> next = a;
    }else{
        tail->next = b;
    }

    // Skip the temporary node and return the merged list
    struct ListNode *head = temp->next;
    free(temp);
    return head;
}

// Name: mergeHelper
// Input(s):
//     (1) 'lists' is a pointer to an array of head nodes of sorted linked lists.
//     (2) 'start' is the integer index value for the starting list.
//     (3) 'end' is the integer index value for the ending list.
// Output: Returns the head node of the merged sorted linked list for the given range.
struct ListNode* mergeHelper(struct ListNode** lists, int start, int end){
    // Base cases: return NULL or single list based on conditions
    if (start > end) return NULL;
    if (start == end) return lists[start];

    // Find the midpoint
    int mid = (start + end)/2;

    // Recursively merge the two halves
    struct ListNode *listA = mergeHelper(lists, start, mid);
    struct ListNode *listB = mergeHelper(lists, mid+1, end);
    return mergeTwoLists (listA, listB);
}

// Name: mergeKLists
// Input(s):
//     (1) 'lists' is a pointer to an array of head nodes of sorted linked lists.
//     (2) 'listsSize' is the integer number of lists to merge.
// Output: Returns the head node of the merged sorted linked list.
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    // Call the helper function with the initial range
    return mergeHelper(lists, 0, listsSize-1);
}
