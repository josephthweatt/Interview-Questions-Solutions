#include <stdio.h>
#include <string.h>

char* reverseVowels(char* s) {
    char *vowels = "aeiouAEIOU";
    char temp;
    int back = strlen(s) - 1;
    
    for (int i = 0; i <= back; i++) {
        if (strchr(vowels, s[i])) {
            for (int j = back; j > i; j--) {
                if (strchr(vowels, s[j])) {
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    back = j - 1;
                    break;
                }
            }
        }
    }
    return s;
}