try:main.o string.o
	cc string.o main.o -o try
main.o: main.c string.c string.h
	cc -c main.c string.c string.h
string.o:string.h string.c
	cc -c string.c string.h
