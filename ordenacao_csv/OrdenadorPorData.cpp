#include "OrdenadorPorData.h"
#include <algorithm>
#include <iostream>

void OrdenadorPorData::bubbleSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo bubble sort para ordenação por data
    int n = pessoas.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pessoas[j].getData() > pessoas[j + 1].getData())
            {
                std::swap(pessoas[j], pessoas[j + 1]);
            }
        }
    }
}

void OrdenadorPorData::insertionSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo insertion sort para ordenação por data
    int n = pessoas.size();
    for (int i = 1; i < n; i++)
    {
        Pessoa chave = pessoas[i];
        int j = i - 1;
        while (j >= 0 && pessoas[j].getData() > chave.getData())
        {
            pessoas[j + 1] = pessoas[j];
            j = j - 1;
        }
        pessoas[j + 1] = chave;
    }
}

void OrdenadorPorData::selectionSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo selection sort para ordenação por data
    int n = pessoas.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (pessoas[j].getData() < pessoas[min_idx].getData())
            {
                min_idx = j;
            }
        }
        std::swap(pessoas[min_idx], pessoas[i]);
    }
}

void OrdenadorPorData::mergeSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo merge sort para ordenação por data
    if (pessoas.size() <= 1)
        return;

    std::vector<Pessoa> left, right;
    int middle = pessoas.size() / 2;

    for (size_t i = 0; i < middle; i++)
    {
        left.push_back(pessoas[i]);
    }
    for (size_t i = middle; i < pessoas.size(); i++)
    {
        right.push_back(pessoas[i]);
    }

    mergeSort(left);
    mergeSort(right);
    merge(pessoas, left, right);
}

void OrdenadorPorData::merge(std::vector<Pessoa> &result, const std::vector<Pessoa> &left, const std::vector<Pessoa> &right)
{
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i].getData() < right[j].getData())
        {
            result[k] = left[i];
            i++;
        }
        else
        {
            result[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size())
    {
        result[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size())
    {
        result[k] = right[j];
        j++;
        k++;
    }
}

void OrdenadorPorData::quickSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo quick sort para ordenação por data
    quickSortRecursivo(pessoas, 0, pessoas.size() - 1);
}

void OrdenadorPorData::quickSortRecursivo(std::vector<Pessoa>& pessoas, int inicio, int fim) {
    if (inicio < fim) {
        int pi = particao(pessoas, inicio, fim);
        quickSortRecursivo(pessoas, inicio, pi - 1);
        quickSortRecursivo(pessoas, pi + 1, fim);
    }
}

int OrdenadorPorData::particao(std::vector<Pessoa>& pessoas, int inicio, int fim) {
    Pessoa pivot = pessoas[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++) {
        if (pessoas[j].getData() < pivot.getData()) {
            i++;
            std::swap(pessoas[i], pessoas[j]);
        }
    }

    std::swap(pessoas[i + 1], pessoas[fim]);
    return i + 1;
}

void OrdenadorPorData::calcularMetricas(std::vector<Pessoa> &pessoas)
{
    // Implementação para calcular métricas de tempo para cada algoritmo de ordenação por data
    std::cout << "Métricas de tempo de execução dos algoritmos de ordenação:" << std::endl;

    auto start = std::chrono::steady_clock::now();
    bubbleSort(pessoas);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Bubble Sort: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    insertionSort(pessoas);
    end = std::chrono::steady_clock::now();
    std::cout << "Insertion Sort: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    selectionSort(pessoas);
    end = std::chrono::steady_clock::now();
    std::cout << "Selection Sort: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    mergeSort(pessoas);
    end = std::chrono::steady_clock::now();
    std::cout << "Merge Sort: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    quickSort(pessoas);
    end = std::chrono::steady_clock::now();
    std::cout << "Quick Sort: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
}
