#include "CalculadorAltura.h"
#include <algorithm>
#include <cmath>

float CalculadorAltura::calcularMedia(const std::vector<Pessoa> &pessoas)
{
    // Implementação do cálculo da média
    if (pessoas.empty())
    {
        return 0.0; // Retornar 0 se o vetor estiver vazio
    }

    float soma = 0.0;
    for (const Pessoa &pessoa : pessoas)
    {
        soma += pessoa.getAltura();
    }

    return soma / pessoas.size();
}

float CalculadorAltura::calcularMediana(const std::vector<Pessoa> &pessoas)
{
    // Implementação do cálculo da mediana
    if (pessoas.empty())
    {
        return 0.0; // Retornar 0 se o vetor estiver vazio
    }

    std::vector<float> alturas;
    for (const Pessoa &pessoa : pessoas)
    {
        alturas.push_back(pessoa.getAltura());
    }

    std::sort(alturas.begin(), alturas.end());

    if (alturas.size() % 2 == 0)
    {
        // Se for par, calcular a média dos dois valores do meio
        return (alturas[alturas.size() / 2 - 1] + alturas[alturas.size() / 2]) / 2.0;
    }
    else
    {
        // Se for ímpar, retornar o valor do meio
        return alturas[alturas.size() / 2];
    }
}

float CalculadorAltura::calcularDesvioPadrao(const std::vector<Pessoa> &pessoas)
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
        float diferenca = pessoa.getAltura() - media;
        somaDiferencasQuadradas += diferenca * diferenca;
    }

    float variancia = somaDiferencasQuadradas / pessoas.size();
    return sqrt(variancia);
}
