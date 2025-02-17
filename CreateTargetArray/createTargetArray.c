/* Davey Getchell
 * CS5008 Spring 2023
 * 1389. Create Target Array in the Given Order - Easy 1 point
 * Tags: Array
 * https://leetcode.com/problems/create-target-array-in-the-given-order/
 */

/**
 *  Note: The returned array must be malloced, assume caller calls free(). 
 */

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int* target = (int*)malloc(sizeof(int)*numsSize);
    int i,j;
    for(i = 0; i<numsSize;i++){
        for (j = indexSize-1; j>index[i]; j--){
            target[j] = target [j-1];
        }
        target[index[i]] = nums[i];
    }  
    *returnSize = numsSize;
    return target;
}
