#include "string.h"
#include <stddef.h> //for declaration of NULL pointer
#include <stdlib.h> //for declaration of size_t

size_t strlen1(const char *str) {
	int i = 0;
	while(*str != '\0') {
		*str++;
		i++;
	}
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
	return p;
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
	return p;
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
	return p;
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
	int i;
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
		i = p - (q - needle) - hay; 
		r = p - (i);
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
                                i++;
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
        return (char*)r;
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
        while(i != n) {
                if(*p == c)
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
		k = p - (q - s) - t; 
		r = p - (k);
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
	char *p = str + strlen1(str),*q = str;
	p--;
	while(*str != '\0') {
		*str = *p;
		str++;
		p--;
	}
	*str = '\0';
	str = q;
	return str;
}
		
char* mystrtok(char *str, const char *delim, char **saveptr) {
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
			if(strncmp(*saveptr + i, delim, strlen(delim)) == 0) {
				*saveptr = *saveptr + i;
				**saveptr = '\0';
			 	*saveptr = *saveptr + strlen(delim);
//				printf("%s\n", *saveptr);
				
				while(strncmp(*saveptr + i, delim, strlen(delim)) == 0) {
					*saveptr = *saveptr + i;
					**saveptr = '\0';
			 		*saveptr = *saveptr + strlen(delim);
//					printf("%s\n", *saveptr);
				}
				return p;
			}
			else
				i++;
	}
}


	
		
							  
