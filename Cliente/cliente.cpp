#include "cliente.hpp"

Cliente::Cliente(int cpf, string nome) {
    this -> cpf = cpf;
    this -> nome = nome;
}

Cliente::~Cliente() {
};

void Cliente::alugar(Filme* filme) {
    this -> filmesAlugados.push_back(filme);
}

void Cliente::devolver(Filme* filme) {
    auto it = find (this->filmesAlugados.begin(), this->filmesAlugados.end(), filme);
    if (it != this->filmesAlugados.end()) {
        this->filmesAlugados.erase(it);
    }
}