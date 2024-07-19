#pragma once

// Estrutura para armazenar elementos na fila de prioridade
struct Item
{
    double priority;
    int index;
    int portais_usados;
};

// Classe de fila de prioridade personalizada
class PriorityQueue
{
private:
    Item *heap;     // Armazena elementos (prioridade, índice)
    int capacidade; // Capacidade máxima do heap
    int tamanho;    // Tamanho atual do heap

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    PriorityQueue(int cap);
    ~PriorityQueue();

    bool empty() const;
    void push(double priority, int index, int portais_usados);
    Item top() const;
    void pop();
};
