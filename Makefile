
output: cw1.o writeID.o
	gcc cw1.o -o run1

cw1.o: cw1.c cw1.h functions.h writeID.c 
	gcc -c cw1.c

writeID.o: writeID.c
	gcc writeID.c -o writeID.o

clean:
	rm *.o run1

run:
	./run1 ./writeID.o
