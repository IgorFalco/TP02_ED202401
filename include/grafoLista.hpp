#pragma once

#include "lista.hpp"

class grafoLista
{
private:
    ListaAdjacencia vertices;
    bool **portais; // Armazena pares de vértices que são portais

public:
    grafoLista(int v);
    ~grafoLista();
    void adicionarAresta(int origem, int destino);
    void adicionarPortal(int u, int v);
    void imprimir() const;
    int getNumVertices();
    Celula *getAdjacencias(int vertice);
    bool isPortal(int u, int v) const; // Verifica se uma aresta é um portal
};
