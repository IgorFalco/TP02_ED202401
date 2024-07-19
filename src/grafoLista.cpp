#include "grafoLista.hpp"
#include <iostream>

grafoLista::grafoLista(int v) : vertices(v) {}

grafoLista::~grafoLista() {}

void grafoLista::adicionarAresta(int origem, int destino)
{
    vertices.adicionarAresta(origem, destino);
}

void grafoLista::adicionarPortal(int u, int v)
{
    portais.insert({u, v});
}

bool grafoLista::isPortal(int u, int v) const
{
    return portais.find({u, v}) != portais.end();
}

void grafoLista::imprimir() const
{
    for (int i = 0; i < vertices.numVertices; ++i)
    {
        std::cout << "Vértice " << i << ": ";
        Celula *atual = vertices.array[i].cabeca;
        while (atual != nullptr)
        {
            std::cout << atual->vertice << " ";
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }
}

int grafoLista::getNumVertices()
{
    return vertices.numVertices;
}

Celula *grafoLista::getAdjacencias(int vertice)
{
    if (vertice >= 0 && vertice < getNumVertices())
    {
        return vertices.array[vertice].cabeca;
    }
    return nullptr; // Retorna nullptr se o vértice estiver fora do intervalo
}