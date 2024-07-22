#include "grafo_matrix.hpp"
#include <iostream>

grafoMatriz::grafoMatriz(int v) : numVertices(v)
{
    matriz = new bool *[numVertices];
    portais = new bool *[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        matriz[i] = new bool[numVertices];
        portais[i] = new bool[numVertices];
        for (int j = 0; j < numVertices; ++j)
        {
            matriz[i][j] = false;
            portais[i][j] = false;
        }
    }
}

grafoMatriz::~grafoMatriz()
{
    for (int i = 0; i < numVertices; ++i)
    {
        delete[] matriz[i];
        delete[] portais[i];
    }
    delete[] matriz;
    delete[] portais;
}

void grafoMatriz::adicionarAresta(int origem, int destino)
{
    if (origem >= numVertices || destino >= numVertices)
    {
        std::cerr << "Índice de vértice inválido." << std::endl;
        return;
    }
    matriz[origem][destino] = true;
}

void grafoMatriz::adicionarPortal(int u, int v)
{
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
    {
        portais[u][v] = true;
    }
}

bool grafoMatriz::isPortal(int u, int v) const
{
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
    {
        return portais[u][v];
    }
    return false;
}

bool grafoMatriz::existeAresta(int origem, int destino) const
{
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices)
    {
        return matriz[origem][destino];
    }
    return false;
}

void grafoMatriz::imprimir() const
{
    for (int i = 0; i < numVertices; ++i)
    {
        std::cout << "Vértice " << i << ": ";
        for (int j = 0; j < numVertices; ++j)
        {
            if (matriz[i][j])
            {
                std::cout << j << " ";
            }
        }
        std::cout << std::endl;
    }
}

int grafoMatriz::getNumVertices() const
{
    return numVertices;
}
