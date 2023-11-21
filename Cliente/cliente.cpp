#include "cliente.hpp"

Cliente::Cliente(int cpf, string nome) {
    this -> cpf = cpf;
    this -> nome = nome;
    this -> pontos = 0;
}

Cliente::~Cliente() {
};

void Cliente::lerCliente(){
    cout << this -> cpf << " ";
    cout << this -> nome << endl;
}

void Cliente::alugar(Filme* filme) {
    this -> filmesAlugados.push_back(filme);
    this -> pontos++;
}

void Cliente::devolver(Filme* filme) {
    auto it = find (this->filmesAlugados.begin(), this->filmesAlugados.end(), filme);
    if (it != this->filmesAlugados.end()) {
        this->filmesAlugados.erase(it);
    }
}