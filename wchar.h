#include<stdlib.h> //(for declaration of wchar_t)
size_t wcslen1(const wchar_t *str1);
wchar_t *wcscpy1(wchar_t * str1, const wchar_t * str2);
wchar_t *wcsncpy1(wchar_t * str1, const wchar_t * str2, size_t n);
wchar_t *wcscat1(wchar_t *str1, const wchar_t *str2);
wchar_t *wcsncat1(wchar_t *str1, const wchar_t *str2, size_t n);
int wcscmp1(const wchar_t *str1, const wchar_t *str2);
int wcsncmp1(const wchar_t *str1, const wchar_t *str2, size_t n);
wchar_t *wcschr1(const wchar_t *str1, wchar_t wc);
wchar_t *wcsrchr1(const wchar_t *str1, wchar_t wc);
size_t wcsspn1(const wchar_t *str1, const wchar_t *str2); 
size_t wcscspn1(const wchar_t *str1, const wchar_t *str2); 
wchar_t *wcspbrk1(const wchar_t *str1, const wchar_t *str2);
wchar_t *wcsstr1(const wchar_t *hay, const wchar_t *needle);
wchar_t *wmemchr1(const wchar_t *str1, wchar_t wc, size_t n);
int wmemcmp1(const wchar_t *str1, const wchar_t *str2, size_t n); 
wchar_t *wmemcpy1(wchar_t *str1, const wchar_t *str2, size_t n);
wchar_t *wmemmove1(wchar_t *str1, const wchar_t *str2, size_t n);
wchar_t *wmemset1(wchar_t *str1, wchar_t wc, size_t n);
wchar_t *wcsdup1(wchar_t *str1);

