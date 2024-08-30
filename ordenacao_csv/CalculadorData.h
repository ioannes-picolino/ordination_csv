#ifndef CALCULADORDATA_H
#define CALCULADORDATA_H

#include "CalculadorEstatistico.h"


class CalculadorData : public CalculadorEstatistico {
public:
    float convertDateToYear(const std::string& date);
    float calcularMedia(const std::vector<Pessoa>& pessoas) override;
    float calcularMediana(const std::vector<Pessoa>& pessoas) override;
    float calcularDesvioPadrao(const std::vector<Pessoa>& pessoas) override;
};


#endif
