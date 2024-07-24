#pragma once

class grafoMatriz
{
private:
    bool **matriz;  
    bool **portais;
    int numVertices;

public:
    grafoMatriz(int v);
    ~grafoMatriz();
    void adicionarAresta(int origem, int destino);
    void adicionarPortal(int u, int v);
    void imprimir() const;
    int getNumVertices() const;
    bool isPortal(int u, int v) const;
    bool existeAresta(int origem, int destino) const;
};

