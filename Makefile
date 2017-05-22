CF = gcc -Wall -Werror 
SRC = src/main.c src/deposit.c
OBJ = build/main.o build/deposit.o
DEP = build/main.d build/deposit.d
EXE = bin/deposit-calc

all: build/ bin/ $(EXE) $(SRC)

build/ bin/:
	mkdir $@

$(EXE): $(OBJ)
	$(CF) $(OBJ) -o $@
build/deposit.o: src/deposit.c
	$(CF) src/deposit.c -c -o $@
	$(CF) src/deposit.c -MM > build/deposit.d

build/main.o: src/main.c src/deposit.h
	$(CF) src/main.c -c -o $@
	$(CF) src/main.c -MM > build/main.d

.PHONY: clean
clean:
	rm -rf build/ bin/

-include $(DEP)
