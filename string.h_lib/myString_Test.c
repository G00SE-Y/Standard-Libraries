#include <stdio.h>
#include <stdlib.h>
#include "myString.h"


int main() {
    FILE *f = fopen("output/myString_Test_output.txt", "w");

    if(f == NULL) {
        printf("Unable to create myString output file\n");
        return 1;
    }

    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz\0";   // test string
    const char malphabet[] = "abcdefghijklmnopqrstuvwxyz"; // test string with no null char
    const char revalpha[] = "zyxwvutsrqponmlkjihgfedcba\0";
    const char mrevalpha[] = "zyxwvutsrqponmlkjihgfedcba";
    const char zeros[] = "00000000000000000000000000\0";
    const char mzeros[] = "00000000000000000000000000";
    const char byte69[] =  "00100101\0";
    const char byte420[] = "11010100\0";
    const char byte87[] =  "01010111\0";
    const char byte25[] =  "00011001\0";
    char test[] = "00000000000000000000000000\0"; // different from zeros because it's not const

    // * tests for memchr
    fprintf(f, "\nmemchr\n");
    fprintf(f, "\t%s\n", (char*)memchr(malphabet, 'a', 26));
    fprintf(f, "\t%s\n", (char*)memchr(malphabet, 'm', 26));
    fprintf(f, "\t%s\n", (char*)memchr(malphabet, 'z', 26));
    fprintf(f, "\t%s\n", (char*)memchr(mzeros, '1', 26));

    // * tests for memcmp
    fprintf(f, "\nmemcmp\n");
    fprintf(f, "\t%d\n", memcmp(malphabet, malphabet, 26));
    fprintf(f, "\t%d\n", memcmp(malphabet, mzeros, 26));
    fprintf(f, "\t%d\n", memcmp(malphabet, mrevalpha, 26));
    fprintf(f, "\t%d\n", memcmp(malphabet, "a", 26));
    fprintf(f, "\t%d\n", memcmp("z", mrevalpha, 26));

    // * tests for memcpy
    fprintf(f, "\nmemchrcpy\n");
    fprintf(f, "\t%s\n", (char *)memcpy(test, malphabet, 26));
    fprintf(f, "\t%s\n", (char *)memcpy(test, mrevalpha, 26));
    fprintf(f, "\t%s\n", (char *)memcpy(test, mzeros, 26));

    // * tests for memmove
    fprintf(f, "\nmemmove\n");
    fprintf(f, "\t%s\n", (char *)memmove(test, malphabet, 26));
    fprintf(f, "\t%s\n", (char *)memmove(test, mrevalpha, 26));
    fprintf(f, "\t%s\n", (char *)memmove(test, mzeros, 26));

    // * tests for strcat
    fprintf(f, "\nstrcat\n");
    char* dma = (char*)calloc((4 * 8) + 1, 1);
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

    // * tests for strncat
    fprintf(f, "\nstrcat\n");

    dma = (char *)calloc((8 + 6 + 4 + 2) + 1, 1);
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

    // * tests for strchr
    fprintf(f, "\nstrchr\n");
    fprintf(f, "\t%s\n", (char *)memchr(alphabet, 'a', 26));
    fprintf(f, "\t%s\n", (char *)memchr(alphabet, 'm', 26));
    fprintf(f, "\t%s\n", (char *)memchr(alphabet, 'z', 26));

    // * tests for strcmp
    fprintf(f, "\nstrcmp\n");
    fprintf(f, "\t%d\n", strcmp(alphabet, alphabet));
    fprintf(f, "\t%d\n", strcmp(alphabet, zeros));
    fprintf(f, "\t%d\n", strcmp(alphabet, revalpha));
    fprintf(f, "\t%d\n", strcmp(alphabet, "a"));
    fprintf(f, "\t%d\n", strcmp("z", revalpha));

    // * tests for strncmp
    fprintf(f, "\nstrncmp\n");
    fprintf(f, "\t%d\n", strncmp(alphabet, alphabet, 26));
    fprintf(f, "\t%d\n", strncmp(alphabet, zeros, 26));
    fprintf(f, "\t%d\n", strncmp(alphabet, revalpha, 26));
    fprintf(f, "\t%d\n", strncmp(alphabet, "a", 26));
    fprintf(f, "\t%d\n", strncmp("z", revalpha, 26));

    // * tests for strcpy
    fprintf(f, "\nstrcpy\n");
    dma = (char *)calloc(50,1);

    fprintf(f, "\t%s\n", strcpy(dma, alphabet));
    fprintf(f, "\t%s\n", strcpy(dma, revalpha));
    fprintf(f, "\t%s\n", strcpy(dma, zeros));
    fprintf(f, "\t%s\n", strcpy(dma, byte69));

    free(dma);

    // * tests for strncpy
    fprintf(f, "\nstrncpy\n");
    dma = (char*)calloc(50,1);

    strncpy(dma, alphabet, 5);
    fprintf(f, "\t%s\n", dma);

    strncpy(dma+5, revalpha, 5);
    fprintf(f, "\t%s\n", dma);

    strncpy(dma+10, zeros, 5);
    fprintf(f, "\t%s\n", dma);

    strncpy(dma+15, byte69, 4);
    fprintf(f, "\t%s\n", dma);

    free(dma);

    // * tests for strcspn
    fprintf(f, "\nstrcspn\n");
    fprintf(f, "\t%lld\n", strcspn(byte69, zeros));
    fprintf(f, "\t%lld\n", strcspn(byte420, zeros));
    fprintf(f, "\t%lld\n", strcspn(byte87, zeros));
    fprintf(f, "\t%lld\n", strcspn(byte25, zeros));
    fprintf(f, "\t%lld\n", strcspn(alphabet, "ebdac\0"));

    // * tests for strspn
    fprintf(f, "\nstrspn\n");
    fprintf(f, "\t%lld\n", strspn(byte69, zeros));
    fprintf(f, "\t%lld\n", strspn(byte420, zeros));
    fprintf(f, "\t%lld\n", strspn(byte87, zeros));
    fprintf(f, "\t%lld\n", strspn(byte25, zeros));
    fprintf(f, "\t%lld\n", strspn(alphabet, "ebdac\0"));

    // * tests for strerror
    fprintf(f, "\nstrerror\n");
    for(int x = 0; x < sys_nerr + 1; x++ ) {
        fprintf(f, "\t%s\n", strerror(x));
    }

    // * tests for strlen
    fprintf(f, "\nstrlen\n");
    fprintf(f, "\t%lld\n", strlen(alphabet));
    fprintf(f, "\t%lld\n", strlen(revalpha));
    fprintf(f, "\t%lld\n", strlen(zeros));
    fprintf(f, "\t%lld\n", strlen(byte87));

    // * tests for strpbrk
    fprintf(f, "\nstrpbrk\n");
    fprintf(f, "\t%s\n", strpbrk(alphabet, "xyz\0"));
    fprintf(f, "\t%s\n", strpbrk(revalpha, "pfr\0"));
    fprintf(f, "\t%s\n", strpbrk(zeros, "12345\0"));
    fprintf(f, "\t%s\n", strpbrk(byte420, "1\0"));

    fclose(f);
    return 0;
}