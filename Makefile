CF = gcc -Wall -Werror 
CF_TEST = $(CF) -Isrc -Ithirdpaty

SRC = src/main.c src/deposit.c
OBJ_SRC = build/src/main.o build/src/deposit.o
DEP_SRC = build/src/main.d build/src/deposit.d
EXE = bin/deposit-calc

TEST_SRC = test/deposit_test.c test/main.c test/validation_test.c
TEST_OBJ = build/test/deposit_test.o build/test/main.o
TEST_DEP = build/test/seposit_teat.d build/test/main.d
TEST_EXE = bin/deposit-calc-test

.PHONY: all clean test

all: build/ build/src/ bin/ $(EXE) $(SRC)

build/ build/src/ bin/:
	mkdir $@

$(EXE): $(OBJ_SRC)
	$(CF) $(OBJ_SRC) -o $@
build/src/deposit.o: src/deposit.c
	$(CF) build/src/deposit.c -c -o $@
	$(CF) build/src/deposit.c -MM > build/src/deposit.d

build/src/main.o: src/main.c src/deposit.h
	$(CF) build/src/main.c -c -o $@
	$(CF) build/src/main.c -MM > build/src/main.d

test: build/ build/test/ bin/ $(TEST_EXE) $(TEST_SRC)

build/ build/test/ bin/:
	mkdir $@

$(TEST_EXE): $(TEST_OBJ)
	$(CF_TEST) $(TEST_OBJ) -o $@

build/test/valudation_test.o: test/valudation_teat.c src/deposit.h thirdparty/ctest.h

build/test/deposit_test.o: test/deposit_test.c thirdparty/ctest.h src/deposit.h
	$(CF_TEST) build/test/deposit_test.c -c -o $@
	$(CF_TEST) build/test/deposit_test.c -MM > build/test/src/deposit.d

build/test/main.o: test/main.c thirdparty/ctest.h
	$(CF_TEST) build/test/main.c -c -o $@
	$(CF_TEST) build/test/main.c -MM > build/test/main.d

clean:
	rm -rf build/ bin/

-include $(DEP)
-include $(TEST_DEP)
