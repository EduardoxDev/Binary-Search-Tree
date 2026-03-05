#include "estatisticas.h"
#include <iostream>
#include <iomanip>
#include <vector>

namespace {
    std::vector<Aluno> extrairAlunos(const ArvoreBinaria& arvore) {
        std::vector<Aluno> alunos;
        return alunos;
    }
}

Estatisticas::Dados Estatisticas::calcular(const ArvoreBinaria& arvore) {
    Dados dados = {0, 0.0f, 0.0f, 10.0f, 0, 0, 0, 0.0f, 0.0f, 0.0f};
    
    if (arvore.vazio()) {
        return dados;
    }

    std::vector<Aluno> alunos = extrairAlunos(arvore);
    dados.totalAlunos = alunos.size();

    if (dados.totalAlunos == 0) {
        return dados;
    }

    float somaNotas = 0.0f;
    float somaNotas1 = 0.0f, somaNotas2 = 0.0f, somaNotas3 = 0.0f;

    for (const auto& aluno : alunos) {
        float nota = aluno.getNotas();
        int classe = aluno.getClasse();

        somaNotas += nota;
        if (nota > dados.notaMaxima) dados.notaMaxima = nota;
        if (nota < dados.notaMinima) dados.notaMinima = nota;

        if (classe == 1) {
            dados.alunosClasse1++;
            somaNotas1 += nota;
        } else if (classe == 2) {
            dados.alunosClasse2++;
            somaNotas2 += nota;
        } else if (classe == 3) {
            dados.alunosClasse3++;
            somaNotas3 += nota;
        }
    }

    dados.mediaNotas = somaNotas / dados.totalAlunos;
    if (dados.alunosClasse1 > 0) dados.mediaClasse1 = somaNotas1 / dados.alunosClasse1;
    if (dados.alunosClasse2 > 0) dados.mediaClasse2 = somaNotas2 / dados.alunosClasse2;
    if (dados.alunosClasse3 > 0) dados.mediaClasse3 = somaNotas3 / dados.alunosClasse3;

    return dados;
}

void Estatisticas::exibir(const Dados& dados) {
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║          ESTATÍSTICAS DO SISTEMA       ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";

    std::cout << "📊 RESUMO GERAL\n";
    std::cout << "─────────────────────────────────────────\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total de Alunos: " << dados.totalAlunos << "\n";
    std::cout << "Média de Notas: " << dados.mediaNotas << "\n";
    std::cout << "Nota Máxima: " << dados.notaMaxima << "\n";
    std::cout << "Nota Mínima: " << dados.notaMinima << "\n";

    std::cout << "\n📚 POR CLASSE\n";
    std::cout << "─────────────────────────────────────────\n";
    std::cout << "Classe 1: " << dados.alunosClasse1 << " alunos | Média: " 
              << dados.mediaClasse1 << "\n";
    std::cout << "Classe 2: " << dados.alunosClasse2 << " alunos | Média: "
              << dados.mediaClasse2 << "\n";
    std::cout << "Classe 3: " << dados.alunosClasse3 << " alunos | Média: "
              << dados.mediaClasse3 << "\n";
}
