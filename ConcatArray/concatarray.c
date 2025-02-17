/* Davey Getchell
 * CS 5008 Spring 2023
 * 1929. Concatenation of Array - Easy 1 point
 * Tags: Array
 * https://leetcode.com/problems/concatenation-of-array/
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* getConcatenation(int* nums, int numsSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*numsSize*2);
    int i = 0;

    for (i=0;i<numsSize;i++){
        ans[i] = nums[i];
        ans[i+numsSize]= nums[i];
    }

    *returnSize = numsSize*2;

    return ans;
}
