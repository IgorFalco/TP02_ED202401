#pragma once

#include "lista.hpp"
#include <unordered_set>

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2; // Combine os dois hashes
    }
};

class grafoLista
{
private:
    ListaAdjacencia vertices;
    std::unordered_set<std::pair<int, int>, pair_hash> portais; // Armazena pares de vértices que são portais

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
