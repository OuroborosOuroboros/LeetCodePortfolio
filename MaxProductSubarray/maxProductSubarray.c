int max(int a, int b) {
    if (a >b){
        return a;
    }else {
        return b;
    }
}

int min(int a, int b) {
    if (a<b){
        return a;
    }else {
        return b;
    }
}

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int maxProduct = nums[0];
    int minProductPrev = nums[0];
    int maxProductPrev = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        int temp = maxProductPrev;
        maxProductPrev = max(max(nums[i], maxProductPrev * nums[i]), minProductPrev * nums[i]);
        minProductPrev = min(min(nums[i], temp * nums[i]), minProductPrev * nums[i]);
        maxProduct = max(maxProduct, maxProductPrev);
    }
    return maxProduct;
}
