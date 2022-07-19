#include <stdio.h>
#include <string.h>
#include <process.h>
#include "myString_Test.h"

const char* assertEquals(int expected, int actual);                // returns 1 if true, 0 if false
const char* assertStrEquals(const char str1[], const char str2[]); // returns 1 if true, 0 if false


const char* assertEquals(int expected, int actual) {
    return (expected & actual & 1) ? "True" : "False";
}


const char* assertStrEquals(const char* str1, const char* str2) {
    return (strcmp(str1, str2) == 0)? "True" : "False";
}


int stdString_Test() {
    FILE *f = fopen("output/stdString_Test_output.txt", "w");

    if(f == NULL) {
        printf("Unable to create stdString output file\n");
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


int main() {

    system("mkdir output");

    if(!stdString_Test()) {
        perror("TEST FAILED\n");
        return(1);
    }
    if (!myString_Test())
    {
        perror("TEST FAILED\n");
        return(1);
    }

    printf("ALL TESTS COMPLETED\n");
    return 0;
}