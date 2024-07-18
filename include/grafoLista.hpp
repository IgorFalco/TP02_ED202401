#pragma once

#include "lista.hpp"

class grafoLista
{
private:
    ListaAdjacencia vertices;

public:
    grafoLista(int v);
    ~grafoLista();
    void adicionarAresta(int origem, int destino);
    void imprimir() const;
};
