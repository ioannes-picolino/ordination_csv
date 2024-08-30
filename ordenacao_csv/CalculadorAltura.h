#ifndef CALCULADORALTURA_H
#define CALCULADORALTURA_H

#include "CalculadorEstatistico.h"

class CalculadorAltura : public CalculadorEstatistico {
public:
    float calcularMedia(const std::vector<Pessoa>& pessoas) override;
    float calcularMediana(const std::vector<Pessoa>& pessoas) override;
    float calcularDesvioPadrao(const std::vector<Pessoa>& pessoas) override;
};


#endif