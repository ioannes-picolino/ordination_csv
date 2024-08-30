#include "Pessoa.h"
#include <string>
#include <sstream>

using namespace std;

Pessoa::Pessoa(string nome, string data, float peso, float altura) :
nome(nome), data(data), peso(peso), altura(altura){}

string Pessoa::getNome() const{
    return nome;
}

string Pessoa::getData() const{
    // Divide a string de data em dia, mês e ano
    istringstream ss(data);
    string dia, mes, ano;
    getline(ss, dia, '/');
    getline(ss, mes, '/');
    getline(ss, ano);

    // Formata a data no formato desejado "AAAA-MM-DD"
    string dataFormatada = ano + "-" + mes + "-" + dia;

    return dataFormatada;
}

float Pessoa::getPeso() const{
    return peso;
}

float Pessoa::getAltura() const{
    return altura;
}