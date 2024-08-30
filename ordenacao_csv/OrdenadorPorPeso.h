#ifndef ORDENADORPESO_H
#define ORDENADORPESO_H

#include "Ordenador.h"

class OrdenadorPorPeso : public Ordenador {
public:
    void bubbleSort(std::vector<Pessoa>& pessoas) override;
    void insertionSort(std::vector<Pessoa>& pessoas) override;
    void selectionSort(std::vector<Pessoa>& pessoas) override;
    void mergeSort(std::vector<Pessoa>& pessoas) override;
    void quickSort(std::vector<Pessoa>& pessoas) override;
    void calcularMetricas(std::vector<Pessoa>& pessoas) override;
};

#endif // ORDENADORPESO_H
