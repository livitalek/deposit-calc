CF = gcc -Wall -Werror
CF_TEST = $(CF) -Isrc -Ithirdparty

OBJ_DIR = build/src
SRC_DIR = src
TEST_OBJ_DIR = build/test
TEST_SRC_DIR = test

EXE = bin/deposit-calc
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEP = $(OBJ:.o=.d)

TEST_EXE := bin/deposit-calc-test
TEST_SRC := $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJ := $(patsubst $(TEST_SRC_DIR)/%.c, $(TEST_OBJ_DIR)/%.o, $(TEST_SRC))
TEST_DEP := $(TEST_OBJ:.o=.d)

-include $(DEP)
-include $(TEST_DEP)

.PHONY: all clean test


all: build/ $(OBJ_DIR) bin/ $(EXE) $(SRC)

build/ $(OBJ_DIR) $(TEST_OBJ_DIR) bin/:
	mkdir $@

$(EXE): $(OBJ)
	$(CF) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CF) $^ -c -o $@ 
	$(CF) $^ -MM > $(OBJ_DIR)/$*.d 



test: all $(TEST_OBJ_DIR) $(TEST_EXE) $(TEST_SRC)

$(TEST_EXE): $(TEST_OBJ) $(patsubst build/src/main.o, ,$(OBJ))
	$(CF_TEST) $^ -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	$(CF_TEST) $^ -c -o $@
	$(CF_TEST) $^ -MM > $(TEST_OBJ_DIR)/$*.d


clean:
	rm -rf build bin