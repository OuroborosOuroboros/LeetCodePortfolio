/* Davey Getchell
 * CS 5008 Spring 2023
 * 1480. Running Sum of 1d Array - Easy 1 point
 * Tags: Array
 * https://leetcode.com/problems/running-sum-of-1d-array/
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *   
 */

int* runningSum(int* nums, int numsSize, int* returnSize){
    int* array = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    int i,j;
    for (i=0;i<numsSize;i++){
        array[i] = 0;
    }
    array[0] = nums[0];
    for(i=1;i<numsSize;i++){
        array[i] = array[i-1]+nums[i];
    }    
    return array;
}
