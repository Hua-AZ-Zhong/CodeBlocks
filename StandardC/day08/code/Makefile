14multi: 14multi.o readInt.o readInt.h
	gcc 14multi.o readInt.o -o 14multi
14multi.o:14multi.c readInt.h
	gcc -c 14multi.c
readInt.o:readInt.c readInt.h
	gcc -c readInt.c
clean:
	rm *.o 14multi
