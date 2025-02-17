/* Davey Getchell
 * CS5008 Spring 2023
 * 1769. Minimum Number of Operations to Move All Balls to Each Box - Medium 2 ppoints
 * Tags: Array
 * https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* minOperations(char * boxes, int* returnSize){
    if(boxes==NULL){
        return NULL;
    }
    int length = strlen(boxes);
    int* array = (int*)malloc(length*sizeof(int));
    if (array==NULL){
        return NULL;
    }
    int i,j;
    for(i=0;i<length;i++){
         int count = 0;
         for (j=0;j<length;j++){
            if (boxes[j] == '1'){
                count += abs(i-j);
            }
        }
        array[i] = count;
    }
    *returnSize = length;
    return array;
}
