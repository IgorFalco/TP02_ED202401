#include "grafoLista.hpp"
#include <iostream>

grafoLista::grafoLista(int v) : vertices(v)
{
    portais = new bool *[vertices.numVertices];
    for (int i = 0; i < vertices.numVertices; i++)
    {
        portais[i] = new bool[vertices.numVertices];
        for (int j = 0; j < vertices.numVertices; ++j)
        {
            portais[i][j] = false;
        }
    }
}

grafoLista::~grafoLista()
{
    for (int i = 0; i < vertices.numVertices; ++i)
    {
        delete[] portais[i];
    }
    delete[] portais;
}

void grafoLista::adicionarAresta(int origem, int destino)
{
    vertices.adicionarAresta(origem, destino);
}

void grafoLista::adicionarPortal(int u, int v)
{
    if (u >= 0 && u < vertices.numVertices && v >= 0 && v < vertices.numVertices)
    {
        portais[u][v] = true;
    }
}

bool grafoLista::isPortal(int u, int v) const
{
    if (u >= 0 && u < vertices.numVertices && v >= 0 && v < vertices.numVertices)
    {
        return portais[u][v];
    }
    return false;
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