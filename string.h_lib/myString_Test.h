#include <stdio.h>
#include "myString.h"


int myString_Test() {
    FILE* f = fopen("output/myString_Test_output.txt", "w");

    if (f == NULL)
    {
        printf("Unable to create myString output file\n");
        return 0;
    }

    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz\0"; // test string
    const char revalpha[] = "zyxwvutsrqponmlkjihgfedcba\0";
    const char zeros[] = "00000000000000000000000000";

        // tests for memchr
        fprintf(f, "%s\n", (char*)memchr(alphabet, 'a', 26));
    fprintf(f, "%s\n", (char*)memchr(alphabet, 'm', 26));
    fprintf(f, "%s\n", (char*)memchr(alphabet, 'z', 26));


    // tests for memcmp
    fprintf(f, "%d\n", memcmp(alphabet, alphabet, 26));
    fprintf(f, "%d\n", memcmp(alphabet, zeros, 26));
    fprintf(f, "%d\n", memcmp(alphabet, revalpha, 26));

    fclose(f);
    return 1;
}
