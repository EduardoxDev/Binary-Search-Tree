#ifndef BINARY_TREE_ALUNO_H
#define BINARY_TREE_ALUNO_H

#include <iostream>
#include <string>
#include <ctime>

class Aluno {
private:
    std::string nome_;
    std::string matricula_;
    int classe_;
    float notas_;
    std::string email_;
    std::string telefone_;
    time_t dataCadastro_;

public:
    Aluno();
    Aluno(const std::string& nome, int classe, float notas);
    Aluno(const std::string& nome, const std::string& matricula, int classe, float notas);
    Aluno(const std::string& nome, const std::string& matricula, int classe, float notas,
          const std::string& email, const std::string& telefone);

    const std::string& getNome() const;
    const std::string& getMatricula() const;
    int getClasse() const;
    float getNotas() const;
    const std::string& getEmail() const;
    const std::string& getTelefone() const;
    time_t getDataCadastro() const;

    void setNotas(float notas);
    void setEmail(const std::string& email);
    void setTelefone(const std::string& telefone);

    void exibir() const;
    std::string obterDadosCSV() const;
};

#endif
