/**************************************************************
 * Written by: Joseph Thweatt
 * Runtime: 0.5 ms
 * You are a product manager and currently leading a team to 
 * develop a new product. Unfortunately, the latest version of 
 * your product fails the quality check. Since each version is 
 * developed based on the previous version, all the versions 
 * after a bad version are also bad.
 * 
 * Example: Suppose you have n versions [1, 2, ..., n] and you 
 * want to find out the first bad one, which causes all the 
 * following ones to be bad.
 * 
 * Note: This was solved using a binary search method. Linear
 * search for the same question would have caused the question
 * to time out.
 *************************************************************/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    if (n == 1) {
        return 1;
    }
    
    long int i;
    long int num = 1, den = 2;
    while (true) {
        i = (int) (n * (((long double) num) / den));
        if (isBadVersion(i)) {
            if (!isBadVersion(i - 1)) {
                printf("%d", i);
                return i;
            } else {
                num = (num*2-1 > 1) ? num*2-1 : 1;
                den = den * 2;
            }
        } else {
            den = den * 2;
            if ((int) ((((long double) num*2+1)/den)*n) == i) {
                num = den;
            } else {
                num = num*2+1;
            }
        }
    }
    return 1;
}