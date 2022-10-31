# /home/pura0273/homework/03/Makefile
# cs-240.wilder..........gcc..........jenna-luz pura
# october 31, 2022.......pura0273@vandals.uidaho.edu
# --------------------
# compiles each msh*.c file into corresponding msh*.o file.
# links all object files to produce executable file msh.
# --------------------
# to compile:
# 	make
#
# to clean:
# 	make clean

CC = gcc
CFLAGS 	= -Wall

headers := mshStatusCode.h mshGetInput.h mshTokenize.h mshForkExec.h mshFree.h
objects := msh.o mshGetInput.o mshTokenize.o mshForkExec.o mshFree.o
executable := msh

$(executable): $(objects)
	$(CC) $(CFLAGS) $(objects) -o $@

%.o: %.c $(headers)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(executable) $(objects)
