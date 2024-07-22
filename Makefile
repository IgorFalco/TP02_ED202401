# Detect the OS and set variables accordingly
ifeq ($(OS),Windows_NT)
	EXE_EXT = .exe
else
	EXE_EXT = .out
endif

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/tp2.o $(OBJ)/grafoLista.o $(OBJ)/lista.o $(OBJ)/grafo_matrix.o $(OBJ)/priorityQueue.o
HEADERS = $(INC)/grafoLista.hpp $(INC)/grafo_matrix.hpp $(INC)/lista.hpp $(INC)/algoritmos.hpp $(INC)/priorityQueue.hpp $(INC)/auxiliar.hpp
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/tp2$(EXE_EXT)

$(BIN)/tp2$(EXE_EXT): $(OBJS)
	$(CC) -o $(BIN)/tp2$(EXE_EXT) $(OBJS) $(LIBS)

$(OBJ)/tp2.o: $(HEADERS) $(SRC)/tp2.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp2.o $(SRC)/tp2.cpp

$(OBJ)/grafoLista.o: $(HEADERS) $(SRC)/grafoLista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/grafoLista.o $(SRC)/grafoLista.cpp

$(OBJ)/grafo_matrix.o: $(HEADERS) $(SRC)/grafo_matrix.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/grafo_matrix.o $(SRC)/grafo_matrix.cpp

$(OBJ)/lista.o: $(HEADERS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp

$(OBJ)/matrix.o: $(HEADERS) $(SRC)/matrix.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matrix.o $(SRC)/matrix.cpp

$(OBJ)/priorityQueue.o: $(HEADERS) $(SRC)/priorityQueue.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/priorityQueue.o $(SRC)/priorityQueue.cpp

all: $(EXE)
 	
clean:
	rm -f $(EXE) $(OBJS)
