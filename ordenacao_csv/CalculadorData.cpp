#include "CalculadorData.h"
#include <algorithm>
#include <cmath>

float CalculadorData::convertDateToYear(const std::string& date) {
    // Supondo que a data esteja no formato "AAAA-MM-DD"
    int ano = std::stoi(date.substr(0, 4));
    int mes = std::stoi(date.substr(5, 2));
    int dia = std::stoi(date.substr(8, 2));

    float anoDecimal = ano + (mes - 1) / 12.0f + (dia - 1) / 365.0f;
    return anoDecimal;
}

float CalculadorData::calcularMedia(const std::vector<Pessoa>& pessoas) {
    float soma = 0.0f;
    for (const auto& pessoa : pessoas) {
        soma += convertDateToYear(pessoa.getData());
    }
    return soma / pessoas.size();
}

float CalculadorData::calcularMediana(const std::vector<Pessoa>& pessoas) {
    std::vector<std::string> datas;
    for (const auto& pessoa : pessoas) {
        datas.push_back(pessoa.getData());
    }

    std::sort(datas.begin(), datas.end());

    int tamanho = datas.size();
    if (tamanho % 2 == 0) {
        return (convertDateToYear(datas[tamanho/2 - 1]) + convertDateToYear(datas[tamanho/2])) / 2.0f;
    } else {
        return convertDateToYear(datas[tamanho/2]);
    }
}

float CalculadorData::calcularDesvioPadrao(const std::vector<Pessoa>& pessoas) {
    float media = calcularMedia(pessoas);
    float soma = 0.0f;
    for (const auto& pessoa : pessoas) {
        float diferenca = convertDateToYear(pessoa.getData()) - media;
        soma += diferenca * diferenca;
    }
    return std::sqrt(soma / pessoas.size());
}
