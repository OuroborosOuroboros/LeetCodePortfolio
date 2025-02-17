/* Davey Getchell
 * CS5008 Spring 2023
 * 1672. Richest Customer Wealth - Easy 1 point
 * Tags: Array
 * https://leetcode.com/problems/richest-customer-wealth/
 */


int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int mostWealth=0;
    int i,j;
    for (i=0;i<accountsSize;i++){
        int current = 0;
        for(j=0;j<*accountsColSize;j++){
            current += accounts[i][j];
        }
        if(current>mostWealth){
            mostWealth = current;
        }
    }
    return mostWealth;
}
