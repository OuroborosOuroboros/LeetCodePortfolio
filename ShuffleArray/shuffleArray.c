/* Davey Getchell
 * CS5008 Spring 2023
 * 1470. Shuffle the Array - Easy 1 point
 * Tags: Array
 * https://leetcode.com/problems/shuffle-the-array/
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 *  
 */

int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* array = (int*)malloc(sizeof(int)* numsSize);
    *returnSize = numsSize;
    int x=0;
    int y=0;
    int k=n;
    for(x=0;x<(2*n-1);x+=2){
        array[x] = nums[y++];
        array[x+1]=nums[k++];
    }
    return array;
}


