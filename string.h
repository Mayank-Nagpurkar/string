#include<stdlib.h> //(for declaration of size_t)
#include<errno.h> //(for strerror)
size_t strlen1(const char *str); //Calculates the lenth of the string excluding NULL character
char *strcpy1(char *str1, const char *str2); // Copies string 2 into string 1
char *strncpy1(char *str1, const char *str2, size_t n); // Copies n bytes of string 2 into string 1
size_t strlcpy1(char *str1, const char *str2, size_t n); // Copies n bytes of string 2 into string 1 return the length of string 1
char *stpcpy1(char *str1, const char *str2);  // Copies n bytes of string 2 into string 1 returns pointer to the end
char *strcat1(char *str1, const char *str2); //Appends string 2 at the end of string 1
char *strncat1(char *str1, const char *str2, size_t n); //Appends n bytes of string 2 at the end of string 1 
size_t strlcat1(char *str1, const char *str2, size_t n); //Appends n bytes of string 2 at the end of string 1 return length of string 1
int strcmp1(const char *str1, const char *str2); //Compares 2 given strings .
int strncmp1(const char *str1, const char *str2, size_t n); // Compares n bytes of 2 given strings.
char *strtok1(char *str1, const char *delim); //Separates the given string on the basis of a delimiter
char *strstr1(const char *hay, const char *needle); //finds the substring in the given string
char *strcasestr1(const char *hay,const char *needle); //finds the substring in the given string ignoring the case
char *strchr1(const char *str1, int c); //finds the first occurance of a character in a stirng
char *strrchr1(const char *str1, int c ); //finds the last occurance of a character in a stirng
size_t strspn1(const char *str1, const char *str2); //finds the length of str1 which contains character of str2
size_t strcspn1(const char *str1, const char *str2);  //finds the length of str1 which does not contains character of str2
char *strpbrk1(const char *str1, const char *str2); //Returs pointer to the str1 containing character from str 2
char *strerror1(int errnum); //Prints error message for the given errno
int strcoll1(const char *str1, const char *str2); //Compares two strings bases on locales
size_t strxfrm1(char *str1, const char *str2, size_t n); //17 Copies n bytes in str1 after coverting to current locale and returns len of string 2
size_t memcmp1(const void *str1, const void *str2, size_t n); //Compares n bytes of 2 strings(memory block)
void *memchr1(void *str1, int c, size_t n); // Searches in first n bytes for the given char c
void *memcpy1(void *str1, const void *str2, size_t n); // Copies n bytes of 2 given strings (mem block)
void *memmove1(void *str1, const void *str2, size_t n); //Copies n bytes of 2 given strings (prevents overlapping)		
void *memset1(void *str1, int c, size_t n);  //sets the first n bytes as given no
void *memmem1(const void *hay, size_t hl, const void *needle, size_t nl); //finds the substring
void *memccpy1(void *str1, const void *str2, int value, size_t len); //copies atmost n bytes stoppong when value is found
void *memrchr1(void *str1, int c, size_t n); //finds the last occurance of a character in a stirng
void *memfrob1(void *str1, size_t n); //encrypt an area of memory by exoring with 42.
int ffs1(int value); // (returns the first least significant bit )
int ffsl1(long int value);  // (returns the first least significant bit )
int ffsll1(long long int value); // (returns the first least significant bit )
char *strchrnul1(const char *str1, int c); //finds character in a string 
int strcasecmp1(const char *str1, const char *str2); //compares character ignoring case
int strncasecmp1(const char *str1, const char *str2, size_t n); //compares n charcaters ignoring case
char *strlwr1(char *str); //converts string to lower case
char *strupr1(char *str); //converts sting to upper case
char *strrev1(char*str); //reverses the given string
char* mystrtok_r1(char *str, const char *delim, char **saveptr); //seperates the string based on delimiter
char *strdup1(const char *s); //duplicates the given string
char *strndup1(const char *s, size_t n); //duplicates n character of the given string
char *strfry1(char *str); //randomly arranges the string characters
char *index1(const char *str, int c); //return pointer to first occerance of c
char *rindex1(const char *str, int c); //returns pointer to last occurance of c
void bzero1(void *s, int n); //makes the first n bytes zero
int bcmp1(const void *str1, const void *str2, int n); //compares n bytes
void bcopy1(const void *str1, void *str2, int n); // copies n bytes
char *strsep2(char **str, const char *delim); //same as strtok but can also handle empty fields
