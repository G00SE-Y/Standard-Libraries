#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *f = fopen("output/stdString_Test_output.txt", "w");

    if(f == NULL) {
        printf("Unable to create stdString output file\n");
        return 1;
    }

    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz\0"; // test string
    const char revalpha[] = "zyxwvutsrqponmlkjihgfedcba\0";
    const char zeros[] = "00000000000000000000000000\0";
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
    char *dma = (char *)malloc((4 * 8) + 1);
    dma[0] = 0;
    fprintf(f, "\nstrcat\n");
    fprintf(f, "\t%s\n", dma = (char *)strcpy(dma, byte69));
    fprintf(f, "\t%s\n", dma = (char *)strcpy(dma, byte420));
    fprintf(f, "\t%s\n", dma = (char *)strcpy(dma, byte87));
    fprintf(f, "\t%s\n", dma = (char *)strcpy(dma, byte25));

    fclose(f);
    return 0;
}