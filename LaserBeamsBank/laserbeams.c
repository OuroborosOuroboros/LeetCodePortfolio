/* Davey Getchell
 * CS 5008 Spring 2023
 * 2125. Number of Laser Beams in a Bank - Medium 2 points
 * Tags: Array
 * https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
 */

int numberOfBeams(char ** bank, int bankSize){
    int totalBeams[bankSize];
    
    int result=0;
    int mult = 1;
    int k = 0;
    int i,j;
    for (i=0;i<bankSize;i++){
        int count =0;
        for(j=0;bank[i][j]!='\0';j++){
            if(bank[i][j]=='1'){
                count++;
            }
        }if(count!=0){
            totalBeams[k]=count;
            k++;
        }
    }
    for (i=0;i<k-1;i++){
        mult = totalBeams[i]*totalBeams[i+1];
        result = result+mult;
        mult = 1;
    }
    return result;
}
