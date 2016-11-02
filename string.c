/*****************************************************************************
 * Copyright (C) Mayank Nagpurkar <mayanknagpurkar@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "string.h"
#include <stddef.h> //for declaration of NULL pointer
#include <stdlib.h> //for declaration of size_t
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
	int l1 = strlen1(str1);
	int l2 = strlen1(str2);
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
	if((l1 < l2) && (l1 < n)) {
		*str1 = '\0';
	}
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
		r = p - (j);
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
					
int strcoll1(const char *str1, const char *str2) {
	return strcmp1(str1, str2); //where locales are unimplemented
}
size_t strxfrm1(char *str1, const char *str2, size_t n) {
	int l1,l2; //where locales are unimplemented
	char *p;
	p = str1;
	l2 = strlen1(str2);
	if(n <= 0)
		return l2;
	l1 = 0;
	while(n != 0) {
		strcpy1(str1, str2);
	}
	return l2; 
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
	int l1 = strlen1(p);
	const char *q = str2;
	int l2 = strlen1(q);
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
	if((l1 < l2) && (l1 < n)) {
		*p = '\0';
	}
	p = str1;
}
void *memmove1(void *str1, const void *str2, size_t n) {
	int i = 0;
	char *p = str1,x[128];
	int l1 = strlen1(p);
	const char *q = str2;
	int l2 = strlen1(q);
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
	if((l1 < l2) && (l1 < n)) {
		*p = '\0';
	}
	p = str1;
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
	int b = 1;
	if(value == 0)
		return 0;
	while((value & 1) == 0) {
		b++;
		value>>=1;
	}
	return b;
}
int ffsll1(long long int value) {
	int b = 1;
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

char *strtok1(char *str, const char *delim) {
	static char *p;
	const char *d = delim;
	int c = 0; //c denotes the no of character of sting read before a delim is encountered.
	static int f = 0; //f is flag if a delimiter is found.
	if(str) 
		p = str;
	while (*p != '\0') {
		while(*d != '\0') {
			if(*p == *d) {
				f = 1;
				*p = '\0';
				p++;
				return (p - c - 1);
			}
			else
				d++;
		}
		d = delim;
		p++;
		c++;
	}
	if(f == 1) {
		if(c != 0)   //for last case with if a delim is found
			return (p - c);
		else
			return NULL;
		}
	else
		return str;
}
char* mystrtok_r1(char *str, const char *delim, char **saveptr) {
	static int count = 0;
	int i = 0;
	char ch, *p;
	str = NULL;
	p = *saveptr;
	while(1) {
		ch = *(*saveptr + i);
		
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
				
				while(strncmp1(*saveptr + i, delim, strlen1(delim)) == 0) {
					*saveptr = *saveptr + i;
					**saveptr = '\0';
			 		*saveptr = *saveptr + strlen1(delim);
				}
				return p;
			}
			else
				i++;
	}
}
char *strsep2(char **str, const char *delim) {
	static char **p;
	char *t;
	p = str;
	int c = 0, f = 0;
	const char *q = delim;
	if(*str == NULL) 
		return NULL;
	while(**p != '\0') {
		while(*q != '\0'){
			if(**p == *q) {
				f = 1;
				**p = '\0';
				*p++;
				return (*p - c - 1);
			}
			else
				q++;
		}
		q = delim;
		*p++;
		c++;
	}
	if(f == 1) {
		if(c != 0)   //for last case with if a delim is found
			return (*p - c);
		}
	else {
	return *p; 
	}

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
	int l1 = strlen1(p);
	const char *q = str1;
	int l2 = strlen1(q);
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
	if((l1 < l2) && (l1 < n)) {
		*p = '\0';
	}
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
char *strerror1(int errnum) {
	int n = errnum;
	char *e, *a;
	switch(n) {
		case 1:
			e = (char *)malloc(128);
			a = "Operation not permitted";
			strcpy1(e, a);
			break;
		case 2:
			e = (char *)malloc(128);
			a = "No such file or directory";
			strcpy1(e, a);
			break;
		case 3:
			e = (char *)malloc(128);
			a = "No such process";
			strcpy1(e, a);
			break;
		case 4:
			e = (char *)malloc(128);
			a = "Interupted system call";
			strcpy1(e, a);
			break;
		case 5:
			e = (char *)malloc(128);
			a = "I/O error";
			strcpy1(e, a);
			break;
		case 6:
			e = (char *)malloc(128);
			a = "No such device or address";
			strcpy1(e, a);
			break;
		case 7:
			e = (char *)malloc(128);
			a = "Argument list too long";
			strcpy1(e, a);
			break;
		case 8:
			e = (char *)malloc(128);
			a = "Exec format error";
			strcpy1(e, a);
			break;
		case 9:
			e = (char *)malloc(128);
			a = "Bad file number";
			strcpy1(e, a);
			break;
		case 10:
			e = (char *)malloc(128);
			a = "No child processes";
			strcpy1(e, a);
			break;
		case 11:
			e = (char *)malloc(128);
			a = "Try again";
			strcpy1(e, a);
			break;
		case 12:
			e = (char *)malloc(128);
			a = "Out of memory";
			strcpy1(e, a);
			break;
		case 13:
			e = (char *)malloc(128);
			a = "Permission denied";
			strcpy1(e, a);
			break;
		case 14:
			e = (char *)malloc(128);
			a = "Bad address";
			strcpy1(e, a);
			break;
		case 15:
			e = (char *)malloc(128);
			a = "Block device required";
			strcpy1(e, a);
			break;
		case 16:
			e = (char *)malloc(128);
			a = "Device or resource busy";
			strcpy1(e, a);
			break;
		case 17:
			e = (char *)malloc(128);
			a = "File exists";
			strcpy1(e, a);
			break;
		case 18:
			e = (char *)malloc(128);
			a = "Cross device link";
			strcpy1(e, a);
			break;
		case 19:
			e = (char *)malloc(128);
			a = "No such device";
			strcpy1(e, a);
			break;
		case 20:
			e = (char *)malloc(128);
			a = "Not a directory";
			strcpy1(e, a);
			break;
		case 21:
			e = (char *)malloc(128);
			a = "Is a directory";
			strcpy1(e, a);
			break;
		case 22:
			e = (char *)malloc(128);
			a = "Invalid Argument";
			strcpy1(e, a);
			break;
		case 23:
			e = (char *)malloc(128);
			a = "File table overflow";
			strcpy1(e, a);
			break;
		case 24:
			e = (char *)malloc(128);
			a = "Too many open files";
			strcpy1(e, a);
			break;
		case 25:
			e = (char *)malloc(128);
			a = "Not  a typewriter";
			strcpy1(e, a);
			break;
		case 26:
			e = (char *)malloc(128);
			a = "Text file busy";
			strcpy1(e, a);
			break;
		case 27:
			e = (char *)malloc(128);
			a = "File too large";
			strcpy1(e, a);
			break;
		case 28:
			e = (char *)malloc(128);
			a = "No space left on device";
			strcpy1(e, a);
			break;
		case 29:
			e = (char *)malloc(128);
			a = "Illlegal seek";
			strcpy1(e, a);
			break;
		case 30:
			e = (char *)malloc(128);
			a = "Read-only file system";
			strcpy1(e, a);
			break;
		case 31:
			e = (char *)malloc(128);
			a = "Too many links";
			strcpy1(e, a);
			break;
		case 32:
			e = (char *)malloc(128);
			a = "Broken pipe";
			strcpy1(e, a);
			break;
		case 33:
			e = (char *)malloc(128);
			a = "Math argument out of domain of func";
			strcpy1(e, a);
			break;
		case 34:
			e = (char *)malloc(128);
			a = "Math result not representable";
			strcpy1(e, a);
			break;
		case 35:
			e = (char *)malloc(128);
			a = "Resource deadlock would occur";
			strcpy1(e, a);
			break;
		case 36:
			e = (char *)malloc(128);
			a = "FIle name too long";
			strcpy1(e, a);
			break;
		case 38:
			e = (char *)malloc(128);
			a = "Function not implemented";
			strcpy1(e, a);
			break;
		case 39:
			e = (char *)malloc(128);
			a = "Directory not empty";
			strcpy1(e, a);
			break;
		case 40:
			e = (char *)malloc(128);
			a = "Too many symbolic links encountered";
			strcpy1(e, a);
			break;
		case 41:
			e = (char *)malloc(128);
			a = "Operation would block";
			strcpy1(e, a);
			break;
		case 42:
			e = (char *)malloc(128);
			a = "No message of desired type";
			strcpy1(e, a);
			break;
		case 43:
			e = (char *)malloc(128);
			a = "Identifier removed";
			strcpy1(e, a);
			break;
		case 44:
			e = (char *)malloc(128);
			a = "Channel number out of range";
			strcpy1(e, a);
			break;
		case 45:
			e = (char *)malloc(128);
			a = "Level 2 not synchronized";
			strcpy1(e, a);
			break;
		case 46:
			e = (char *)malloc(128);
			a = "Level 3 halted";
			strcpy1(e, a);
			break;
		case 47:
			e = (char *)malloc(128);
			a = "Level 3 reset";
			strcpy1(e, a);
			break;
		case 48:
			e = (char *)malloc(128);
			a = "Link number out of range";
			strcpy1(e, a);
			break;
		case 49:
			e = (char *)malloc(128);
			a = "Protocol driver not attached";
			strcpy1(e, a);
			break;
		case 50:
			e = (char *)malloc(128);
			a = "No CSI structure available";
			strcpy1(e, a);
			break;
		case 51:
			e = (char *)malloc(128);
			a = "Lvele 2 halted";
			strcpy1(e, a);
			break;
		case 52:
			e = (char *)malloc(128);
			a = "Invalid Exchange";
			strcpy1(e, a);
			break;
		case 53:
			e = (char *)malloc(128);
			a = "Invalid request descriptor";
			strcpy1(e, a);
			break;
		case 54:
			e = (char *)malloc(128);
			a = "Exchange full";
			strcpy1(e, a);
			break;
		case 55:
			e = (char *)malloc(128);
			a = "No anode";
			strcpy1(e, a);
			break;
		case 56:
			e = (char *)malloc(128);
			a = "Invalid request code";
			strcpy1(e, a);
			break;
		case 57:
			e = (char *)malloc(128);
			a = "Invlid slot";
			strcpy1(e, a);
			break;
		case 58:
			e = (char *)malloc(128);
			a = "EDEALK";
			strcpy1(e, a);
			break;
		case 59:
			e = (char *)malloc(128);
			a = "Bad front file format";
			strcpy1(e, a);
			break;
		case 60:
			e = (char *)malloc(128);
			a = "Device not a stream";
			strcpy1(e, a);
			break;
		case 61:
			e = (char *)malloc(128);
			a = "No data available";
			strcpy1(e, a);
			break;
		case 62:
			e = (char *)malloc(128);
			a = "Timer expired";
			strcpy1(e, a);
			break;
		case 63:
			e = (char *)malloc(128);
			a = "Out of streams resources";
			strcpy1(e, a);
			break;
		case 64:
			e = (char *)malloc(128);
			a = "Machine is not on network";
			strcpy1(e, a);
			break;
		case 65:
			e = (char *)malloc(128);
			a = "Package not installed";
			strcpy1(e, a);
			break;
		case 66:
			e = (char *)malloc(128);
			a = "Object is remote";
			strcpy1(e, a);
			break;
		case 67:
			e = (char *)malloc(128);
			a = "Link has been severed";
			strcpy1(e, a);
			break;
		case 68:
			e = (char *)malloc(128);
			a = "Advertise error";
			strcpy1(e, a);
			break;
		case 69:
			e = (char *)malloc(128);
			a = "Srmount error";
			strcpy1(e, a);
			break;
		case 70:
			e = (char *)malloc(128);
			a = "Communication error on send";
			strcpy1(e, a);
			break;
		case 71:
			e = (char *)malloc(128);
			a = "Protocol error";
			strcpy1(e, a);
			break;
		case 72:
			e = (char *)malloc(128);
			a = "Multihop attempted";
			strcpy1(e, a);
			break;
		case 73:
			e = (char *)malloc(128);
			a = "RFS specific error";
			strcpy1(e, a);
			break;
		case 74:
			e = (char *)malloc(128);
			a = "Not a data message";
			strcpy1(e, a);
			break;
		case 75:
			e = (char *)malloc(128);
			a = "Valid too large for defined data type";
			strcpy1(e, a);
			break;
		case 76:
			e = (char *)malloc(128);
			a = "Name not unique on network";
			strcpy1(e, a);
			break;
		case 77:
			e = (char *)malloc(128);
			a = "File descriptor in bad state";
			strcpy1(e, a);
			break;
		case 78:
			e = (char *)malloc(128);
			a = "Remote address changed";
			strcpy1(e, a);
			break;
		case 79:
			e = (char *)malloc(128);
			a = "Can not access a needed shared library";
			strcpy1(e, a);
			break;
		case 80:
			e = (char *)malloc(128);
			a = "Accessing a corrupted shared library";
			strcpy1(e, a);
			break;
		case 81:
			e = (char *)malloc(128);
			a = ".lib section in a.out corrupted";
			strcpy1(e, a);
			break;
		case 82:
			e = (char *)malloc(128);
			a = "Attempted to link too many shared libraries";
			strcpy1(e, a);
			break;
		case 83:
			e = (char *)malloc(128);
			a = "Cannot exec a shared library directly";
			strcpy1(e, a);
			break;
		case 84:
			e = (char *)malloc(128);
			a = "Illegal byte sequence";
			strcpy1(e, a);
			break;
		case 85:
			e = (char *)malloc(128);
			a = "Interrupted system call should be restarted";
			strcpy1(e, a);
			break;
		case 86:
			e = (char *)malloc(128);
			a = "Streams pipe error";
			strcpy1(e, a);
			break;
		case 87:
			e = (char *)malloc(128);
			a = "Too many errors";
			strcpy1(e, a);
			break;
		case 88:
			e = (char *)malloc(128);
			a = "SOcket operation on non-socket";
			strcpy1(e, a);
			break;
		case 89:
			e = (char *)malloc(128);
			a = "Destination address required";
			strcpy1(e, a);
			break;
		case 90:
			e = (char *)malloc(128);
			a = "Message too long";
			strcpy1(e, a);
			break;
		case 91:
			e = (char *)malloc(128);
			a = "Prtocol wrong type for socket";
			strcpy1(e, a);
			break;
		case 92:
			e = (char *)malloc(128);
			a = "Protocol not available";
			strcpy1(e, a);
			break;
		case 93:
			e = (char *)malloc(128);
			a = "Protocol not suported";
			strcpy1(e, a);
			break;
		case 94:
			e = (char *)malloc(128);
			a = "Socket type not supported";
			strcpy1(e, a);
			break;
		case 95:
			e = (char *)malloc(128);
			a = "Operation not supported on transport endpoint";
			strcpy1(e, a);
			break;
		case 96:
			e = (char *)malloc(128);
			a = "Protocol family not supported ";
			strcpy1(e, a);
			break;
		case 97:
			e = (char *)malloc(128);
			a = "Address family not supported by protocol";
			strcpy1(e, a);
			break;
		case 98:
			e = (char *)malloc(128);
			a = "Address already in use";
			strcpy1(e, a);
			break;
		case 99:
			e = (char *)malloc(128);
			a = "Cannot assign requested address";
			strcpy1(e, a);
			break;
		case 100:
			e = (char *)malloc(128);
			a = "Network is down";
			strcpy1(e, a);
			break;
		case 101:
			e = (char *)malloc(128);
			a = "Network is unreachable";
			strcpy1(e, a);
			break;
		case 102:
			e = (char *)malloc(128);
			a = "Network dropped connection because of reset";
			strcpy1(e, a);
			break;
		case 103:
			e = (char *)malloc(128);
			a = "Software caused connection abort";
			strcpy1(e, a);
			break;
		case 104:
			e = (char *)malloc(128);
			a = "Connection reset by peer";
			strcpy1(e, a);
			break;
		case 105:
			e = (char *)malloc(128);
			a = "No buffer space available";
			strcpy1(e, a);
			break;
		case 106:
			e = (char *)malloc(128);
			a = "Transport endpoint is already connected";
			strcpy1(e, a);
			break;
		case 107:
			e = (char *)malloc(128);
			a = "Transport endpoint is not connected";
			strcpy1(e, a);
			break;
		case 108:
			e = (char *)malloc(128);
			a = "Cannot send after transport endpoint shutdown";
			strcpy1(e, a);
			break;
		case 109:
			e = (char *)malloc(128);
			a = "Too many refrences: cannot splice";
			strcpy1(e, a);
			break;
		case 110:
			e = (char *)malloc(128);
			a = "Connection timed out";
			strcpy1(e, a);
			break;
		case 111:
			e = (char *)malloc(128);
			a = "Connection refused";
			strcpy1(e, a);
			break;
		case 112:
			e = (char *)malloc(128);
			a = "Host is down";
			strcpy1(e, a);
			break;
		case 113:
			e = (char *)malloc(128);
			a = "No route to host";
			strcpy1(e, a);
			break;
		case 114:
			e = (char *)malloc(128);
			a = "Operation is already in process";
			strcpy1(e, a);
			break;
		case 115:
			e = (char *)malloc(128);
			a = "Operation now in progress";
			strcpy1(e, a);
			break;
		case 116:
			e = (char *)malloc(128);
			a = "Stale NFS file handle";
			strcpy1(e, a);
			break;
		case 117:
			e = (char *)malloc(128);
			a = "STructure needs cleaning";
			strcpy1(e, a);
			break;
		case 118:
			e = (char *)malloc(128);
			a = "Not a XENIX named type file";
			strcpy1(e, a);
			break;
		case 119:
			e = (char *)malloc(128);
			a = "No XENIX semaphores available";
			strcpy1(e, a);
			break;
		case 120:
			e = (char *)malloc(128);
			a = "Is a named type file";
			strcpy1(e, a);
			break;
		case 121:
			e = (char *)malloc(128);
			a = "Remote I/O error";
			strcpy1(e, a);
			break;
		case 122:
			e = (char *)malloc(128);
			a = "Quota exceeded";
			strcpy1(e, a);
			break;
		case 123:
			e = (char *)malloc(128);
			a = "No medium found";
			strcpy1(e, a);
			break;
		case 124:
			e = (char *)malloc(128);
			a = "Wrong medium type";
			strcpy1(e, a);
			break;
		case 125:
			e = (char *)malloc(128);
			a = "Operation canceled";
			strcpy1(e, a);
			break;
		case 126:
			e = (char *)malloc(128);
			a = "Required key not available";
			strcpy1(e, a);
			break;
		case 127:
			e = (char *)malloc(128);
			a = "Key has expired";
			strcpy1(e, a);
			break;
		case 128:
			e = (char *)malloc(128);
			a = "Key has been revoked";
			strcpy1(e, a);
			break;
		case 129:
			e = (char *)malloc(128);
			a = "Key was rejected by service";
			strcpy1(e, a);
			break;
		case 130:
			e = (char *)malloc(128);
			a = "Owner died";
			strcpy1(e, a);
			break;
		case 131:
			e = (char *)malloc(128);
			a = "State not recoverable";
			strcpy1(e, a);
			break;
		default:
			break;
		
		
	}
	return e;
}


