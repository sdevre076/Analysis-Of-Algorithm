#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    // Loop to slide the pattern one by one
    for (int i = 0; i <= N - M; i++) {
        int j;

        // Check for pattern match at current index i
        for (j = 0; j < M; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }

        // If we reached the end of pat[], we found a match
        if (j == M) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    // Example 1
    char txt1[] = "AABAACAADAABAABA";
    char pat1[] = "AABA";

    // Example 2
    char txt2[] = "agd";
    char pat2[] = "g";

    printf("Example 1:\n");
    search(pat1, txt1);

    printf("\n\nExample 2:\n");
    search(pat2, txt2);

    return 0;
}
