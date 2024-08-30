#ifndef ORDENADORDATA_H
#define ORDENADORDATA_H

#include "Ordenador.h"

class OrdenadorPorData : public Ordenador {
public:
    void bubbleSort(std::vector<Pessoa>& pessoas) override;
    void insertionSort(std::vector<Pessoa>& pessoas) override;
    void selectionSort(std::vector<Pessoa>& pessoas) override;
    void mergeSort(std::vector<Pessoa>& pessoas) override;
    void merge(std::vector<Pessoa> &result, const std::vector<Pessoa> &left, const std::vector<Pessoa> &right);
    void quickSort(std::vector<Pessoa> &pessoas) override;
    void quickSortRecursivo(std::vector<Pessoa>& pessoas, int inicio, int fim);
    int particao(std::vector<Pessoa> &pessoas, int inicio, int fim);
    void calcularMetricas(std::vector<Pessoa> &pessoas) override;
};

#endif // ORDENADORDATA_H
