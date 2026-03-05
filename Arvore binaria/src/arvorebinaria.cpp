#include "arvorebinaria.h"
#include <iostream>

Node::Node() : esquerda(nullptr), direita(nullptr) {}

Node::Node(const Aluno& aluno)
    : aluno(aluno), esquerda(nullptr), direita(nullptr) {}

ArvoreBinaria::ArvoreBinaria() : raiz_(nullptr) {}

ArvoreBinaria::~ArvoreBinaria() {
    limpar();
}

void ArvoreBinaria::inserir(const Aluno& aluno) {
    if (raiz_ == nullptr) {
        raiz_ = new Node(aluno);
        return;
    }

    Node* atual = raiz_;
    while (true) {
        if (aluno.getClasse() < atual->aluno.getClasse()) {
            if (atual->esquerda == nullptr) {
                atual->esquerda = new Node(aluno);
                return;
            }
            atual = atual->esquerda;
        } else {
            if (atual->direita == nullptr) {
                atual->direita = new Node(aluno);
                return;
            }
            atual = atual->direita;
        }
    }
}

void ArvoreBinaria::exibirEmOrdem() const {
    exibirEmOrdemAux(raiz_);
    std::cout << std::endl;
}

void ArvoreBinaria::exibirEmOrdemAux(Node* node) const {
    if (node != nullptr) {
        exibirEmOrdemAux(node->esquerda);
        node->aluno.exibir();
        exibirEmOrdemAux(node->direita);
    }
}

void ArvoreBinaria::exibirPreOrdem() const {
    exibirPreOrdemAux(raiz_);
    std::cout << std::endl;
}

void ArvoreBinaria::exibirPreOrdemAux(Node* node) const {
    if (node != nullptr) {
        node->aluno.exibir();
        exibirPreOrdemAux(node->esquerda);
        exibirPreOrdemAux(node->direita);
    }
}

void ArvoreBinaria::buscar(const Aluno& aluno) const {
    Node* atual = raiz_;
    while (atual != nullptr) {
        if (atual->aluno.getClasse() == aluno.getClasse()) {
            std::cout << "Aluno encontrado: " << std::endl;
            atual->aluno.exibir();
            return;
        } else if (aluno.getClasse() < atual->aluno.getClasse()) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }
    std::cout << "Aluno nao encontrado." << std::endl;
}

void ArvoreBinaria::buscarPorNome(const std::string& nome) const {
    bool encontrado = false;
    buscarPorNomeAux(raiz_, nome, encontrado);
    if (!encontrado) {
        std::cout << "[AVISO] Nenhum aluno encontrado com esse nome.\n";
    }
}

void ArvoreBinaria::buscarPorNomeAux(Node* node, const std::string& nome, bool& encontrado) const {
    if (node != nullptr) {
        buscarPorNomeAux(node->esquerda, nome, encontrado);
        
        std::string nomeAluno = node->aluno.getNome();
        std::string nomeBusca = nome;
        
        // Converter para minusculas para comparacao case-insensitive
        for (auto& c : nomeAluno) c = std::tolower(c);
        for (auto& c : nomeBusca) c = std::tolower(c);
        
        if (nomeAluno.find(nomeBusca) != std::string::npos) {
            node->aluno.exibir();
            encontrado = true;
        }
        
        buscarPorNomeAux(node->direita, nome, encontrado);
    }
}

void ArvoreBinaria::limpar() {
    deletarAux(raiz_);
    raiz_ = nullptr;
}

void ArvoreBinaria::deletarAux(Node* node) {
    if (node != nullptr) {
        deletarAux(node->esquerda);
        deletarAux(node->direita);
        delete node;
    }
}

bool ArvoreBinaria::vazio() const {
    return raiz_ == nullptr;
}
