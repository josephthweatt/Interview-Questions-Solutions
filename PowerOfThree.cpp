/*******************************************************************************
* Written by: Joseph Thweatt
* Runtime: NA
* Given an integer, write a function to determine if it is a power of three.
* Follow up:
* Could you do it without using any loop / recursion?
*******************************************************************************/

#include <Math.h>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        } else {
            double x;
            if (modf(log((double) n) / log(3.0), &x) > .9999999999) {
                x++;
            }
            if (pow (3.0, x) == n) {
                return true;
            }
        }
        return false;
    }
};
