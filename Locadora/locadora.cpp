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

void Locadora::cadastrarFilme(string tipo, int quantidade, int id, const string& titulo, const string& categoria) {
    
    for (int i=0; i<filmes.size(); i++) {
        if (id == filmes[i]->id) {
            cout << "ERRO: codigo repetido\n";
        }
        if (tipo == filmes[i]->tipo) {
        cout << "ERRO: dados incorretos\n";
    }

    }
    Filme* novoFilme = new Filme(tipo, quantidade, id, titulo, categoria);
    //precisa adicionar categorias para os DVDs

    filmes.push_back(novoFilme);
    cout << "Filme "<< novoFilme->id <<" cadastrado com sucesso";
}


void Locadora::removerFilme(int codigo) {
     auto it = std::find_if(filmes.begin(), filmes.end(),
        [codigo](Filme* filme) { return filme->id == codigo; });

    if (it != filmes.end()) {
        delete *it; 
        filmes.erase(it);
        std::cout << "Filme " << codigo << " removido com sucesso\n";
    } else {
        std::cout << "ERRO: código inexistente\n";
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