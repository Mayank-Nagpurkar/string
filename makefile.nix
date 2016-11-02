project1:wmain.o string.o wchar.o
	cc string.o wmain.o wchar.o -o project1
wmain.o:wmain.c wchar.c wchar.h
	cc -c wmain.c wchar.c 
string.o:string.h string.c
	cc -c string.c 
wchar.o:wchar.c wchar.h
	cc -c wchar.c
clean:
	rm *.o
	
