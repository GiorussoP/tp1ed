## configurações do compilador
CC := g++
CFLAGS := -Wall -g -O3

##  definição de diretórios
INC_DIR := include
OBJ_DIR := obj
SRC_DIR := src
BIN_DIR := bin

LIBS :=

## linking das bibliotecas usadas
LINKING :=

## saída
EXEC_NAME := tp1.exe


## FUNCIONAMENTO

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

OBJS := $(SRCS:%= $(OBJ_DIR)/%.o)

#################### make / make all ######################

all: $(BIN_DIR)/$(EXEC_NAME)

$(BIN_DIR)/$(EXEC_NAME) : $(OBJS)
	mkdir -p $(dir $@)
	$(CC) $(LIBS) $^ -o $@ $(LINKING)

$(OBJ_DIR)/$(SRC_DIR)/%.cpp.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./$(INC_DIR)/ -c $^ -o $@

$(OBJ_DIR)/$(SRC_DIR)/%.c.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./$(INC_DIR)/ -c $^ -o $@

#################### make run ######################

run : all
	./$(BIN_DIR)/$(EXEC_NAME)

.PHONY: clean rebuild install

#################### make clean ######################

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

#################### make run ######################

rebuild :
	make clean
	make all

#################### make install ######################

install :
	sudo apt-get install gnuplot