/********************************************************
* Written by: Joseph Thweatt
* Runtime: NA
* Given an array nums, write a function to move all 0's 
* to the end of it while maintaining the relative order
* of the non-zero elements.
* For example, given nums = [0, 1, 0, 3, 12], after 
* calling your function, nums should be [1, 3, 12, 0, 0].
*********************************************************/

void moveZeroes(int* nums, int numsSize) {
    int temp;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] != 0) {
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    break;
                }
            }
        }
    }
    
}
