#include "locadora.hpp"

Locadora::Locadora() {
    vector<Filme> filmes;
    vector<Cliente> clientes;
}

Locadora::~Locadora() {
    for (Filme* filme : filmes) {
        delete filme;
    }
}

void Locadora::cadastrarFilme(Filme* filme) {
    this -> filmes.push_back(filme);
}

void Locadora::removerFilme(Filme* filme) {
    auto it = find (this->filmes.begin(), this->filmes.end(), filme);
    if (it != this->filmes.end()) {
        this->filmes.erase(it);
    }
}

void Locadora::listarFilmes() {
    for (Filme* filme : filmes) {
        filme->lerFilme();
    }
}

void Locadora::cadastrarCliente(Cliente* cliente) {
    this -> clientes.push_back(cliente);
}

void Locadora::removerCliente(Cliente* cliente) {
    auto it = find (this->clientes.begin(), this->clientes.end(), cliente);
    if (it != this->clientes.end()) {
        this->clientes.erase(it);
    }
}

void Locadora::aluguel(Filme* filme, Cliente* cliente) {

}


void Locadora::devolucao(Filme* filme, Cliente* cliente) {
    
}