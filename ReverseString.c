/**
* Written by: Joseph Thweatt
* Runtime: NA
*/
char* reverseString(char* s) {
    int size = strlen(s);
    char temp;
    printf("%d", size);
    for (int i = 0; i < size/2; i++) {
        temp = s[i];
        s[i] = s[size - 1 - i];
        s[size - 1 - i] = temp;
    }
    return s;
}
