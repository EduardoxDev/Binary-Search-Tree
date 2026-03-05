#ifndef BINARY_TREE_ESTATISTICAS_H
#define BINARY_TREE_ESTATISTICAS_H

#include "arvorebinaria.h"
#include <string>

class Estatisticas {
public:
    struct Dados {
        int totalAlunos;
        float mediaNotas;
        float notaMaxima;
        float notaMinima;
        int alunosClasse1;
        int alunosClasse2;
        int alunosClasse3;
        float mediaClasse1;
        float mediaClasse2;
        float mediaClasse3;
    };

    static Dados calcular(const ArvoreBinaria& arvore);
    static void exibir(const Dados& dados);
};

#endif
