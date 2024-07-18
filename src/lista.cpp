#include <iostream>
#include "lista.hpp"

// Implementação da classe Celula
Celula::Celula(int v) : vertice(v), proximo(nullptr) {}

// Implementação da classe Lista
Lista::Lista() : cabeca(nullptr) {}

void Lista::adicionar(int v)
{
    Celula *novoNo = new Celula(v);
    novoNo->proximo = cabeca;
    cabeca = novoNo;
}

ListaAdjacencia::ListaAdjacencia(int n) : numVertices(n)
{
    array = new Lista[numVertices];
}

ListaAdjacencia::~ListaAdjacencia()
{
    for (int i = 0; i < numVertices; ++i)
    {
        Celula *atual = array[i].cabeca;
        while (atual != nullptr)
        {
            Celula *proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
    }
    delete[] array;
}

void ListaAdjacencia::adicionarAresta(int origem, int destino)
{
    if (origem >= numVertices || destino >= numVertices)
    {
        std::cerr << "Índice de vértice inválido." << std::endl;
        return;
    }
    array[origem].adicionar(destino);
}