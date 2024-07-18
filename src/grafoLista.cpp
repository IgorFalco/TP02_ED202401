#include "grafoLista.hpp"
#include <iostream>

grafoLista::grafoLista(int v) : vertices(v) {}

grafoLista::~grafoLista() {}

void grafoLista::adicionarAresta(int origem, int destino)
{
    vertices.adicionarAresta(origem, destino);
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