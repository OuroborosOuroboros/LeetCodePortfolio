// Name: findMedianSortedArrays
// Input(s):
//     (1) 'nums1' is a pointer to the first sorted integer array.
//     (2) 'nums1Size' is the size of the first sorted array.
//     (3) 'nums2' is a pointer to the second sorted integer array.
//     (4) 'nums2Size' is the size of the second sorted array.
// Output: Returns the median value of the two sorted arrays.
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    // Ensure 'nums1' is the smaller array
    if (nums1Size > nums2Size){
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int x = nums1Size;
    int y = nums2Size;
    int low = 0;
    int high = x;
    
    // Use binary search on the smaller array
    while (low <= high){
        int partitionX = (low+high)/2;
        int partitionY = (x+y+1)/2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        // Check if we found the correct partition
        if (maxX <= minY && maxY <= minX){
            if ((x + y) % 2 == 0){
                return (fmax(maxX, maxY) + fmin(minX, minY)) / 2.0;
            } else {
                return fmax(maxX, maxY);
            }
        }
        // If not, adjust the binary search bounds
        else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    // Return 0.0 if no solution exists
    return 0.0;
}
