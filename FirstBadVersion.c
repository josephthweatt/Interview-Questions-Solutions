// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    if (n == 1) {
        return 1;
    }
    
    int i;
    int num = 1, den = 2;
    while (true) {
        i = (int) (n * (((double) num) / den));
        printf("%d %d %d %d\n", num, den, n, (int) (n * (((double) num) / den)));
        if (isBadVersion(i)) {
            if (!isBadVersion(i - 1)) {
                printf("%d", i);
                return i;
            } else {
                num += (num*2-1 > 1) ? num*2-1 : 1;
                den = den * 2;
            }
        } else {
            den = den * 2;
            if (((num*2+1)/den)*n == i) {
                num = den;
            } else {
                num = num*2+1;
            }
        }
    }
    return 1;
}