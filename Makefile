project:main.o string.o
	cc string.o main.o -o project
main.o:main.c string.c string.h
	cc -c main.c string.c 
string.o:string.h string.c
	cc -c string.c 
clean:
	rm *.o
