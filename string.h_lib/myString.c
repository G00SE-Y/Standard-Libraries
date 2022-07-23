/* RFERENCE MATERIAL
 * https://www.tutorialspoint.com/c_standard_library/string_h.htm
 */

#define null ((void*)0) // * I hate the all caps 'NULL', so im using 'null'
#define size_t unsigned long long
#define errno_t int

void *memchr(const void* str, int c, size_t n);
int memcmp(const void* str1, const void* str2, size_t n);
void *memcpy(void* dest, const void* src, size_t n);
void *memmove(void* dest, const void* src, size_t n);
void *memset(void* str, int c, size_t n);
char *strcat(char* dest, const char* src);
char *strncat(char* dest, const char* src, size_t n);
char *strchr(const char* str, int c);
int strcmp(const char* str1, const char* str2);
// int strncmp(const char* str1, const char* str2, size_t n); // Compares at most the first n bytes of str1 and str2.
// int strcoll(const char* str1, const char* str2); // Compares string str1 to str2. The result is dependent on the LC_COLLATE setting of the location.
// char *strcpy(char* dest, const char* src); // Copies the string pointed to, by src to dest.
// char *strncpy(char* dest, const char* src, size_t n); // Copies up to n characters from the string pointed to, by src to dest.
// size_t strcspn(const char* str1, const char* str2); // Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
// char *strerror(int errnum); // Searches an internal array for the error number errnum and returns a pointer to an error message string.
// size_t strlen(const char* str); // Computes the length of the string str up to but not including the terminating null character.
// char *strpbrk(const char* str1, const char* str2); // Finds the first character in the string str1 that matches any character specified in str2.
// char *strrchr(const char* str, int c); // Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str.
// size_t strspn(const char* str1, const char* str2); // Calculates the length of the initial segment of str1 which consists entirely of characters in str2.
// char *strstr(const char* haystack, const char* needle); // Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack.
// char *strtok(char* str, const char* delim); // Breaks string str into a series of tokens separated by delim.
// size_t strxfrm(char* dest, const char* src, size_t n); // Transforms the first n characters of the string src into current locale and places them in the string dest.

/* EXTENSIONS REFERENCE MATERIAL
 * https://en.wikibooks.org/wiki/C_Programming/string.h
 */

// void *memccpy(void *dest, const void *src, int c, size_t n); // copies up to n bytes between two memory areas, which must not overlap, stopping when the byte c is found 
// void *mempcpy(void *dest, const void *src, size_t n); // variant of memcpy returning a pointer to the byte following the last written byte
// errno_t strcat_s(char *dest, size_t n, const char *src); // bounds - checked variant of strcat
// errno_t strcpy_s(char *dest, size_t n, const char *src); // bounds - checked variant of strcpy
// char *strdup(const char *src); // allocates and duplicates a string into memory POSIX;
// int strerror_r(int, char *, size_t); // Puts the result of strerror() into the provided buffer in a thread - safe way.
// char *strerror_r(int, char *, size_t); // Return strerror() in a thread - safe way.The provided buffer is used only if necessary (incompatible with POSIX version).
// size_t strlcat(char *dest, const char *src, size_t n); // bounds - checked variant of strcat
// size_t strlcpy(char *dest, const char *src, size_t n); // bounds - checked variant of strcpy
// char *strsignal(int sig); // by analogy to strerror, returns string representation of the signal sig(not thread safe) 
// char *strtok_r(char *, const char *delim, char **saveptr); // thread - safe and reentrant version of strtok


/*
 * Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str. 
 */
void * memchr(const void *str, int c, size_t n)
{

    char x = -1;
    char* loc = (char*) str;
    for (size_t i = 0; (i < n); i++, loc++) {
        x = *loc;

        if(x == c) {
            return loc;
        }
    }
    return null;
}


/* 
 *Compares the first n bytes of str1 and str2. 
 */
int memcmp(const void *str1, const void *str2, size_t n) {
    
    int diff = 0;
    char x,y;

    for(size_t i = 0; i<n; i++) {
        x = *(char*)(str1 + i);
        y = *(char*)(str2 + i);

        if(x == 0 || y == 0) return ((x==0)? -1 : 1);

        diff += x - y; 
    }

    return ((diff>0) ? 1 : -1);
}


/* 
 * Copies n characters from src to dest. 
 */
void *memcpy(void *dest, const void *src, size_t n) {
    
    for (size_t i = 0; i < n; i++)
    {
        *(char *)(dest + i) = 0x00000000;
        *(char *)(dest + i) = *(char *)(dest + i) | *(char *)(src + i);
    }

    return dest;
}


/* 
 * Another function to copy n characters from str2 to str1 using an intermediate buffer. (safer than memcpy) 
 */
void *memmove(void *dest, const void *src, size_t n) {

    char buf = 0;

    for (size_t i = 0; i < n; i++)
    {
        buf = *(char *)(src + i);
        *(char *)(dest + i) = 0x00000000;
        *(char *)(dest + i) = *(char *)(dest + i) | buf;
    }

    return dest;
}


/*
 * Appends the string pointed to, by src to the end of the string pointed to by dest. 
 */
char *strcat(char *dest, const char *src) {

    char* tmp = dest;
    size_t i = 0;

    while(*dest != 0) { ++dest; }

    for ( ; src[i] != 0; i++) {
        *dest = src[i];
        dest++;
    }

    *dest = 0;

    return tmp;
}


/* 
 * Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. 
 */
char *strncat(char *dest, const char *src, size_t n) {

    char *tmp = dest;
    size_t i = 0;

    while (*dest != 0) {
        ++dest;
    }

    for (; src[i] != 0 && i < n; i++) {
        *dest = src[i];
        dest++;
    }

    *dest = 0;

    return tmp;
}


/* 
 * Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. 
 */
char *strchr(const char *str, int c) {

    char x = -1;
    char *loc = (char *)str;

    for (size_t i = 0; (x != 0); i++, loc++) {
        x = *loc;

        if (x == c) {
            return loc;
        }
    }
    return null;
}


/*
 * Compares the string pointed to, by str1 to the string pointed to by str2.
 */
int strcmp(const char *str1, const char *str2) {

    int diff = 0;
    char x, y;

    for (size_t i = 0; x != 0 || x != 0; i++) {
        x = str1[i];
        y = str2[i];

        if (x == 0 || y == 0)
            return ((x == 0) ? -1 : 1);

        diff += x - y;
    }

    return ((diff > 0) ? 1 : -1);
}