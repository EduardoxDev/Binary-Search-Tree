#ifndef BINARY_TREE_EXPORTADOR_H
#define BINARY_TREE_EXPORTADOR_H

#include "arvorebinaria.h"
#include <string>

class Exportador {
public:
    static bool exportarCSV(const ArvoreBinaria& arvore, const std::string& nomeArquivo);
    static bool importarCSV(ArvoreBinaria& arvore, const std::string& nomeArquivo);
    static void exibirFormatoCSV();
};

#endif
