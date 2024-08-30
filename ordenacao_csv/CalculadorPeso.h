#ifndef CALCULADORPESO_H
#define CALCULADORPESO_H

#include "CalculadorEstatistico.h"

class CalculadorPeso : public CalculadorEstatistico {
public:
    float calcularMedia(const std::vector<Pessoa>& pessoas) override;
    float calcularMediana(const std::vector<Pessoa>& pessoas) override;
    float calcularDesvioPadrao(const std::vector<Pessoa>& pessoas) override;
};


#endif