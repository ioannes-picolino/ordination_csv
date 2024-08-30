#include "CalculadorPeso.h"
#include <algorithm>
#include <cmath>

float CalculadorPeso::calcularMedia(const std::vector<Pessoa> &pessoas)
{
    // Implementação do cálculo da média
    if (pessoas.empty())
    {
        return 0.0; // Retornar 0 se o vetor estiver vazio
    }

    float soma = 0.0;
    for (const Pessoa &pessoa : pessoas)
    {
        soma += pessoa.getPeso();
    }

    return soma / pessoas.size();
}

float CalculadorPeso::calcularMediana(const std::vector<Pessoa> &pessoas)
{
    // Implementação do cálculo da mediana
    if (pessoas.empty())
    {
        return 0.0; // Retornar 0 se o vetor estiver vazio
    }

    std::vector<float> pesos;
    for (const Pessoa &pessoa : pessoas)
    {
        pesos.push_back(pessoa.getPeso());
    }

    std::sort(pesos.begin(), pesos.end());

    if (pesos.size() % 2 == 0)
    {
        // Se for par, calcular a média dos dois valores do meio
        return (pesos[pesos.size() / 2 - 1] + pesos[pesos.size() / 2]) / 2.0;
    }
    else
    {
        // Se for ímpar, retornar o valor do meio
        return pesos[pesos.size() / 2];
    }
}

float CalculadorPeso::calcularDesvioPadrao(const std::vector<Pessoa> &pessoas)
{
    // Implementação do cálculo do desvio padrão
    if (pessoas.empty())
    {
        return 0.0; // Retornar 0 se o vetor estiver vazio
    }

    float media = calcularMedia(pessoas);
    float somaDiferencasQuadradas = 0.0;

    for (const Pessoa &pessoa : pessoas)
    {
        float diferenca = pessoa.getPeso() - media;
        somaDiferencasQuadradas += diferenca * diferenca;
    }

    float variancia = somaDiferencasQuadradas / pessoas.size();
    return sqrt(variancia);
}
