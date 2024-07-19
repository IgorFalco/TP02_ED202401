#pragma once

#include <iostream>

class Celula
{
public:
    int vertice;
    Celula *proximo;

    Celula(int v);
};

// Classe para representar a lista de adjacência
class Lista
{
public:
    Celula *cabeca;

    Lista();
    void adicionar(int v);
};

// Classe para representar o grafo usando lista de adjacência
class ListaAdjacencia
{

public:
    Lista *array;
    int numVertices;
    ListaAdjacencia(int n);
    ~ListaAdjacencia();

    void adicionarAresta(int origem, int destino);
};