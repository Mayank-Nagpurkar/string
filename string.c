#include "string.h"
#include<stdio.h>   //for testing of my own code
#include <stddef.h> //for declaration of NULL pointer
#include <stdlib.h> //for declaration of size_t
#include <sys/cdefs.h> //for wchar
size_t strlen1(const char *str) {
	int i = 0;
	const char *p = str;
	while(*str != '\0') {
		str++;
		i++;
	}
	str = p;
	return i;
}

char *strcpy1(char *str1, const char *str2) {
	char *p = str1;
	while(*str2 != '\0') {
		*str1 = *str2;
		 str1++;
		 str2++;
	}
	*str1 = '\0';
	str1 = p;
	return str1;
}
char *strncpy1(char *str1, const char* str2, size_t n) {
	int i = 0;
	char *p = str1;
	while(i != n) {
		if(*str2 != '\0') {
			*str1 = *str2;

			 str1++;
			 str2++;
			 i++;
		}
		if(*str2 == '\0')
			break;
	}
	*str1 = '\0';
	str1 = p;
	return str1;
}
size_t strlcpy1(char *str1, const char *str2, size_t n) {
	int l1,l2;
	char *p;
	p = str1;
	l1 = strlen1(str1);
	l2 = strlen1(str2);
	if(n <= 0)
		return l1;
	l1 = 0;
	while(l1 < n) {
		*p = *str2;
		if(*str2 == '\0')
			break;
		p++;
		l1++;
		str2++;
	}
	*p = '\0';
	return l1; 
}
char *stpcpy1(char *str1, const char *str2) {
	char *p;
	strcpy1(str1, str2);
	p = str1 + strlen1(str1);
	return p;
}
char *strcat1(char *str1, const char *str2) {
	char *p;
	p = str1;	
	while(*str1 != '\0') {
		str1++;
	}
	while(*str2 != '\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	str1 = p;
	return str1;
}
char *strncat1(char *str1, const char *str2, size_t n) {
	char *p;
	int i = 0;
	p = str1;
	while(*str1 != '\0') {
		str1++;
	}
	while(i != n) {
		if(*str2 != '\0') {
			*str1 = *str2;
			str1++;
			str2++;
			i++;
		}
		if(*str2 == '\0') {
			break;
		}
	}
	*str1 = '\0';
	str1 = p;
	return str1;
}
size_t strlcat1(char *str1, const char *str2, size_t n) {
	int l1,l2, l3;
	char *p;
	p = str1 + (strlen1(str1));
	l1 = strlen1(str1);
	l2 = strlen1(str2);
	l3 = l1 + n;
	if(n <= 0)
		return l1;
	while(l1 != l3) {
		*p = *str2;
		p++;
		l1++;
		str2++;
	}
	*p = '\0';
	return l1; 
}
int strcmp1(const char *str1, const char *str2) {
	while(*str1 == *str2) {
		str1++;
		str2++;
		if(*str1 == '\0' && *str2 == '\0')
			return 0;
	}
	if(*str1 - *str2 > 0)
		return (*str1 - *str2);
	else
		return (*str1 - *str2);	
}
int strncmp1(const char *str1, const char *str2, size_t n) {
	int i = 0;
	while(1) {
		if(*str1 == *str2) {
			str1++;
			str2++;
			i++;
		}
		if(i == n) 
			break;
		if(*str1 == '\0' && *str2 == '\0')
			return 0;
		if(*str1 - *str2 > 0)
                	return (*str1 - *str2);
        	else if(*str1 - *str2 < 0 )
                	return (*str1 - *str2);
	}
		return 0;
}
char *strstr1(const char *hay, const char *needle) {
	const char *p = hay, *q = needle, *r;
	int j;
	j = strlen1(needle);
	while(*p != '\0' && *q != '\0') {
		if(*p == *q)  {
			p++;
			q++;
		}
		else { 
			if(q == needle)
				p++;
			else  {
				p = p - (q- needle) + 1;
				q = needle;
			}
		}
	}
	if(*q == '\0') {
		//i = p - (q - needle) - hay;
		r = p - (j);
		return (char*)r;
	}
	else 
		return NULL;
 
}
char *strcasestr1(const char *hay, const char *needle) {
	char *x = (char*)malloc(sizeof(char)* strlen1(hay) + 1);
	char *y = (char*)malloc(sizeof(char)* strlen1(needle) + 1);
	strcpy1(x, (char*)hay);
	strcpy1(y, (char*)needle);
	strlwr1((char*) hay);
	strlwr1((char*) needle);
	const char *p = hay, *q = needle, *r;
	int i = 0, j;
	j = strlen1(needle);
	while(*p != '\0' && *q != '\0') {
		if(*p == *q)  {
			p++;
			q++;
		}
		else { 
			if(q == needle)
				p++;
			else  {
				p = p - (q- needle) + 1;
				q = needle;
			}
		}
	}
	strcpy1((char*)hay, x);
	strcpy1((char*)needle, y);
	if(*q == '\0') {
		//i = p - (q - needle) - hay; 
		r = p - (i + j);
		return (char*)r;
	}
	else 
		return NULL;
 
}
char *strchr1(const char *str1, int c) {
	const char *p = str1; 
	while(*str1 != '\0') {
		if(*str1 == c)
			return (char*)p;
		str1++;
		p++;
	}
	return NULL;
}
char *strrchr1(const char *str1, int c) {
	const char *p = str1;
	int flag = 0;
	while(*str1 != '\0') {
		if(*str1 == c) {
			flag = 1;
			p = str1;
		}
		str1++;
	}
	if(flag == 1) 
		return (char*)p;
	else
		return NULL;
}
size_t strspn1(const char *str1, const char *str2) {
	int i = 0;
	const char *p = str1, *q = str2;
	while(*p != '\0') {
		while(*q != '\0') {
			if(*p == *q) {
				i++;
				q++;
				break;
			}
			else 
				q++;
			 if(*q == '\0')
				return i;			
		}
		q = str2;
		p++;
	}
	return i;
}
size_t strcspn1(const char *str1, const char *str2) {
        int i = 0;
        const char *p = str1, *q = str2;
        while(*p != '\0') {
                while(*q != '\0') {
                        if(*p == *q) {
                          //      i++;
                                return i;
                                
                        }
                        else
                                q++;
                         if(*q == '\0')
                                i++;
                }
                q = str2;
                p++;
        }
        return i;
}
char *strpbrk1(const char *str1, const char *str2) {
        const char *r = str1;
        const char *p = str1, *q = str2;
        while(*p != '\0') {
                while(*q != '\0') {
                        if(*p == *q) {
                                r = p;
                                return (char*)r;

                        }
                        else
                                q++;
                }
                q = str2;
                p++;
        }
        return NULL;
}
size_t memcmp1(const void *str1, const void *str2, size_t n) {
	int i = 0;
	const char *p = str1, *q = str2;
        while(1) {
                if(*p == *q) {
                        p++;
                        q++;
                        i++;
                }
                if(i == n)
                        break;
                if(*p == '\0' && *q == '\0')
                        return 0;
                if(*p - *q > 0)
                        return (*p - *q);
                else if(*p - *q < 0 )
                        return (*p - *q);
        }
                return 0;
}
void *memchr1(void *str1, int c, size_t n) {
	const char *p = str1;
	int i = 0;
	char ch = (char)c;
        while(i < n) {
                if(*p == ch)
                        return (void*)p;
          	i++;
                p++;
        }
	return NULL;
}
void *memcpy1(void *str1, const void *str2, size_t n) {
	int i = 0;
	char *p = str1;
	const char *q = str2;
        while(i != n) {
                if(*q != '\0') {
                        *p = *q;
                         p++;
                         q++;
                         i++;
                }
                if(*q == '\0')
                        break;
        }
        *p = '\0';
}
void *memmove1(void *str1, const void *str2, size_t n) {
	int i = 0;
	char *p = str1,x[128];
	const char *q = str2;
	char *temp = x;
	while(i != n) {
		*temp++ = *q++;
		i++;
	}
	i = 0;
	temp = x;
	while(i != n) {
		*p++ = *temp++;
		i++;
	}
	*p = '\0';
}
void *memset1(void *str1, int c, size_t n) {
	int i = 0;
        char *p = str1;
        while(i != n) {
		*p = c;
		p++;
                i++;
                if(*p == '\0')
			break;
        }
}
void *memmem1(const void *hay, size_t hl, const void *needle, size_t nl) {
	const char *p = hay, *q = needle, *r, *s = needle, *t = hay;
	int i = 0, j = 0, k;
	while(i != hl && j != nl) {
		if(*p == *q)  {
			p++;
			q++;
			i++;
			j++;
		}
		else { 
			if(q == s) { 
				p++;
				i++;
			}
			else  {
				p = p - (q- s) + 1;
				q = s;
				j = 0;
			}
		}
	}
	if(j == nl) {
	//	k = p - (q - s) - t; 
		r = p - (nl);
		return (char*)r;
	}
	else 
		return NULL;
 
}
void *memccpy1(void *str1, const void *str2, int value, size_t len) {
	char *p = str1;
	char *r = str1;
	const char *q = str2;
	int i = 0;
	while(i != len) {
		*p = *q;
		r++;
		if(*q == value) {
			*p = '\0';
			return r;
		}
		p++;
		q++;
		i++;
	}
	return NULL;
}
void *memrchr1(void *str1, int c, size_t n) {
	char *p = str1, *q = str1;
	void *r;
	int flag = 0;
	int i = 0;
	while(i != n) {
		if(*q == c) {
			flag = 1;
			p = str1;
			r = q;
		}
		q++;
		i++;
	}
	if(flag == 1) 
		return r;
	else
		return NULL;
}
		 			
int ffs1(int value) {
	int b = 1;
	if(value == 0)
		return 0;
	while((value & 1) == 0) {
		b++;
		value>>=1;
	}
	return b;
}
int ffsl1(long int value) {
	long int b = 1;
	if(value == 0)
		return 0;
	while((value & 1) == 0) {
		b++;
		value>>=1;
	}
	return b;
}
int ffsll1(long long int value) {
	long long int b = 1;
	if(value == 0)
		return 0;
	while((value & 1) == 0) {
		b++;
		value>>=1;
	}
	return b;
}
char *strchrnul1(const char *str1, int c) {
	const char *p = str1;
	const char *q = str1; 
	while(*str1 != '\0') {
		if(*str1 == c)
			return (char*)p;
		str1++;
		p++;
	}
	str1 = q;
	q = str1 + strlen1(str1);
	return (char*)q;
}
int strcasecmp1(const char *str1, const char *str2) {
	strlwr1((char*)str1);
	strlwr1((char*)str2);
	while(*str1 == *str2) {
		str1++;
		str2++;
		if(*str1 == '\0' && *str2 == '\0')
			return 0;
	}
	if(*str1 - *str2 > 0)
		return (*str1 - *str2);
	else
		return (*str1 - *str2);	
}
int strncasecmp1(const char *str1, const char *str2, size_t n) {
	int i = 0;
	strlwr1((char*)str1);
	strlwr1((char*)str2);
	while(i != n) {
		if(*str1 ==  *str2 ) {
			str1++;
			str2++;
			i++;
		}
		else if(*str1 - *str2 > 0)
			return (*str1 - *str2);
		else
			return (*str1 - *str2);	
	}
	return 0;
}	
char *strlwr1(char *str) {
	char *p = str;
	while(*str != '\0') {
		if(*str >= 'A' && *str <= 'Z') {
			*str = *str + 32;
			str++;
		}
		else
			str++;
	}
	str = p;
	return str;
}
char *strupr1(char *str) {
	char *p = str;
	while(*str != '\0') {
		if(*str >= 'a' && *str <= 'z') {
			*str = *str - 32;
			str++;
		}
		else
			str++;
	}
	str = p;
	return str;
}
char *strrev1(char *str) {
	char *p = str + (strlen1(str) - 1),*q = (char *)malloc(sizeof(char) *strlen1(str)  + 1);
	char *r = q;
	while(p != str) {
		*q = *p;
		q++;
		p--;
	}
	*q = *p;
	q++;
	*q = '\0';
	q = r;	
	strcpy1(str, q);
	return str;
}
		
char* mystrtok_r1(char *str, const char *delim, char **saveptr) {
	static int count = 0;
	int i = 0;
	char ch, *p;
	str = NULL;
	p = *saveptr;
//	printf("%s\n", p);
	while(1) {
		ch = *(*saveptr + i);
//		printf("%c\n", ch);
		
		if(ch == '\0') {
			if(count == 0) {
				count++;
				return p;
			}
			else
				return NULL;
		}
		else if(ch != *delim)
			i++;
		else
			if(strncmp1(*saveptr + i, delim, strlen1(delim)) == 0) {
				*saveptr = *saveptr + i;
				**saveptr = '\0';
			 	*saveptr = *saveptr + strlen1(delim);
//				printf("%s\n", *saveptr);
				
				while(strncmp1(*saveptr + i, delim, strlen1(delim)) == 0) {
					*saveptr = *saveptr + i;
					**saveptr = '\0';
			 		*saveptr = *saveptr + strlen1(delim);
//					printf("%s\n", *saveptr);
				}
				return p;
			}
			else
				i++;
	}
}

char *strdup1(const char*s) {
	char *p = (char *)malloc(sizeof(char)*strlen1(s) +1);
	strcpy1(p , s);
	return p;
}
char *strndup1(const char*s, size_t n) {
	char *p = (char *)malloc(sizeof(char)*strlen1(s) +1);
	strncpy1(p , s, n);
	return p;
}
char *strfry1(char *str) {
	unsigned int i, j, k, l1;
	l1 = strlen1(str);
	char ch;
	srand(j);
	for(i = 0; i < l1; i++) {
		k = rand() % l1;
		ch = str[i];
		str[i] = str[k];
		str[k] = ch;		
	}
	return str;
}
char *index1(const char *str, int c) {
	const char *p = str; 
	while(*str != '\0') {
		if(*str == c)
			return (char*)p;
		str++;
		p++;
	}
	return NULL;
}
char *rindex1(const char *str, int c) {
	const char *p = str;
	int flag = 0;
	while(*str != '\0') {
		if(*str == c) {
			flag = 1;
			p = str;
		}
		str++;
	}
	if(flag == 1) 
		return (char*)p;
	else
		return NULL;
}	
void bzero1(void *s, int n) {
	int i = 0;
	char *p = s;
	while(i != n) {
		*p = '\0';
		p++;
		i++;
	}
}
int bcmp1(const void *str1, const void *str2, int n) {
	if(n == 0) 
		return 0;
	else
		return strncmp1(str1, str2, n);
}			
void bcopy1(const void *str1, void *str2, int n) {
	int i = 0;
	char *p = str2,x[128];
	const char *q = str1;
	char *temp = x;
	while(i != n) {
		*temp++ = *q++;
		i++;
	}
	i = 0;
	temp = x;
	while(i != n) {
		*p++ = *temp++;
		i++;
	}
	*p = '\0';
}
void *memfrob1(void *str1, size_t n) {
	char *p = str1;
	int i = 0;
	while(i != n) {
		*p = (*p ^ 42);
		i++;
		p++;
	}
}

size_t wcslen1(const wchar_t *str1) {
	int i = 0;
	const wchar_t *p = str1; 
	while(*str1 != L'\0') {
		str1++;
		i++;
	}
	str1 = p;
	return i;
}

wchar_t *wcscpy1(wchar_t * str1, const wchar_t * str2) {
	wchar_t *p = str1;
	while(*str2 != L'\0') {
		*str1 = *str2;
		 str1++;
		 str2++;
	}
	*str1 = L'\0';
	str1 = p;
	return str1;
}

wchar_t *wcsncpy1(wchar_t * str1, const wchar_t * str2, size_t n) {
	int i = 0;
	wchar_t *p = str1;
	while(i != n) {
		if(*str2 != L'\0') {
			*str1 = *str2;
			 str1++;
			 str2++;
			 i++;
		}
		if(*str2 == L'\0')
			break;
	}
	*str1 = L'\0';
	str1 = p;
	return str1;
}

wchar_t *wcscat1(wchar_t *str1, const wchar_t *str2) {
	wchar_t *p;
	p = str1;	
	while(*str1 != L'\0') {
		str1++;
	}
	while(*str2 != L'\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = L'\0';
	str1 = p;
	return str1;
}

wchar_t *wcsncat1(wchar_t *str1, const wchar_t *str2, size_t n) {
	wchar_t *p;
	int i = 0;
	p = str1;
	while(*str1 != L'\0') {
		str1++;
	}
	while(i != n) {
		if(*str2 != L'\0') {
			*str1 = *str2;
			str1++;
			str2++;
			i++;
		}
		if(*str2 == L'\0') {
			break;
		}
	}
	*str1 = L'\0';
	str1 = p;
	return str1;
}

int wcscmp1(const wchar_t *str1, const wchar_t *str2) {
	while(*str1 == *str2) {
		str1++;
		str2++;
		if(*str1 == 0)
			return 0;
	}
	if(*str1 - *str2 > 0)
		return 1;
	else
		return -1;
}

int wcsncmp1(const wchar_t *str1, const wchar_t *str2, size_t n) {
	int i = 0;
	while(1) {
		if(*str1 == *str2) {
			str1++;
			str2++;
			i++;
		}
		if(i == n) 
			break;
		if(*str1 == 0)
			return 0;
		if(*str1 - *str2 > 0)
                	return 1;
        	else if(*str1 - *str2 < 0 )
                	return -1;
	}
		return 0;
}

wchar_t *wcschr1(const wchar_t *str1, wchar_t wc) {
	const wchar_t *p = str1; 
	while(*str1 != L'\0') {
		if(*str1 == wc)
			return (wchar_t*)p;
		str1++;
		p++;
	}
	return NULL;
}

wchar_t *wcsrchr1(const wchar_t *str1, wchar_t wc) {
	const wchar_t *p = str1;
	int flag = 0;
	while(*str1 != L'\0') {
		if(*str1 == wc) {
			flag = 1;
			p = str1;
		}
		str1++;
	}
	if(flag == 1) 
		return (wchar_t*)p;
	else
		return NULL;
}

size_t wcsspn1(const wchar_t *str1, const wchar_t *str2) {
	int i = 0;
	const wchar_t *p = str1, *q = str2;
	while(*p != L'\0') {
		while(*q != L'\0') {
			if(*p == *q) {
				i++;
				q++;
				break;
			}
			else 
				q++;
			 if(*q == L'\0')
				return i;			
		}
		q = str2;
		p++;
	}
	return i;
}
size_t wcscspn1(const wchar_t *str1, const wchar_t *str2) {
	int i = 0;
        const wchar_t *p = str1, *q = str2;
        while(*p != L'\0') {
                while(*q != L'\0') {
                        if(*p == *q) {
                                i++;
                                return i;
                                
                        }
                        else
                                q++;
                         if(*q == L'\0')
                                i++;
                }
                q = str2;
                p++;
        }
        return i;
}
 
wchar_t *wcspbrk1(const wchar_t *str1, const wchar_t *str2) {
        const wchar_t *r = str1;
        const wchar_t *p = str1, *q = str2;
        while(*p != L'\0') {
                while(*q != L'\0') {
                        if(*p == *q) {
                                r = p;
                                return (wchar_t*)r;

                        }
                        else
                                q++;
                }
                q = str2;
                p++;
        }
	return NULL;	
}

wchar_t *wcsstr1(const wchar_t *hay, const wchar_t *needle) {
	const wchar_t *p = hay, *q = needle, *r;
	int i, j;
	j = wcslen1(needle);
	while(*p != L'\0' && *q != L'\0') {
		if(*p == *q)  {
			p++;
			q++;
		}
		else { 
			if(q == needle)
				p++;
			else  {
				p = p - (q- needle) + 1;
				q = needle;
			}
		}
	}
	if(*q == L'\0') {
		i = p - (q - needle) - hay; 
		r = p - (i + j);
		return (wchar_t*)r;
	}
	else 
		return NULL;
 
}

wchar_t *wmemchr1(const wchar_t *str1, wchar_t wc, size_t n) {
	const wchar_t *p = str1;
	int i = 0;
        while(i != n) {
                if(*p == wc)
                        return (wchar_t*)p;
          	i++;
                p++;
        }
	return NULL;
}

int wmemcmp1(const wchar_t *str1, const wchar_t *str2, size_t n) {
	int i = 0;
	const wchar_t *p = str1, *q = str2;
        while(1) {
                if(*p == *q) {
                        p++;
                        q++;
                        i++;
                }
                if(i == n)
                        break;
                if(*p == L'\0' && *q == L'\0')
                        return 0;
                if(*p - *q > 0)
                        return 1;
                else if(*p - *q < 0 )
                        return -1;
        }
                return 0;
}

wchar_t *wmemcpy1(wchar_t *str1, const wchar_t *str2, size_t n)	{
	int i = 0;
	wchar_t *p = str1;
	const wchar_t *q = str2;
        while(i != n) {
                if(*q != L'\0') {
                        *p = *q;
                         p++;
                         q++;
                         i++;
                }
                if(*q == L'\0')
                        break;
        }
        *p = L'\0';
	return str1;
}

wchar_t *wmemmove1(wchar_t *str1, const wchar_t *str2, size_t n) {
	int i = 0;
	wchar_t *p = str1,x[128];
	const wchar_t *q = str2;
	wchar_t *temp = x;
	while(i != n) {
		*temp++ = *q++;
		i++;
	}
	i = 0;
	temp = x;
	while(i != n) {
		*p++ = *temp++;
		i++;
	}
	return str1;
}

wchar_t *wmemset1(wchar_t *str1, wchar_t wc, size_t n) {
	int i = 0;
        wchar_t *p = str1;
        while(i != n) {
		*p = wc;
		p++;
                i++;
                if(*p == L'\0')
			break;
        }
	return str1;
}

wchar_t *wcsdup1(wchar_t *str1) {
	wchar_t *p = (wchar_t *)malloc(sizeof(wchar_t)*wcslen1(str1) +1);
	wcscpy1(p , str1);
	return p;
}

