#include<stdlib.h> //(for declaration of size_t)
size_t strlen1(const char *str); //1
char *strcpy1(char *str1, const char *str2); //2
char *strncpy1(char *str1, const char *str2, size_t n); //3
char *strcat1(char *str1, const char *str2); //4
char *strncat1(char *str1, const char *str2, size_t n); //5
int strcmp1(const char *str1, const char *str2); //6
int strncmp1(const char *str1, const char *str2, size_t n); //7
char *strtok1(char *str1, const char *delim); //8 ****
char *strstr1(const char *hay, const char *needle); //9 
char *strchr1(const char *str1, int c); //10
char *strrchr1(const char *str1, int c ); //11
size_t strspn1(const char *str1, const char *str2); //12
size_t strcspn1(const char *str1, const char *str2); //13 
char *strpbrk1(const char *str1, const char *str2); //14
char *strerror1(int errnum); //15 ****
size_t strcoll1(const char *str1, const char *str2); //16 ****
size_t strxfrm1(char *str1, const char *str2, size_t n); //17 ****
size_t memcmp1(const void *str1, const void *str2, size_t n); //18
void *memchr1(void *str1, int c, size_t n); //19
void *memcpy1(void *str1, const void *str2, size_t n); //20
void *memmove1(void *str1, const void *str2, size_t n); //21		
void *memset1(void *str1, int c, size_t n);  //22
void *memmem1(const void *hay, size_t hl, const void *needle, size_t nl); //23
void *memccpy1(void *str1, const void *str2, int value, size_t len); //24
void *memrchr1(void *str1, int c, size_t n); //25
int ffs1(int value); //26 (returns the first least significant bit )
int ffsl1(long int value); //27
int ffsll1(long long int value); //28
char *strchrnul1(const char *str1, int c); //29
int strcasecmp1(const char *str1, const char *str2); //30
int strncasecmp1(const char *str1, const char *str2, size_t n); //31
char *strlwr1(char *str); //32
char *strupr1(char *str); //33
char *strrev1(char*str); //34
char* mystrtok_r1(char *str, const char *delim, char **saveptr); //35
char *strdup1(const char *s); //36



