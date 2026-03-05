#include "arvorebinaria.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void exibirCabecalho() {
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "   ARVORE BINARIA - SISTEMA DE ALUNOS  \n";
    std::cout << "========================================\n";
}

void exibirMenu() {
    std::cout << "\n-------------- MENU ---------------\n";
    std::cout << " 1 - Inserir novo aluno\n";
    std::cout << " 2 - Exibir em ordem (por classe)\n";
    std::cout << " 3 - Exibir pre-ordem\n";
    std::cout << " 4 - Buscar aluno por nome\n";
    std::cout << " 5 - Listar todos os alunos\n";
    std::cout << " 6 - Limpar arvore\n";
    std::cout << " 7 - Ajuda\n";
    std::cout << " 0 - Sair\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Escolha [0-7]: ";
}

void exibirAjuda() {
    limparTela();
    exibirCabecalho();
    std::cout << "\n>>> GUIA DE USO\n";
    std::cout << "===================================\n";
    std::cout << "\n[INSERIR ALUNO]\n";
    std::cout << "  - Digite o nome completo\n";
    std::cout << "  - Classe: 1, 2 ou 3\n";
    std::cout << "  - Notas: 0 a 10 (aceita decimais)\n";
    std::cout << "\n[BUSCAR ALUNO]\n";
    std::cout << "  - Digite o nome para buscar\n";
    std::cout << "  - Busca por correspondencia parcial\n";
    std::cout << "\n[EXIBIR]\n";
    std::cout << "  - Em Ordem: ordenado por classe\n";
    std::cout << "  - Pre-Ordem: estrutura da arvore\n";
    std::cout << "\n[IMPORTANTE]\n";
    std::cout << "  - Dados ficam apenas na memoria\n";
    std::cout << "  - Use 'Limpar' para deletar tudo\n";
    std::cout << "\nPressione ENTER para voltar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void pausa() {
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validarNome(const std::string& nome) {
    if (nome.empty() || nome.length() > 50) return false;
    for (char c : nome) {
        if (!std::isalpha(c) && c != ' ') return false;
    }
    return true;
}

bool lerInteiro(int& valor, int min, int max) {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    if (!(ss >> valor) || !ss.eof() || valor < min || valor > max) {
        return false;
    }
    return true;
}

bool lerFloat(float& valor, float min, float max) {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    if (!(ss >> valor) || !ss.eof() || valor < min || valor > max) {
        return false;
    }
    return true;
}

int main() {
    ArvoreBinaria arvore;
    int opcao;
    std::string nome;
    int classe;
    float notas;

    while (true) {
        limparTela();
        exibirCabecalho();
        exibirMenu();
        
        if (!lerInteiro(opcao, 0, 7)) {
            std::cout << "\n[ERRO] Entrada invalida! Digite um numero entre 0 e 7.\n";
            pausa();
            continue;
        }

        switch (opcao) {
            case 1: {
                limparTela();
                exibirCabecalho();
                std::cout << "\n>>> INSERIR NOVO ALUNO\n";
                std::cout << "-----------------------------------\n";
                
                std::cout << "Nome: ";
                std::getline(std::cin, nome);
                
                if (!validarNome(nome)) {
                    std::cout << "[ERRO] Nome invalido! Use apenas letras (max 50 caracteres)\n";
                    pausa();
                    break;
                }

                std::cout << "Classe (1-3): ";
                if (!lerInteiro(classe, 1, 3)) {
                    std::cout << "[ERRO] Classe deve ser 1, 2 ou 3!\n";
                    pausa();
                    break;
                }

                std::cout << "Notas (0-10): ";
                if (!lerFloat(notas, 0.0f, 10.0f)) {
                    std::cout << "[ERRO] Notas devem estar entre 0 e 10!\n";
                    pausa();
                    break;
                }

                Aluno novo(nome, classe, notas);
                arvore.inserir(novo);
                std::cout << "\n[OK] Aluno '" << nome << "' inserido com sucesso!\n";
                pausa();
                break;
            }

            case 2: {
                limparTela();
                exibirCabecalho();
                std::cout << "\n>>> ALUNOS ORDENADOS POR CLASSE\n";
                std::cout << "======================================\n";
                
                if (!arvore.vazio()) {
                    std::cout << std::left << std::setw(20) << "Nome" 
                              << std::setw(10) << "Classe" 
                              << std::setw(10) << "Notas\n";
                    std::cout << "--------------------------------------\n";
                    arvore.exibirEmOrdem();
                } else {
                    std::cout << "[AVISO] Arvore vazia! Insira alunos primeiro.\n";
                }
                pausa();
                break;
            }

            case 3: {
                limparTela();
                exibirCabecalho();
                std::cout << "\n>>> ESTRUTURA DA ARVORE (Pre-Ordem)\n";
                std::cout << "======================================\n";
                
                if (!arvore.vazio()) {
                    std::cout << std::left << std::setw(20) << "Nome" 
                              << std::setw(10) << "Classe" 
                              << std::setw(10) << "Notas\n";
                    std::cout << "--------------------------------------\n";
                    arvore.exibirPreOrdem();
                } else {
                    std::cout << "[AVISO] Arvore vazia! Insira alunos primeiro.\n";
                }
                pausa();
                break;
            }

            case 4: {
                limparTela();
                exibirCabecalho();
                std::cout << "\n>>> BUSCAR ALUNO POR NOME\n";
                std::cout << "======================================\n";
                std::cout << "Nome (ou parte): ";
                std::getline(std::cin, nome);

                if (nome.empty()) {
                    std::cout << "[ERRO] Nome nao pode estar vazio!\n";
                    pausa();
                    break;
                }

                std::cout << "\n>>> Resultado da busca:\n";
                std::cout << "--------------------------------------\n";
                arvore.buscarPorNome(nome);
                pausa();
                break;
            }

            case 5: {
                limparTela();
                exibirCabecalho();
                std::cout << "\n>>> TODOS OS ALUNOS\n";
                std::cout << "======================================\n";
                
                if (!arvore.vazio()) {
                    std::cout << std::left << std::setw(20) << "Nome" 
                              << std::setw(10) << "Classe" 
                              << std::setw(10) << "Notas\n";
                    std::cout << "--------------------------------------\n";
                    arvore.exibirEmOrdem();
                } else {
                    std::cout << "[AVISO] Nenhum aluno cadastrado ainda.\n";
                }
                pausa();
                break;
            }

            case 6: {
                limparTela();
                exibirCabecalho();
                std::cout << "\n>>> LIMPAR ARVORE\n";
                std::cout << "======================================\n";
                std::cout << "[ATENCAO] Deletar TODOS os alunos? (s/n): ";
                
                std::string confirmacao;
                std::getline(std::cin, confirmacao);
                
                if (confirmacao == "s" || confirmacao == "S") {
                    arvore.limpar();
                    std::cout << "[OK] Arvore limpa com sucesso!\n";
                } else {
                    std::cout << "[CANCELADO] Operacao cancelada.\n";
                }
                pausa();
                break;
            }

            case 7: {
                exibirAjuda();
                break;
            }

            case 0: {
                limparTela();
                std::cout << "\n========================================\n";
                std::cout << "  Obrigado por usar nosso sistema!\n";
                std::cout << "  Ate a proxima!\n";
                std::cout << "========================================\n\n";
                return 0;
            }

            default: {
                std::cout << "\n[ERRO] Opcao invalida! Digite um numero entre 0 e 7.\n";
                pausa();
            }
        }
    }

    return 0;
}
