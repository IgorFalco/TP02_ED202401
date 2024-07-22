#pragma once

#include <iostream>
#include <cmath>
#include "grafoLista.hpp"
#include "grafo_matrix.hpp"
#include "priorityQueue.hpp"


struct Coordenada {
    double x;
    double y;
};

double calcularDistancia(double x1, double y1, double x2, double y2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double calcularDistanciaTotalLista(int *caminho, Coordenada *coordenadas, grafoLista &grafo, int &tamanhoCaminho)
{
    double distanciaTotal = 0.0;
    for (size_t i = 0; i < static_cast<size_t>(tamanhoCaminho) - 1; ++i)
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
            double x1 = coordenadas[u].x;
            double y1 = coordenadas[u].y;
            double x2 = coordenadas[v].x;
            double y2 = coordenadas[v].y;
            distanciaTotal += calcularDistancia(x1, y1, x2, y2);
        }
    }
    return distanciaTotal;
}

double calcularDistanciaTotalMatriz(int *caminho, Coordenada *coordenadas, grafoMatriz &grafo, int tamanhoCaminho)
{
    double distanciaTotal = 0.0;
    for (size_t i = 0; i <  static_cast<size_t>(tamanhoCaminho) - 1; ++i)
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
            double x1 = coordenadas[u].x;
            double y1 = coordenadas[u].y;
            double x2 = coordenadas[v].x;
            double y2 = coordenadas[v].y;
            distanciaTotal += calcularDistancia(x1, y1, x2, y2);
        }
    }
    return distanciaTotal;
}

void reverseArray(int *array, int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        ++start;
        --end;
    }
}
// Função para reconstruir o caminho a partir dos predecessores
int *reconstruirCaminho(const int *pred, int destino, int &tamanhoCaminho)
{
    // Primeiro, contamos o número de elementos no caminho
    int count = 0;
    for (int v = destino; v != -1; v = pred[v])
    {
        ++count;
    }

    // Alocamos memória para o caminho
    int *caminho = new int[count];
    tamanhoCaminho = count;
    // Preenchemos o caminho em ordem reversa
    int index = 0;
    for (int v = destino; v != -1; v = pred[v])
    {
        caminho[index++] = v;
    }

    // Reverte o caminho para obter a ordem correta
    reverseArray(caminho, count);

    return caminho;
}