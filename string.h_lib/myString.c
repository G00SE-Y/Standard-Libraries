/* RFERENCE MATERIAL
 * https://www.tutorialspoint.com/c_standard_library/string_h.htm
 */

#define null ((void*)0) // * I hate the all caps 'NULL', so im using 'null'
#define size_t unsigned long long
#define errno_t int


int strcoll(const char *str1, const char *str2);
size_t strxfrm(char *dest, const char *src, size_t n);
size_t strxfrm(char* dest, const char* src, size_t n); // Transforms the first n characters of the string src into current locale and places them in the string dest.

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
void* memchr(const void *str, int c, size_t n) {

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
void* memcpy(void *dest, const void *src, size_t n) {
    
    for (size_t i = 0; i < n; i++)
    {
        *(char *)(dest + i) = 0;
        *(char *)(dest + i) = *(char *)(dest + i) | *(char *)(src + i);
    }

    return dest;
}


/* 
 * Another function to copy n characters from str2 to str1 using an intermediate buffer. (safer than memcpy) 
 */
void* memmove(void *dest, const void *src, size_t n) {

    char buf = 0;

    for (size_t i = 0; i < n; i++)
    {
        buf = *(char *)(src + i);
        *(char *)(dest + i) = 0;
        *(char *)(dest + i) = *(char *)(dest + i) | buf;
    }

    return dest;
}

/* 
 * Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.
 */
void* memset(void* str, int c, size_t n) {

    if(n == 0) return str;
    
    char* ptr = (char*)str;

    for(size_t i = 0; i < n; i++) {
        *(char*)(ptr + i) = 0;
        *(char*)(ptr + i) = *(char*)(ptr + i) | c;
    }

    return (void*)ptr;

}

/*
 * Appends the string pointed to, by src to the end of the string pointed to by dest. 
 */
char* strcat(char *dest, const char *src) {

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
char* strncat(char *dest, const char *src, size_t n) {

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
char* strchr(const char *str, int c) {

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

    int x, y;

    for (size_t i = 0; x != 0 && x != 0; i++) {
        x = str1[i];
        y = str2[i];

        if (x < y) return -1;
        else if (x > y) return 1;
    }

    if(x == 0 && y == 0) return 0;
    return (x == 0)? -1 : 1;
}


/*
 * Compares at most the first n bytes of str1 and str2.
 */
int strncmp(const char *str1, const char *str2, size_t n) {

    int x, y;

    for (size_t i = 0; (x != 0 && x != 0) && i < n; i++) {
        x = str1[i];
        y = str2[i];

        if (x < y) return -1;
        else if (y < x) return 1;
    }

    if (x == 0 && y == 0) return 0;
    return (x == 0) ? 1 : -1;
}


/*
 * Copies the string pointed to, by src to dest. (unsafe)
 */
char* strcpy(char *dest, const char *src) {

    char* tmp = dest;
    size_t i;

    for(i = 0; src[i] != 0; i++) {
        dest[i] = src[i];
    }
    dest[i] = 0;

    return tmp;
}


/*
 * Copies up to n characters from the string pointed to, by src to dest.
 */
char* strncpy(char *dest, const char *src, size_t n) {

    char* tmp = dest;
    size_t i;

    for(i = 0; src[i] != 0 && i < n; i++) {
        dest[i] = src[i];
    }
    // dest[i] = 0;

    return tmp;
}

/* 
 * Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
 */
size_t strcspn(const char* str1, const char* str2) {
    
    size_t count = 0;

    for(size_t i = 0; str1[i] != 0; i++) {

        int found = 0;

        for(size_t j = 0; str2[j] != 0; j++) {
            if(str1[i] == str2[j]) {
                found++;
                break;
            }
        }

        if(found) break;
        else count++;
    }

    return count;
}

/* 
 * Calculates the length of the initial segment of str1 which consists entirely of characters not in str2.
 */
size_t strspn(const char* str1, const char* str2) {
    
    size_t count = 0;

    for(size_t i = 0; str1[i] != 0; i++) {

        int found = 0;

        for(size_t j = 0; str2[j] != 0; j++) {
            if(str1[i] == str2[j]) {
                found++;
                break;
            }
        }

        if(!found) break; // ? only difference between strcspn and strspn
        else count++;
    }

    return count;
}

 /* 
  * global error message array used by strerror() 
  */
char* error_msgs[] = {
"No error",
"Operation not permitted",
"No such file or directory",
"No such process",
"Interrupted function call",
"Input/output error",
"No such device or address",
"Arg list too long",
"Exec format error",
"Bad file descriptor",
"No child processes",
"Resource temporarily unavailable",
"Not enough space",
"Permission denied",
"Bad address",
"Unknown error",
"Resource device",
"File exists",
"Improper link",
"No such device",
"Not a directory",
"Is a directory",
"Invalid argument",
"Too many open files in system",
"Too many open files",
"Inappropriate I/O control operation",
"Unknown error",
"File too large",
"No space left on device",
"Invalid seek",
"Read-only file system",
"Too many links",
"Broken pipe",
"Domain error",
"Result too large",
"Unknown error",
"Resource deadlock avoided",
"Unknown error",
"Filename too long",
"No locks available",
"Function not implemented",
"Directory not empty",
"Illegal byte sequence",
"Unknown error"
};

/* 
 * Searches an internal array for the error number errnum and returns a pointer to an error message string.
 */
char* strerror(int errnum){

    if(errnum < 0 || errnum > 42) return error_msgs[43];
    else return error_msgs[errnum];

}

/* 
 * Computes the length of the string str up to but not including the terminating null character.
 */
size_t strlen(const char* str){

    size_t len = 0;

    while(str[len] != 0) len++;

    return len;
}

/*
 * Finds the first character in the string str1 that matches any character specified in str2.
 */
char* strpbrk(const char* str1, const char* str2) {

    char* ret = (char*)str1;

    while(*ret != 0) {
        for(size_t i = 0; str2[i] != 0; i++) {
            if(*ret == str2[i]) return ret;
        }
        ret++;
    }
    return null;
}

/* 
 * Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str.
 */
char* strrchr(const char* str, int c) {

    size_t pos = 0, i;
    int found = 0;

    for(i = 0; str[i] != 0; i++) {
        if( str[i] == c) {
            found = 1;
            pos = i;
        }
    }

    return (found)? (char*)(str + pos) : null;
}

/* 
 * Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack.
 */
char* strstr(const char* haystack, const char* needle){

    size_t i, j, pos;
    int found = 0;
    
    for(i = 0; haystack[i] != 0; i++) {
        if(haystack[i] == needle[0]) {
            pos = i;

            for(j = 0; needle[j] != 0; j++, i++) {

                if(haystack[i] == needle[j] && needle[j+1] == 0) found = 1;
                else if(haystack[i] != needle[j]) break;
            }
        }

        if (found) break;
    }

    return (found)? (char*)(haystack + pos) : null;
}


char* prev_ptr = null; // ? keeps a pointer to the last used str in strtok()

/* 
 * Breaks string str into a series of tokens separated by delim. 
 * The delim array is treated as an array of single character tokens
 */
char* strtok(char* str, const char* delim) {

    if(str != null) prev_ptr = str;
    else if(prev_ptr == null) return null;

    char* cur_ptr = prev_ptr; // ? tracks the current token's start position

    for( ; *prev_ptr != 0; prev_ptr++) {
        for(size_t i = 0; delim[i] != 0; i++) {

            if(*prev_ptr == delim[i]) {

                *prev_ptr = 0;
                prev_ptr++;
                return cur_ptr;
            }
            else if(*(prev_ptr + 1) == 0) {
                prev_ptr = null;
                return cur_ptr;
            }
        }
    }

    return null;

}

