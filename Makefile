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
OBJS = $(OBJ)/tp02.o $(OBJ)/grafo_lista.o $(OBJ)/lista.o $(OBJ)/grafo_matrix.o $(OBJ)/matrix.o
HEADERS = $(INC)/grafo_lista.hpp $(INC)/grafo_matrix.hpp $(INC)/lista.hpp $(INC)/matrix.hpp
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/tp02$(EXE_EXT)

$(BIN)/tp02$(EXE_EXT): $(OBJS)
	$(CC) -o $(BIN)/tp02$(EXE_EXT) $(OBJS) $(LIBS)

$(OBJ)/tp02.o: $(HEADERS) $(SRC)/tp02.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp02.o $(SRC)/tp02.cpp

$(OBJ)/grafo_lista.o: $(HEADERS) $(SRC)/grafo_lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/grafo_lista.o $(SRC)/grafo_lista.cpp

$(OBJ)/lista.o: $(HEADERS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp

$(OBJ)/grafo_matrix.o: $(HEADERS) $(SRC)/grafo_matrix.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/grafo_matrix.o $(SRC)/grafo_matrix.cpp

$(OBJ)/matrix.o: $(HEADERS) $(SRC)/matrix.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matrix.o $(SRC)/matrix.cpp

all: $(EXE)
 	
clean:
	rm -f $(EXE) $(OBJS)
