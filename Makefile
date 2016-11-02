project:project project2
project:main.o string.o
	cc string.o main.o -o project
main.o:main.c string.c string.h
	cc -c main.c string.c 
string.o:string.h string.c
	cc -c string.c 
project2:wmain.o string.o wchar.o
	cc string.o wmain.o wchar.o -o project2
wmain.o:wmain.c wchar.c wchar.h
	cc -c wmain.c wchar.c  
wchar.o:wchar.c wchar.h
	cc -c wchar.c
clean:
	rm *.o
