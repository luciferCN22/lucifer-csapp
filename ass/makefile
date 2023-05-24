CC = /usr/bin/gcc-9
CFLAGS = -Wall -g -O2 -Werror -std=gnu99

EXE = program

SRC = ./src

CODE =./src/cpu/mmu.c ./src/memory/dram.c ./src/memory/instruction.c ./src/disk/code.c ./src/main.c 

.PHONY: program
main:
	$(CC) $(CFLAGS) -I$(SRC) $(CODE) -o $(EXE)    # -I$(SRC)设置路径

run:
	./$(EXE)
