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
NAME3=extraProgram

#text_file names
TNAME1=producent
TNAME2=consumer

#FIFO_PIPE
PIP=my_fif

#C Source files
CFILE1=$(NAME1).c
CFILE2=$(NAME2).c
CFILE3=$(NAME3).c

#OBJECT FILES
OBJS1=$(NAME1).o
OBJS2=$(NAME2).o
OBJS3=$(NAME3).o

#EXECUTABLE FILES
EXEC1=$(NAME1).x
EXEC2=$(NAME2).x
EXEC3=$(NAME3).x

#Executables
#flags
CFLAGS =-Wall -std=c99 -pedantic -O 
LFLAGS =-Wall -std=c99 -pedantic -O

#========================================

all: $(EXEC1) $(EXEC2) $(EXEC3)

$(EXEC1): $(OBJS1) $(HEADS)
	$(CO) -o $@ $^

$(EXEC2): $(OBJS2) $(HEADS)
	$(CO) -o $@ $^

$(EXEC3): $(OBJS3) $(HEADS) 
	$(CO) -o $@ $^

%.o:%.c
	$(CO) $(CFLAGS) -c -o $@ $^

#======================================
#Example startup options
run:
	./$(EXEC3) ./$(EXEC1) ./$(EXEC2) ./$(TNAME1) ./$(TNAME2) ./$(PIP) 

runb2:
	./$(EXEC2) ./$(TNAME2) ./$(PIP)

runb1:
	./$(EXEC1) ./$(TNAME1) ./$(PIP)

#=====================================================
#Utilities
test:
	/bin/sh test.sh $(TNAME1) $(TNAME2) 
pipe:
	/bin/sh pipe.sh 0644 $(PIP)
delpipe:
	rm $(PIP)
#=====================================================
clean:
	rm *.x *.o $(TNAME2) 
tar: 
	(cd ../; tar -cvzf $(DIR).tar.gz --exclude .git --exclude "*.log" $(DIR))
