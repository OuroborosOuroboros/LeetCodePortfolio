/* Davey Getchell
 * CS5008 Spring 2023
 * 119. Pascal's Triangle - Easy 1 point
 * Tags: Array, Dynamic Programming
 * https://leetcode.com/problems/pascals-triangle-ii/
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    long answer = 1;
    int* array = (int*)malloc((rowIndex+1)*sizeof(int));
    array[0] = 1;
    int i,j,k;
    for (k=1;k<rowIndex+1;k++){
        array[k] = (long) 0;
    }
    for(i=1;i<=rowIndex;i++){
        array[i] = 1;
        for (j=1;j<i;j++){
            array[j] = answer + array[j];
            answer = array[j] - answer;
        }
    }
    *returnSize = rowIndex +1;
    return array;
}
