#include "priorityQueue.hpp"
#include <cassert>
#include <stdexcept>

// Função para reordenar o heap para cima
void PriorityQueue::heapifyUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[index].priority >= heap[parent].priority)
            break;
        Item temp = heap[index];
        heap[index] = heap[parent];
        heap[parent] = temp;
        index = parent;
    }
}

// Função para reordenar o heap para baixo
void PriorityQueue::heapifyDown(int index)
{
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < tamanho && heap[left].priority < heap[smallest].priority)
            smallest = left;
        if (right < tamanho && heap[right].priority < heap[smallest].priority)
            smallest = right;

        if (smallest != index)
        {
            Item temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

PriorityQueue::PriorityQueue(int cap) : capacidade(cap), tamanho(0)
{
    heap = new Item[capacidade];
}

PriorityQueue::~PriorityQueue()
{
    delete[] heap;
}

bool PriorityQueue::empty() const
{
    return tamanho == 0;
}

void PriorityQueue::push(double priority, int index, int portais_usados)
{
    if (tamanho == capacidade)
    {
        throw std::overflow_error("Heap capacity exceeded");
    }
    heap[tamanho] = {priority, index, portais_usados};
    heapifyUp(tamanho);
    tamanho++;
}

Item PriorityQueue::top() const
{
    assert(!empty()); // Assegura que a fila não está vazia
    return heap[0];
}

void PriorityQueue::pop()
{
    if (tamanho == 0)
    {
        throw std::underflow_error("Heap is empty");
    }
    heap[0] = heap[tamanho - 1];
    tamanho--;
    heapifyDown(0);
}
