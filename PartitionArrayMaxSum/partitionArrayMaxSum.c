
int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
    if (arrSize == 0) return 0;
    if (arrSize == 1) return arr[0];

    int memo[arrSize+1];
    memo[0] = 0;

    int i,j;
    for (i =1; i<= arrSize; i++){
        int maxVal = arr[i-1];
        memo[i] = 0;
        for (j=1; j <= k && i-j >= 0; j++){
            maxVal = (arr[i-j]> maxVal) ? arr[i-j]: maxVal;
            int currentSum = memo[i-j] + maxVal * j;
            memo[i] = (currentSum > memo[i]) ? currentSum: memo[i];
        }
    }
    return memo[arrSize];
}
