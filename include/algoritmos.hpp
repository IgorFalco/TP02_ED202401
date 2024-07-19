#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <functional>
#include <algorithm>
#include "grafoLista.hpp"
#include "priorityQueue.hpp"

// Definindo um valor infinito para a distância
const double INF = std::numeric_limits<double>::infinity();

double calcularDistancia(double x1, double y1, double x2, double y2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double calcularDistanciaTotal(const std::vector<int> &caminho, const std::vector<std::pair<double, double>> &coordenadas, grafoLista &grafo)
{
    double distanciaTotal = 0.0;
    for (size_t i = 0; i < caminho.size() - 1; ++i)
    {
        int u = caminho[i];
        int v = caminho[i + 1];

        if (grafo.isPortal(u, v))
        {
            // Se a aresta é um portal, a distância é 0
            distanciaTotal += 0.0;
        }
        else
        {
            // Calcula a distância euclidiana
            double x1 = coordenadas[u].first;
            double y1 = coordenadas[u].second;
            double x2 = coordenadas[v].first;
            double y2 = coordenadas[v].second;
            distanciaTotal += calcularDistancia(x1, y1, x2, y2);
        }
    }
    return distanciaTotal;
}

// Função para reconstruir o caminho a partir dos predecessores
std::vector<int> reconstruirCaminho(const std::vector<int> &pred, int destino)
{
    std::vector<int> caminho;
    for (int v = destino; v != -1; v = pred[v])
    {
        caminho.push_back(v);
    }
    std::reverse(caminho.begin(), caminho.end());
    return caminho;
}

// Função para calcular o menor caminho usando o algoritmo de Dijkstra
std::vector<double> dijkstra(grafoLista &grafo, int origem, std::vector<int> &pred, const std::vector<std::pair<double, double>> &coordenadas, int limitePortais)
{
    int n = grafo.getNumVertices();
    std::vector<double> dist(n, INF); // Distâncias iniciais são infinitas
    pred.assign(n, -1);               // Predecessores para reconstruir o caminho
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
                peso = calcularDistancia(coordenadas[u].first, coordenadas[u].second,
                                         coordenadas[v].first, coordenadas[v].second);
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
std::vector<double> aStar(grafoLista &grafo, int origem, int destino, std::vector<int> &pred, const std::vector<std::pair<double, double>> &coordenadas, int limitePortais)
{
    int n = grafo.getNumVertices();
    std::vector<double> dist(n, INF); // Distâncias iniciais são infinitas
    pred.assign(n, -1);               // Predecessores para reconstruir o caminho
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
        if (dist[u] < d - calcularDistancia(coordenadas[u].first, coordenadas[u].second, coordenadas[destino].first, coordenadas[destino].second) || portais_usados > limitePortais)
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
                peso = calcularDistancia(coordenadas[u].first, coordenadas[u].second,
                                         coordenadas[v].first, coordenadas[v].second);
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
            double heuristica = calcularDistancia(coordenadas[v].first, coordenadas[v].second,
                                                  coordenadas[destino].first, coordenadas[destino].second);
            double prioridade = nova_distancia + heuristica;

            // Relaxamento da aresta
            if (nova_distancia < dist[v])
            {
                dist[v] = nova_distancia;
                pred[v] = u;
                pq.push(prioridade, v, novos_portais_usados);
            }

            atual = atual->proximo;
        }
    }

    return dist;
}
