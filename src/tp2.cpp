#include <iostream>
#include <vector>
#include <utility>
#include "lista.hpp"
#include "grafoLista.hpp"
#include "algoritmos.hpp"

int main()
{
    int numVertices, numArestas, numPortais;
    std::cin >> numVertices >> numArestas >> numPortais;

    grafoLista grafo(numVertices);

    // Ler as coordenadas dos vértices
    std::vector<std::pair<double, double>> coordenadas(numVertices);
    for (int i = 0; i < numVertices; ++i)
    {
        double x, y;
        std::cin >> x >> y;
        coordenadas[i] = std::make_pair(x, y);
    }

    // Ler as arestas
    for (int i = 0; i < numArestas; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        grafo.adicionarAresta(u, v);
    }

    // Ler os portais
    for (int i = 0; i < numPortais; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        grafo.adicionarAresta(u, v);
        grafo.adicionarPortal(u, v);
    }

    // Ler a energia e o número de portais que podem ser usados
    double energia;
    int limitePortais;
    std::cin >> energia >> limitePortais;

    // Vetor para armazenar os predecessores
    std::vector<int> pred;
    std::vector<int> predstar;

    std::vector<double> dist = dijkstra(grafo, 0, pred, coordenadas, limitePortais);
    std::vector<int> caminho = reconstruirCaminho(pred, numVertices - 1);
    double distanciaTotalDijkstra = calcularDistanciaTotal(caminho, coordenadas, grafo);

    dist = aStar(grafo, 0, numVertices - 1, predstar, coordenadas, limitePortais);
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

    // grafo.imprimir();

    // std::cout << "Caminho: ";
    // for (int v : caminho)
    // {
    //     std::cout << v << " ";
    // }
    // std::cout << std::endl;

    return 0;
}