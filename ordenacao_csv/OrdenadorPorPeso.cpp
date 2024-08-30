#include "OrdenadorPorPeso.h"
#include <algorithm>
#include <iostream>

void OrdenadorPorPeso::bubbleSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo bubble sort para ordenação por peso
    int n = pessoas.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pessoas[j].getPeso() > pessoas[j + 1].getPeso())
            {
                std::swap(pessoas[j], pessoas[j + 1]);
            }
        }
    }
}

void OrdenadorPorPeso::insertionSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo insertion sort para ordenação por peso
    int n = pessoas.size();
    for (int i = 1; i < n; i++)
    {
        Pessoa key = pessoas[i];
        int j = i - 1;
        while (j >= 0 && pessoas[j].getPeso() > key.getPeso())
        {
            pessoas[j + 1] = pessoas[j];
            j = j - 1;
        }
        pessoas[j + 1] = key;
    }
}

void OrdenadorPorPeso::selectionSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo selection sort para ordenação por peso
    int n = pessoas.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (pessoas[j].getPeso() < pessoas[minIndex].getPeso())
            {
                minIndex = j;
            }
        }
        std::swap(pessoas[minIndex], pessoas[i]);
    }
}

void OrdenadorPorPeso::mergeSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo merge sort para ordenação por peso
    mergeSortHelper(pessoas, 0, pessoas.size() - 1);
}

void merge(std::vector<Pessoa> &pessoas, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<Pessoa> leftArray(n1), rightArray(n2);

    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = pessoas[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArray[j] = pessoas[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i].getPeso() <= rightArray[j].getPeso())
        {
            pessoas[k] = leftArray[i];
            i++;
        }
        else
        {
            pessoas[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        pessoas[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        pessoas[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSortHelper(std::vector<Pessoa> &pessoas, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSortHelper(pessoas, left, middle);
        mergeSortHelper(pessoas, middle + 1, right);
        merge(pessoas, left, middle, right);
    }
}

void OrdenadorPorPeso::quickSort(std::vector<Pessoa> &pessoas)
{
    // Implementação do algoritmo quick sort para ordenação por peso
    quickSortHelper(pessoas, 0, pessoas.size() - 1);
}

int partition(std::vector<Pessoa> &pessoas, int low, int high)
{
    float pivot = pessoas[high].getPeso();
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (pessoas[j].getPeso() < pivot)
        {
            i++;
            std::swap(pessoas[i], pessoas[j]);
        }
    }
    std::swap(pessoas[i + 1], pessoas[high]);
    return i + 1;
}

void quickSortHelper(std::vector<Pessoa> &pessoas, int low, int high)
{
    if (low < high)
    {
        int pi = partition(pessoas, low, high);
        quickSortHelper(pessoas, low, pi - 1);
        quickSortHelper(pessoas, pi + 1, high);
    }
}

void OrdenadorPorPeso::calcularMetricas(std::vector<Pessoa> &pessoas)
{
    // Implementação para calcular métricas de tempo para cada algoritmo de ordenação por peso
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
