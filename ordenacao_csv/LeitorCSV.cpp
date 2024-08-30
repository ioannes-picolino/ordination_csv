#include "LeitorCSV.h"
#include <fstream>
#include <sstream>

bool LeitorCSV::lerArquivo(const std::string& nomeArquivo, std::vector<Pessoa>& pessoas) {
    std::ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        return false;
    }

    std::string linha;

    // Ignora a primeira linha (cabeçalho)
    getline(arquivo, linha);

    // Lê cada linha do arquivo
    while (getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string item;

        // Separa os valores da linha por vírgula e armazena em um vetor
        std::vector<std::string> valores;
        while (getline(ss, item, ',')) {
            valores.push_back(item);
        }

        // Verifica se há pelo menos quatro valores na linha (atributos esperados)
        if (valores.size() >= 4) {
            // Converte os valores para os tipos corretos
            std::string nome = valores[0];
            std::string data = valores[1];
            float peso = std::stof(valores[2]);
            float altura = std::stof(valores[3]);

            // Instancia o objeto Pessoa e o adiciona ao vetor
            pessoas.push_back(Pessoa(nome, data, peso, altura));
        }
    }

    arquivo.close();
    return true;
}
