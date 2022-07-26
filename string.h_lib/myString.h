#define null ((void *)0)
#define size_t unsigned long long
#define errno_t int

// * STANDARD LIBRARY FUNCTIONS
void *memchr(const void *str, int c, size_t n);
int memcmp(const void *str1, const void *str2, size_t n);
void *memcpy(void *dest, const void *src, size_t n);       
void *memmove(void *dest, const void *src, size_t n);      
void *memset(void *str, int c, size_t n);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
char *strchr(const char *str, int c);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
size_t strcspn(const char *str1, const char *str2);
char *strerror(int errnum);
size_t strlen(const char *str);
char *strpbrk(const char *str1, const char *str2);
char *strrchr(const char *str, int c);
size_t strspn(const char *str1, const char *str2);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);

// * EXTENDED LIBRARY FUNCTIONS
void* memccpy(void *dest, const void *src, int c, size_t n);
void* mempcpy(void *dest, const void *src, size_t n);
errno_t strcat_s(char *dest, size_t n, const char *src);
errno_t strcpy_s(char *dest, size_t n, const char *src);
char* strdup(const char *src);
int strerror_r(int, char *, size_t);
size_t strlcat(char *dest, const char *src, size_t n);
size_t strlcpy(char *dest, const char *src, size_t n);
char* strsignal(int sig);
char* strtok_r(char *, const char *delim, char **saveptr);