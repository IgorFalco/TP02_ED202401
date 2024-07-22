#pragma once

class grafoMatriz
{
private:
    bool **matriz;      // Matriz de adjacência para as arestas
    bool **portais;     // Matriz de adjacência para os portais
    int numVertices;

public:
    grafoMatriz(int v);
    ~grafoMatriz();
    void adicionarAresta(int origem, int destino);
    void adicionarPortal(int u, int v);
    void imprimir() const;
    int getNumVertices() const;
    bool isPortal(int u, int v) const; // Verifica se uma aresta é um portal
    bool existeAresta(int origem, int destino) const;
};

