#ifndef LEITOR_CSV_H
#define LEITOR_CSV_H

#include <vector>
#include <string>
#include "Pessoa.h"

class LeitorCSV {
public:
    static bool lerArquivo(const std::string& nomeArquivo, std::vector<Pessoa>& pessoas);
};

#endif // LEITOR_CSV_H
