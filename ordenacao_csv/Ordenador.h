#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <vector>
#include "Pessoa.h"
#include <chrono>

class Ordenador {
public:
    virtual void bubbleSort(std::vector<Pessoa>& pessoas) = 0;
    virtual void insertionSort(std::vector<Pessoa>& pessoas) = 0;
    virtual void selectionSort(std::vector<Pessoa>& pessoas) = 0;
    virtual void mergeSort(std::vector<Pessoa>& pessoas) = 0;
    virtual void quickSort(std::vector<Pessoa>& pessoas) = 0;
    virtual void calcularMetricas(std::vector<Pessoa>& pessoas) = 0; // Método para calcular métricas de tempo
    virtual ~Ordenador() {}
protected:
    void calcularTempo(std::chrono::steady_clock::time_point inicio,
                       std::chrono::steady_clock::time_point fim,
                       const std::string& nomeAlgoritmo);
};

#endif // ORDENADOR_H
