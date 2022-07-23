#include <stdio.h>
#include <stdlib.h>
#include "myString.h"


int main() {
    FILE *f = fopen("output/myString_Test_output.txt", "w");

    if(f == NULL) {
        printf("Unable to create myString output file\n");
        return 1;
    }

    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz\0";    // test string
    const char evil_alphabet[] = "abcdefghijklmnopqrstuvwxyz\0a01"; // test string with no null char
    const char revalpha[] = "zyxwvutsrqponmlkjihgfedcba\0";
    const char evil_revalpha[] = "zyxwvutsrqponmlkjihgfedcba";
    const char zeros[] = "00000000000000000000000000\0";
    const char evil_zeros[] = "00000000000000000000000000";
    const char byte69[] = "00100101";
    const char byte420[] = "11010100";
    const char byte87[] = "01010111";
    const char byte25[] = "00011001";
    char test[] = "00000000000000000000000000\0";

    // tests for memchr
    fprintf(f, "\nmemchr\n");
    fprintf(f, "\t%s\n", (char*)memchr(alphabet, 'a', 26));
    fprintf(f, "\t%s\n", (char*)memchr(alphabet, 'm', 26));
    fprintf(f, "\t%s\n", (char*)memchr(alphabet, 'z', 26));
    fprintf(f, "\t%s\n", (char*)memchr(evil_alphabet, 'a', 26));
    fprintf(f, "\t%s\n", (char*)memchr(evil_revalpha, 'a', 26));
    fprintf(f, "\t%s\n", (char*)memchr(evil_zeros, '1', 26));
    fprintf(f, "\t%s\n", (char*)memchr(evil_alphabet, '0', 30));

    // tests for memcmp
    fprintf(f, "\nmemcmp\n");
    fprintf(f, "\t%d\n", memcmp(alphabet, alphabet, 26));
    fprintf(f, "\t%d\n", memcmp(alphabet, zeros, 26));
    fprintf(f, "\t%d\n", memcmp(alphabet, revalpha, 26));
    fprintf(f, "\t%d\n", memcmp(alphabet, "a", 26));
    fprintf(f, "\t%d\n", memcmp("z", revalpha, 26));

    // tests for memcpy
    fprintf(f, "\nmemchrcpy\n");
    fprintf(f, "\t%s\n", (char *)memcpy(test, alphabet, 26));
    fprintf(f, "\t%s\n", (char *)memcpy(test, revalpha, 26));
    fprintf(f, "\t%s\n", (char *)memcpy(test, zeros, 26));

    // tests for memmove
    fprintf(f, "\nmemmove\n");
    fprintf(f, "\t%s\n", (char *)memmove(test, alphabet, 26));
    fprintf(f, "\t%s\n", (char *)memmove(test, revalpha, 26));
    fprintf(f, "\t%s\n", (char *)memmove(test, zeros, 26));

    // tests for strcat
    fprintf(f, "\nstrcat\n");
    char* dma = (char*)malloc((4 * 8) + 1);
    *dma = 0;

    dma = (char *)strcat(dma, byte69);
    fprintf(f, "\t%s\n", dma);

    dma = (char *)strcat(dma, byte420);
    fprintf(f, "\t%s\n", dma);

    dma = (char *)strcat(dma, byte87);
    fprintf(f, "\t%s\n", dma);

    dma = (char *)strcat(dma, byte25);
    fprintf(f, "\t%s\n", dma);

    free(dma);


    // tests for strncat
    fprintf(f, "\nstrcat\n");

    dma = (char *)malloc((8 + 6 + 4 + 2) + 1);
    *dma = 0;

    dma = (char *)strncat(dma, byte69, 8);
    fprintf(f, "\t%s\n", dma);

    dma = (char *)strncat(dma, byte420, 6);
    fprintf(f, "\t%s\n", dma);

    dma = (char *)strncat(dma, byte87, 4);
    fprintf(f, "\t%s\n", dma);

    dma = (char *)strncat(dma, byte25, 2);
    fprintf(f, "\t%s\n", dma);

    free(dma);

    // tests for strchr
    fprintf(f, "\nmemchr\n");
    fprintf(f, "\t%s\n", (char *)memchr(alphabet, 'a', 26));
    fprintf(f, "\t%s\n", (char *)memchr(alphabet, 'm', 26));
    fprintf(f, "\t%s\n", (char *)memchr(alphabet, 'z', 26));

    fclose(f);
    return 0;
}