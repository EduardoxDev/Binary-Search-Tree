#include "aluno.h"
#include <iomanip>

Aluno::Aluno() 
    : nome_(""), matricula_(""), classe_(0), notas_(0.0f), 
      email_(""), telefone_(""), dataCadastro_(time(nullptr)) {}

Aluno::Aluno(const std::string& nome, int classe, float notas)
    : nome_(nome), matricula_(std::string("MAT") + std::to_string(time(nullptr) % 1000000)),
      classe_(classe), notas_(notas), email_(""), telefone_(""),
      dataCadastro_(time(nullptr)) {}

Aluno::Aluno(const std::string& nome, const std::string& matricula, int classe, float notas)
    : nome_(nome), matricula_(matricula), classe_(classe), notas_(notas), 
      email_(""), telefone_(""), dataCadastro_(time(nullptr)) {}

Aluno::Aluno(const std::string& nome, const std::string& matricula, int classe, float notas,
             const std::string& email, const std::string& telefone)
    : nome_(nome), matricula_(matricula), classe_(classe), notas_(notas),
      email_(email), telefone_(telefone), dataCadastro_(time(nullptr)) {}

const std::string& Aluno::getNome() const {
    return nome_;
}

const std::string& Aluno::getMatricula() const {
    return matricula_;
}

int Aluno::getClasse() const {
    return classe_;
}

float Aluno::getNotas() const {
    return notas_;
}

const std::string& Aluno::getEmail() const {
    return email_;
}

const std::string& Aluno::getTelefone() const {
    return telefone_;
}

time_t Aluno::getDataCadastro() const {
    return dataCadastro_;
}

void Aluno::setNotas(float notas) {
    if (notas >= 0.0f && notas <= 10.0f) {
        notas_ = notas;
    }
}

void Aluno::setEmail(const std::string& email) {
    email_ = email;
}

void Aluno::setTelefone(const std::string& telefone) {
    telefone_ = telefone;
}

void Aluno::exibir() const {
    std::cout << std::left << std::setw(20) << nome_
              << std::setw(10) << classe_
              << std::fixed << std::setprecision(2) << notas_ << std::endl;
}

std::string Aluno::obterDadosCSV() const {
    return nome_ + "," + matricula_ + "," + std::to_string(classe_) + "," +
           std::to_string(notas_) + "," + email_ + "," + telefone_;
}

