===================================================================================
Author: Mikołaj Pawłoś
===================================================================================

* Items:
============

Catalog ex5 contains 3 simple programs and 2 BASH scripts
--------------------------------------------------------------------

1.  -Program creates a FIFO PIPE.
    -forks twice launching both PRODUCER and CONSUMER programs through execlp.
    -passes the FIFO PIPE name,and names of program specific textfiles(producer.txt, consumer.txt)
    -waits for the children to finish, and closes deletes the pipe file at exit.

2.  the PRODUCER reads M bytes from a created file1 onto the buffer
    if he read EOF:(closes all his filedes and quits)
    else:
        writes from the buffer to the pipe
        writes the same information onto the STDOUT
        repeats 
         

3.   the CONSUMENT reads X bytes from the pipe onto his buffer2
     -writes/appends from buffer2 onto file2
     if he writes EOF: (closes all his filedes and quits)
     else:
        writes the same information onto the STDOUT


    files: 1) ex5.c - main program 
           2) producer.c - producer program
           3) consumer.c - consumer program
           4) producer.txt - 'producer' file - filled with dummy text
           5) consumer.txt - 'consumer' file - empty - created with program startup
           6) test.sh - used for checking if 4) and 5) are equal after program completion
           7) pipe.sh - used for creating a pipe from command line


------------------------------------------------------------------------

* How to launch the programs:
=========================

Catalog contains a Makefile used to compile,link
and start the programs above,
that also serves as a cleaning and archiving utility.

---> To make sure that commands defined in the MAKEFILE are executed
     as oposed to the default make's command use the option -r, ex: 
       make -r run 

// a)
----
->  to run the PROGRAM a) write 
       make run  

->  to test if the files are equal write
        make test


// b)
----
->  to create the pipe write:
        make pipe

NOTE! to run both the consumer and produer programs you'll need 2 seperate console windows
-----
->  to run the CONSUMER PROGRAM (USING XTERM) write 
       make consumer  

->  to run the PRODUCER PROGRAM (USING XTERM) write 
       make producer 

->  to test if the files are equal write
        make test

->  to delete the pipe write:
        make delpipe

Note: consumer and producer programs can be ran normally using
    |-> make consumer2
    |-> make producer2
    - respectivley

========================================================================
-> to clean the catalog you have to write the command:
       make clean

-> to archive the catalog and its contents write the command: 
       make tar


mockup text from www.cheeseipsum.co.uk
