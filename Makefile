output:
	gcc ex3a.c -o ex3a.o  && ./ex3a.o SIGINT SIG_DFL
ex3a.o:
	gcc ex3a.c -o ex3a.o
c:
	rm *.o
