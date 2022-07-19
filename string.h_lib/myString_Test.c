#include <stdio.h> //TODO: replace this
#include "myString.h"
//#include <string.h>


const char* assertEquals(int expected, int actual); // returns 1 if true, 0 if false
const char* assertStrEquals(const char str1[], const char str2[]); // returns 1 if true, 0 if false


int main(void) {
    const char alphabet[]  = "abcdefghijklmnopqrstuvwxyz\0";

    // printf("%30s == %30s : %s\n", "a", "a", assertEquals('a', 'a'));
    // printf("%30s == %30s : %s\n", alphabet, alphabet, assertStrEquals(alphabet, alphabet));

    printf("\n%s\n", (char*)memchr(alphabet, 'a', 26));
    printf("\n%s\n", (char*)memchr(alphabet, 'm', 26));
    printf("\n%s\n", (char*)memchr(alphabet, 'z', 26));
}

const char* assertEquals(int expected, int actual)
{
    return (expected & actual & 1)? "True":"False";
}

// const char* assertStrEquals(const char* str1, const char* str2)
// {
//     return (strcmp(str1, str2) == 0)? "True" : "False";
// }