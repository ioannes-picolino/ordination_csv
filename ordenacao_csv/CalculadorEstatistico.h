#ifndef CALCULADORESTATISTICO_H
#define CALCULADORESTATISTICO_H

#include <vector>
#include "Pessoa.h"

class CalculadorEstatistico {
public:
    virtual float calcularMedia(const std::vector<Pessoa>& pessoas) = 0;
    virtual float calcularMediana(const std::vector<Pessoa>& pessoas) = 0;
    virtual float calcularDesvioPadrao(const std::vector<Pessoa>& pessoas) = 0;
    virtual ~CalculadorEstatistico() {}
};

#endif // CALCULADORESTATISTICO_H
