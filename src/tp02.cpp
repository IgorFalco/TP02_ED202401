#include <iostream>
#include "lista.hpp"
#include "grafoLista.hpp"

int main()
{

    grafoLista grafo(5);

    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 4);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 4);
    grafo.adicionarAresta(2, 3);
    grafo.adicionarAresta(3, 4);
    grafo.imprimir();

    return 0;
}
