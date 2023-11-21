#include "cliente.hpp"

Cliente::Cliente(int cpf, string nome) {
    this -> cpf = cpf;
    this -> nome = nome;
    this -> pontos = 0;
}

Cliente::~Cliente() {
    for (Filme* filme : filmesAlugados) {
        delete filme;
    }
    for (Filme* filme : historico) {
        delete filme;
    }
};

void Cliente::lerCliente(){
    cout << this -> cpf << " ";
    cout << this -> nome << endl;
}

void Cliente::alugar(Filme* filme) {
    this -> filmesAlugados.push_back(filme);
    this -> pontos++;
    this -> historico.push_back(filme);
}

void Cliente::devolver() {
    for (const auto& filme : this->filmesAlugados) {
        delete filme;
    }
}