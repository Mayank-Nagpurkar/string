#include <stdio.h>
#include <wchar.h>
#include <errno.h>
#include <stdlib.h>
#include "string.h"
//#include <string.h> //just to check

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
	while(*a != '\0') {
		sum += *a;
		a++;
	}
	//printf("%d\n", sum);
	return sum;
}

int main (int argc, char *argv[]) {
	FILE *fp;
	int p;
	char *fn, *b, *a, *x, *f, ch, *l, *y, *s;
	int i, k, n, m, c = 0;
	fp = fopen(argv[1], "r");
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
			break;
		}
		k = hash(fn);
		switch(k) {
			case 664: //strlen
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				n = atoi(b);
				i = strlen1(a);
				if(i == n) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);


				break;
			case 677: //strcpy
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				y = strcpy1(a, b);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 787: //strncpy
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				y = strncpy1(a, b, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 785: //strlcpy
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				i = strlcpy1(a, b, n);
				m = atoi(x);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 675: //stpcpy
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				stpcpy1(a, b);
				i = strcmp1(x , a);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 657: //strcat
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				y = strcat1(a, b);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 767: //strncat
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				y = strncat1(a, b, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 665: //strcmp
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(x);
				i = strcmp1(a, b);
				if(i == n) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 775: //strncmp
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				i = strncmp1(a, b, n);
				m = atoi(x);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 690: //strstr
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				y = strstr1(a, b);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 1102: //strcasestr
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				y = strcasestr1(a, b);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 662: //strchr
				a = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				y = strchr1(a, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 776: //strrchr
				a = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				y = strrchr1(a, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 682: //strspn
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(x);
				i = strspn1(a, b);
				if(i == n) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 781: //strcspn
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(x);
				i = strcspn1(a, b);
				if(i == n) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 825: //strpbrk
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				y = strpbrk1(a, b);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 639: //memcmp
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				i = memcmp1(a, b, n);
				m = atoi(x);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 651: //memcpy
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				memcpy1(a, b, n);
				i = strcmp1(x , a);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 636: //memchr
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				m = atoi(b);
				y = memchr1(a, m, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 758: //memmove
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				memmove1(a, b, n);
				i = strcmp1(x , a);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 700: //memset
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				m = atoi(b);
				memset1(a, m, n);
				i = strcmp1(x , a);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 638: //memmem
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				f = strtok1(NULL,"\t");
				n = atoi(s);
				m = atoi(b);
				y = memmem1(a, m, x, n);
				i = strcmp1(f , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 750: //memccpy
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				f = strtok1(NULL,"\t");
				n = atoi(s);
				m = atoi(x);
				memccpy1(a, b, m, n);
				i = strcmp1(f , a);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 799: //memrchr
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				m = atoi(b);
				y = memrchr1(a, m, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 744: //memfrob
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(b);
				memfrob1(a, n);
				i = strcmp1(x , a);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);


				break;
			case 319: //ffs
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				n = atoi(a);
				m = atoi(b);
				i = ffs1(n);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 427: //ffsl
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				n = atoi(a);
				m = atoi(b);
				i = ffsl1(n);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 535: //ffsll
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				n = atoi(a);
				m = atoi(b);
				i = ffsll1(n);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 997: //strchrnul
				a = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				y = strchrnul1(a, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 1077: //strcasecmp
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(x);
				i = strcasecmp1(a, b);
				if(i == n) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 1187: //strncasecmp
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				i = strncasecmp1(a, b, n);
				m = atoi(x);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 686: //strlwr
				a = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				y = strlwr1(a);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 688: //strupr
				a = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				y = strupr1(a);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 678: //strrev
				a = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				y = strrev1(a);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 674: //strdup
				a = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				y = strdup1(a);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 784: //strndup
				a = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				y = strndup1(a, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 536: //index
				a = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				y = index1(a, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 650: //rindex
				a = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				y = rindex1(a, n);
				i = strcmp1(x , y);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 418: //bcmp
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				i = bcmp1(a, b, n);
				m = atoi(x);
				if(i == m) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
			case 541: //bcopy
				a = strtok1(NULL,"\t");
				b = strtok1(NULL,"\t");
				s = strtok1(NULL,"\t");
				x = strtok1(NULL,"\t");
				n = atoi(s);
				bcopy1(a, b, n);
				i = strcmp1(x , b);
				if(i == 0) 
					printf("Case %d : PASS\n", c);
				else
					 printf("Case %d : FAIL\n", c);
				break;
		} 

	}
	return 0;
}
		 
