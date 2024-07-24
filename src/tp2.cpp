#include <iostream>
#include "lista.hpp"
#include "grafoLista.hpp"
#include "algoritmos.hpp"
#include "auxiliar.hpp"

int main()
{
    int numVertices, numArestas, numPortais;

    std::cin >> numVertices >> numArestas >> numPortais;

    grafoLista grafo(numVertices);

    Coordenada *coordenadas = new Coordenada[numVertices];

    for (int i = 0; i < numVertices; ++i)
    {
        double x, y;
        std::cin >> x >> y;
        coordenadas[i].x = x;
        coordenadas[i].y = y;
    }

    for (int i = 0; i < numArestas; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        grafo.adicionarAresta(u, v);
    }

    for (int i = 0; i < numPortais; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        grafo.adicionarAresta(u, v); // Adiciona as arestras e os portais
        grafo.adicionarPortal(u, v); // As arestas serão conferidas na matriz de portais, para saber se elas são ligadas por portais ou não!
    }

    double energia;
    int limitePortais;
    std::cin >> energia >> limitePortais;

    // Vetor para armazenar os predecessores
    int *pred = new int[numVertices];
    int tamanhoCaminho;

    double *dist = dijkstraLista(grafo, 0, pred, coordenadas, limitePortais);
    int *caminho = reconstruirCaminho(pred, numVertices - 1, tamanhoCaminho);
    double distanciaTotalDijkstra = calcularDistanciaTotalLista(caminho, coordenadas, grafo, tamanhoCaminho);

    dist = aStarLista(grafo, 0, numVertices - 1, coordenadas, limitePortais);
    double distanciaTotalEstrela = dist[numVertices - 1];

    // Verifica se a distância total é menor ou igual à energia disponível
    if (distanciaTotalDijkstra <= energia)
    {
        std::cout << 1 << " ";
    }
    else
    {
        std::cout << 0 << " ";
    }

    if (distanciaTotalEstrela <= energia)
    {
        std::cout << 1;
    }
    else
    {
        std::cout << 0;
    }

    delete[] pred;
    delete[] caminho;
    delete[] dist;
    delete[] coordenadas;

    return 0;
}