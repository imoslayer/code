#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastIndex[128];

    for (int i = 0; i < 128; i++) {
        lastIndex[i] = -1;
    }

    int maxLength = 0;
    int start = 0;

    for (int end = 0; s[end] != '\0'; end++) {

        if (lastIndex[(int)s[end]] >= start) {
            start = lastIndex[(int)s[end]] + 1;
        }

        lastIndex[(int)s[end]] = end;

        int length = end - start + 1;

        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}