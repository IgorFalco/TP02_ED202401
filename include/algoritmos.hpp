#pragma once

#include <iostream>
#include <limits>
#include "grafoLista.hpp"
#include "priorityQueue.hpp"
#include "auxiliar.hpp"

// Definindo um valor infinito para a distância
const double INF = std::numeric_limits<double>::infinity();

// Função para calcular o menor caminho usando o algoritmo de Dijkstra
double *dijkstraLista(grafoLista &grafo, int origem, int *pred, Coordenada *coordenadas, int limitePortais)
{
    int n = grafo.getNumVertices();
    double *dist = new double[n];

    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF; // Distâncias iniciais são infinitas
        pred[i] = -1;
    }

    PriorityQueue pq(n);

    // Inicializar o ponto de origem
    dist[origem] = 0.0;
    pq.push(0.0, origem, 0);

    while (!pq.empty())
    {
        Item top = pq.top();
        double d = top.priority;
        int u = top.index;
        int portais_usados = top.portais_usados;
        pq.pop();

        // Se a distância atual for maior que a distância conhecida ou os portais usados forem maiores que o permitido, ignore
        if (d > dist[u] || portais_usados > limitePortais)
            continue;

        // Percorre os vizinhos
        Celula *atual = grafo.getAdjacencias(u);
        while (atual != nullptr)
        {
            int v = atual->vertice;

            double peso;
            if (grafo.isPortal(u, v))
            {
                peso = 0.0;
            }
            else
            {
                peso = calcularDistancia(coordenadas[u].x, coordenadas[u].y,
                                         coordenadas[v].x, coordenadas[v].y);
            }

            int novos_portais_usados = portais_usados + (grafo.isPortal(u, v) ? 1 : 0);

            if (novos_portais_usados > limitePortais)
            {
                atual = atual->proximo;
                continue;
            }

            // Relaxamento da aresta
            if (dist[u] + peso < dist[v])
            {
                dist[v] = dist[u] + peso;
                pred[v] = u;
                pq.push(dist[v], v, novos_portais_usados);
            }

            atual = atual->proximo;
        }
    }

    return dist;
}

// Função para calcular o menor caminho usando o algoritmo A*
double *aStarLista(grafoLista &grafo, int origem, int destino, Coordenada *coordenadas, int limitePortais)
{
    int n = grafo.getNumVertices();

    double *dist = new double[n];
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF; // Distâncias iniciais são infinitas
    }
    PriorityQueue pq(n);

    // Inicializar o ponto de origem
    dist[origem] = 0.0;
    pq.push(0.0, origem, 0);

    while (!pq.empty())
    {
        Item top = pq.top();
        double d = top.priority;
        int u = top.index;
        int portais_usados = top.portais_usados;

        pq.pop();

        // Se a distância atual for maior que a distância conhecida ou os portais usados forem maiores que o permitido, ignore
        if (dist[u] < d - calcularDistancia(coordenadas[u].x, coordenadas[u].y, coordenadas[destino].x, coordenadas[destino].y) || portais_usados > limitePortais)
            continue;

        // Se chegamos ao destino, termine a busca
        if (u == destino)
            break;

        // Percorre os vizinhos
        Celula *atual = grafo.getAdjacencias(u);
        while (atual != nullptr)
        {
            int v = atual->vertice;

            double peso;
            if (grafo.isPortal(u, v))
            {
                peso = 0.0;
            }
            else
            {
                peso = calcularDistancia(coordenadas[u].x, coordenadas[u].y,
                                         coordenadas[v].x, coordenadas[v].y);
            }

            int novos_portais_usados = portais_usados + (grafo.isPortal(u, v) ? 1 : 0);

            // Verifica se o número de portais usados excede o limite permitido
            if (novos_portais_usados > limitePortais)
            {
                atual = atual->proximo;
                continue;
            }

            // Cálculo da distância total e heurística
            double nova_distancia = dist[u] + peso;
            double heuristica = calcularDistancia(coordenadas[v].x, coordenadas[v].y,
                                                  coordenadas[destino].x, coordenadas[destino].y);

            double prioridade = nova_distancia + heuristica;

            // Relaxamento da aresta
            if (nova_distancia < dist[v])
            {
                dist[v] = nova_distancia;
                pq.push(prioridade, v, novos_portais_usados);
            }

            atual = atual->proximo;
        }
    }

    return dist;
}
