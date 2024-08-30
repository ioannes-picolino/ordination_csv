#include <iostream>
#include <vector>
#include "Pessoa.h"
#include "LeitorCSV.h"
#include "CalculadorData.h"
#include "CalculadorPeso.h"
#include "CalculadorAltura.h"
#include "OrdenadorPorData.h"
#include "OrdenadorPorPeso.h"
#include "OrdenadorPorAltura.h"

int main() {
    // Nome do arquivo CSV a ser lido
    std::string nomeArquivo = "dados_pessoais.csv";

    // Vetor para armazenar as pessoas lidas do arquivo
    std::vector<Pessoa> pessoas;

    // Objeto para ler o arquivo CSV e preencher o vetor de pessoas
    LeitorCSV leitor;
    bool sucessoLeitura = leitor.lerArquivo(nomeArquivo, pessoas);

    if (sucessoLeitura) {
        // Exibir as pessoas lidas do arquivo
        for (const auto& pessoa : pessoas) {
            std::cout << "Nome: " << pessoa.getNome() << ", Data: " << pessoa.getData() << ", Peso: " << pessoa.getPeso() << ", Altura: " << pessoa.getAltura() << std::endl;
        }

        // Criar objetos CalculadorData, CalculadorPeso e CalculadorAltura para calcular estatísticas
        CalculadorData calculadorData;
        CalculadorPeso calculadorPeso;
        CalculadorAltura calculadorAltura;

        // Calcular e exibir as estatísticas de data, peso e altura
        std::cout << "\nEstatisticas de Data:\n";
        calculadorData.calcularMedia(pessoas);
        calculadorData.calcularMediana(pessoas);
        calculadorData.calcularDesvioPadrao(pessoas);

        std::cout << "\nEstatisticas de Peso:\n";
        calculadorPeso.calcularMedia(pessoas);
        calculadorPeso.calcularMediana(pessoas);
        calculadorPeso.calcularDesvioPadrao(pessoas);

        std::cout << "\nEstatisticas de Altura:\n";
        calculadorAltura.calcularMedia(pessoas);
        calculadorAltura.calcularMediana(pessoas);
        calculadorAltura.calcularDesvioPadrao(pessoas);

        // Criar objetos OrdenadorPorData, OrdenadorPorPeso e OrdenadorPorAltura para ordenação
        OrdenadorPorData ordenadorData;
        OrdenadorPorPeso ordenadorPeso;
        OrdenadorPorAltura ordenadorAltura;

        // Ordenar as pessoas por data, peso e altura
        ordenadorData.bubbleSort(pessoas);
        ordenadorData.calcularMetricas(pessoas);
        ordenadorPeso.insertionSort(pessoas);
        ordenadorPeso.calcularMetricas(pessoas);
        ordenadorAltura.selectionSort(pessoas);
        ordenadorAltura.calcularMetricas(pessoas);

        // Exibir as pessoas ordenadas
        std::cout << "\nPessoas ordenadas:\n";
        for (const auto& pessoa : pessoas) {
            std::cout << "Nome: " << pessoa.getNome() << ", Data: " << pessoa.getData() << ", Peso: " << pessoa.getPeso() << ", Altura: " << pessoa.getAltura() << std::endl;
        }
    } else {
        std::cerr << "Erro ao ler o arquivo " << nomeArquivo << std::endl;
    }

    return 0;
}
