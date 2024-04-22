#Directory and system
.SUFFIXES: .c .cpp .o .x .h
DIR=$(notdir $(CURDIR))
SYSNAME =$(shell uname -s)



#Compiler & Linker
CO=gcc
LD=$(CO)

#header files
HEADS=ex5.h

#file names 
NAME1=ex5
NAME2=ex5c

#text_file names
TNAME1=consumer
TNAME2=producent

#FIFO_PIPE
PIP=my_fif

#C Source files
CFILE1=$(NAME1).c
CFILE2=$(NAME2).c

#OBJECT FILES
OBJS1=$(NAME1).o
OBJS2=$(NAME2).o

#EXECUTABLE FILES
EXEC1=$(NAME1).x
EXEC2=$(NAME2).x

#Executables
#flags
CFLAGS =-Wall -std=c99 -pedantic -O 
LFLAGS =-Wall -std=c99 -pedantic -O

#========================================

all: $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJS1) $(HEADS)
	$(CO) -o $@ $^

$(EXEC2): $(OBJS2) $(HEADS)
	$(CO) -o $@ $^

%.o:%.c
	$(CO) $(CFLAGS) -c -o $@ $^

#======================================
#Example startup options
run:
	./$(EXEC1) ./$(TNAME1) ./$(TNAME2) ./$(PIP) ./$(EXEC2)
test:
	/bin/sh test.sh $(TNAME1) $(TNAME2) 
#=====================================================
clean:
	rm *.x *.o $(TNAME1) 
tar: 
	(cd ../; tar -cvzf $(DIR).tar.gz --exclude .git --exclude "*.log" $(DIR))
