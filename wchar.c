#include<stdio.h>   //for testing of my own code
#include <stddef.h> //for declaration of NULL pointer
#include <stdlib.h> //for declaration of size_t
#include <sys/cdefs.h> //for wchar

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
	int l1 = wcslen1(str1);
	int l2 = wcslen1(str2);
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
	if((l1 < l2) && (l1 < n)) {
		*str1 = L'\0';
	}
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
		if(*str1 == L'\0' && *str2  == L'\0')
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
		r = p - (j);
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
	int l1 = wcslen1(str1);
	const wchar_t *q = str2;
	int l2 = wcslen1(str2);
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
        if((l1 < l2) && (l1 < n)) {
		*p = L'\0';
	}
	return str1;
}

wchar_t *wmemmove1(wchar_t *str1, const wchar_t *str2, size_t n) {
	int i = 0;
	wchar_t *p = str1,x[128];
	int l1 = wcslen1(str1);
	const wchar_t *q = str2;
	int l2 = wcslen1(str2);
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
	if((l1 < l2) && (l1 < n)) {
		*p = L'\0';
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
