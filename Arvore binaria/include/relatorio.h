#ifndef BINARY_TREE_RELATORIO_H
#define BINARY_TREE_RELATORIO_H

#include "arvorebinaria.h"
#include "estatisticas.h"
#include <string>

class Relatorio {
public:
    static void gerarRelatorioCompleto(const ArvoreBinaria& arvore);
    static void gerarRelatorioClasse(const ArvoreBinaria& arvore, int classe);
    static void gerarRelatorioDesempenho(const ArvoreBinaria& arvore);
};

#endif
