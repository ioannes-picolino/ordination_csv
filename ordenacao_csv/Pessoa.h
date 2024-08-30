#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa
{
private:
    string nome;
    string data;
    float peso;
    float altura;
public:
    Pessoa(string nome, string data, float peso, float altura);
    
    string getNome() const;
    string getData() const;
    float getPeso() const;
    float getAltura() const;
};

#endif
