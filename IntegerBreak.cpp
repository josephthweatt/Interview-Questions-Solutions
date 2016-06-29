/*
* Written by: Joseph Thweatt
* Runtime: NA
* Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. 
* Return the maximum product you can get.
* For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
*/

class Solution {
public:
    int integerBreak(int n) {
        // base case
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }
        
        int max = 0;
        for (int i = 2; i < n - 1; i++) {
            int baseValue = n / i;
            int remainder = n % (baseValue * i);
            int product = (int) pow((double) baseValue, (double) (i - remainder)) *
                pow((double) baseValue + 1, (double) remainder);
            if (product > max) { max = product; };
        }
        return max;
    }
};
