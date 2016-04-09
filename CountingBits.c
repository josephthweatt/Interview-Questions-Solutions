#include <math.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    *returnSize = num + 1;
    int *result = (int *) malloc(sizeof(int) * (*returnSize));
    result[0] = 0;
    if (num == 0) return result;
    for (int i = 1; i < num + 1; i++) {
        int bits = 0;
        double x = (double) i;
        double y;
        int z;
        while(x > 0) {
            y = log (x) / log (2.0);
            z = (int) y;
            x -= pow(2.0, z);
            bits++;
        }
        result[i] = bits;
    }
    return result;
}
