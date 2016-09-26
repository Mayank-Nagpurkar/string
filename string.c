#include "string.h"
#include <stddef.h>
#include <stdlib.h>

size_t strlen1(const char *str) {
	int i = 0;
	while(*str != '\0') {
		*str++;
		i++;
	}
	return i;
}

char *strcpy1(char *str1, const char *str2) {
	while(*str2 != '\0') {
		*str1 = *str2;
		 str1++;
		 str2++;
	}
	*str1 = '\0';
}
char *strncpy1(char *str1, const char* str2, size_t n) {
	int i = 0;
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
		r = p - (i + 1);
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
char *strtok1(char *str1, const char *delim) {
	char *p;
	const char *q = delim;
	static int i = 0;
	if(*str1 == NULL)
		return NULL;
	else		
		p = str1;
	while(p[i] != '\0') {
		while(*q != '\0') {
			if(p[i] == *q) { 
				p[i] = '\0';
				i++;
			}
		}
	}
}
							  
