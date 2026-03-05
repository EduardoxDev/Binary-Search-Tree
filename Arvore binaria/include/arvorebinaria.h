#ifndef BINARY_TREE_ARVOREBINARIA_H
#define BINARY_TREE_ARVOREBINARIA_H

#include "aluno.h"

struct Node {
    Aluno aluno;
    Node* esquerda;
    Node* direita;

    Node();
    explicit Node(const Aluno& aluno);
};

class ArvoreBinaria {
private:
    Node* raiz_;

    void exibirEmOrdemAux(Node* node) const;
    void exibirPreOrdemAux(Node* node) const;
    void buscarPorNomeAux(Node* node, const std::string& nome, bool& encontrado) const;
    void deletarAux(Node* node);

public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void inserir(const Aluno& aluno);
    void exibirEmOrdem() const;
    void exibirPreOrdem() const;
    void buscar(const Aluno& aluno) const;
    void buscarPorNome(const std::string& nome) const;
    void limpar();
    bool vazio() const;

    ArvoreBinaria(const ArvoreBinaria&) = delete;
    ArvoreBinaria& operator=(const ArvoreBinaria&) = delete;
};

#endif
