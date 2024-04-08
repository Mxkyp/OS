output:
	gcc ex3a.c -o ex3a.o 
ex3a.o:
	gcc ex3a.c -o ex3a.o

intr:
	./ex3a.o 2 SIG_INTERCEPT 
dfl:
	./ex3a.o 2 SIG_DFL
ign:
	./ex3a.o 2 SIG_IGN

c:
	rm *.o
