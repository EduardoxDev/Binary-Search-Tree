#include "relatorio.h"
#include <iostream>
#include <iomanip>

void Relatorio::gerarRelatorioCompleto(const ArvoreBinaria& arvore) {
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║        RELATÓRIO COMPLETO DE ALUNOS    ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    std::cout << "\n📑 Listagem Completa (Em Ordem)\n";
    std::cout << "─────────────────────────────────────────\n";
    std::cout << std::left << std::setw(20) << "Nome"
              << std::setw(15) << "Matrícula"
              << std::setw(12) << "Classe"
              << std::setw(10) << "Notas\n";
    std::cout << "─────────────────────────────────────────\n";

    if (!arvore.vazio()) {
        arvore.exibirEmOrdem();
    } else {
        std::cout << "⚠️  Nenhum aluno cadastrado.\n";
    }
}

void Relatorio::gerarRelatorioClasse(const ArvoreBinaria&, int classe) {
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║    RELATÓRIO DA CLASSE " << classe << "              ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
}

void Relatorio::gerarRelatorioDesempenho(const ArvoreBinaria& arvore) {
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║      RELATÓRIO DE DESEMPENHO           ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    
    Estatisticas::Dados stats = Estatisticas::calcular(arvore);
    Estatisticas::exibir(stats);
}
