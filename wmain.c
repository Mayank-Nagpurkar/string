#include <stdio.h>
#include <wchar.h> //for functions like wprintf, fgetws etc
#include <errno.h>
#include "string.h"
#include <stdlib.h>
#include "wchar.h"

void help() {
	printf("HELP\n");
	printf("For wchar.h\n");
	printf("use make -f makefile.nix command\n");
	printf("usage:	./project1 wdata\n");
	printf("For string.h\n");
	printf("use make command\n");
	printf("usage:	./project data1\n");
}
char *readline(FILE *fp) {
	int i = 0;
	char ch;
	char *line = malloc(sizeof(128));
	while(((ch = fgetc(fp)) != '\n') && (ch != EOF))
		line[i++] = ch;
	line[i] = '\0';
	if(!i)
		return NULL;
	return line;	
}

int hash(char *a) {
	int sum = 0;
	if(!a)
		return 0;
	while(*a != L'\0') {
		sum += *a;
		a++;
	}
	return sum;
}

int main (int argc, char *argv[]) {
	FILE *fp;
	int p;
	wchar_t t[32],u[32], v[32], *y, wc;
	char *fn, *b, *a, *x, *f, ch, *s;
	char *l;
	int i, k, n, m, c = 0;
	fp = fopen(argv[1], "r");
	if(strcmp1(argv[1], "-h") == 0) {
		help();
		exit(2);
	}
	if(fp == NULL) {
		perror("Cant Open the given file");
		return errno;
	}
	if(argc != 2) {
		perror("Invalid Arguments");
		return errno;
	}
	while(1) {
		l = readline(fp);
		c++;                //case No (line no for the given data file)
		if(feof(fp))
			break;
		if(l == NULL) {     //case for blank line
			printf("Case %d : FAIL\n", c);
			continue;
		} 
		fn = strtok1(l, "\t");
		if(fn == NULL) {
			printf("Case %d : FAIL\n", c);
			continue;
		}
		k = hash(fn);
		switch(k) {
			case 652: //wcslen
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(b);
				mbstowcs(t, a, 32);	//Converts the given string into wide string as we read the string in char format
				i = wcslen1(t);
				printf("%d", i);
				if( i == n) 
					printf("Case %d : PASS\n", c);
				else
					printf("Case %d : FAIL Expected output %d\n", c, i);


				break;
			case 665: //wcscpy
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				x = strtok1(NULL,"\t");
				mbstowcs(v, x, 32);
				y = wcscpy1(t, u);
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 775: //wcsncpy
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				s = strtok1(NULL,"\t");
				if(s == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(s);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wcsncpy1(t, u, n);
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 645: //wcscat
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wcscat1(t, u);
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 755: //wcsncat
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				s = strtok1(NULL,"\t");
				if(s == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(s);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x,32);
				y = wcsncat1(t, u, n);
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 653: //wcscmp
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(x);
				i = wcscmp1(t, u);
				if(i == n) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 763: //wcsncmp
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				s = strtok1(NULL,"\t");
				if(s == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(s);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				m = atoi(x);
				i = wcsncmp1(t, u, n);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 650: //wcschr
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				ch = *b;
				wc = ch;
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wcschr1(t, wc);
				if((strcmp1(x, "null") == 0) && (y == NULL)) {
					printf("Case %d : PASS\n", c);
					break;
				}
				else if((strcmp1(x, "null") != 0) && (y == NULL)) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 764: //wcsrchr
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				ch = *b;
				wc = ch;
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wcsrchr1(t, wc);
				if((strcmp1(x, "null") == 0) && (y == NULL)) {
					printf("Case %d : PASS\n", c);
					break;
				}
				else if((strcmp1(x, "null") != 0) && (y == NULL)) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 670: //wcsspn
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(x);
				i = wcsspn1(t, u);
				if(i == n) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 769: //wcscspn
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(x);
				i = wcscspn1(t, u);
				if(i == n) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 813: //wcspbrk1
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wcspbrk1(t, u);
				if((strcmp1(x, "null") == 0) && (y == NULL)) {
					printf("Case %d : PASS\n", c);
					break;
				}
				else if((strcmp1(x, "null") != 0) && (y == NULL)) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 678: //wcsstr
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wcsstr1(t, u);
				if((strcmp1(x, "null") == 0) && (y == NULL)) {
					printf("Case %d : PASS\n", c);
					break;
				}
				else if((strcmp1(x, "null") != 0) && (y == NULL)) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 804: //wmemchr1
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				ch = *b;
				wc = ch;
				s = strtok1(NULL,"\t");
				if(s == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(s);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wmemchr1(t, wc, n);
				if((strcmp1(x, "null") == 0) && (y == NULL)) {
					printf("Case %d : PASS\n", c);
					break;
				}
				else if((strcmp1(x, "null") != 0) && (y == NULL)) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 758: //wmemcmp
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				s = strtok1(NULL,"\t");
				if(s == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(s);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				m = atoi(x);
				i = wmemcmp1(t, u, n);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 770: //wmemcpy
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				s = strtok1(NULL,"\t");
				if(s == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(s);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wmemcpy1(t, u, n);
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 877: //wmemmove
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(u, b, 32);
				s = strtok1(NULL,"\t");
				if(s == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(s);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wmemmove1(t, u, n);
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 819: //wmemset1
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				b = strtok1(NULL,"\t");
				if(b == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				ch = *b;
				wc = ch;
				s = strtok1(NULL,"\t");
				if(s == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				n = atoi(s);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wmemset1(t, wc, n);
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 662: //wcsdup
				a = strtok1(NULL,"\t");
				if(a == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(t, a, 32);
				x = strtok1(NULL,"\t");
				if(x == NULL) {
					printf("Case %d : FAIL\n", c);
					break;
				}
				mbstowcs(v, x, 32);
				y = wcsdup1(t);
				i = wcscmp1(v , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			default:
				 printf("Case %d : FAIL\n", c);
			
		}
				
	}
	return 0;
}


