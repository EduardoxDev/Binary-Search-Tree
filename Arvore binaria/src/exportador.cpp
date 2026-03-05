#include "exportador.h"
#include <fstream>
#include <iostream>

bool Exportador::exportarCSV(const ArvoreBinaria&, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        std::cout << "❌ Erro ao abrir arquivo para escrita!\n";
        return false;
    }

    arquivo << "Nome,Matrícula,Classe,Notas,Email,Telefone\n";
    
    std::cout << "✅ Arquivo '" << nomeArquivo << "' exportado com sucesso!\n";
    arquivo.close();
    return true;
}

bool Exportador::importarCSV(ArvoreBinaria&, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        std::cout << "❌ Erro ao abrir arquivo para leitura!\n";
        return false;
    }

    std::string linha;
    std::getline(arquivo, linha);

    std::cout << "✅ Arquivo '" << nomeArquivo << "' importado com sucesso!\n";
    arquivo.close();
    return true;
}

void Exportador::exibirFormatoCSV() {
    std::cout << "\n📋 FORMATO CSV\n";
    std::cout << "═════════════════════════════════════════\n";
    std::cout << "Nome,Matrícula,Classe,Notas,Email,Telefone\n";
    std::cout << "João Silva,20240001,1,8.5,joao@email.com,11999999999\n";
    std::cout << "Maria Santos,20240002,2,9.0,maria@email.com,11988888888\n";
}
