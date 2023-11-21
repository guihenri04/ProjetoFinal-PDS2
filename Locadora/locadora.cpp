#include "locadora.hpp"

Locadora::Locadora() {
    vector<Filme*> filmes;
    vector<Cliente*> clientes;
    this -> filmes = filmes;
    this -> clientes = clientes;
}

Locadora::~Locadora() {
    for (Filme* filme : filmes) {
        delete filme;
    }
    for (Cliente* cliente : clientes) {
        delete cliente;
    }
}

void Locadora::cadastrarFilme(string tipo, int unidades, int id, const string& titulo, const string& categoria) {
    
    for (int i=0; i<filmes.size(); i++) {
        if (id == filmes[i]->id) {
            cout << "ERRO: codigo repetido\n";
            return;
        }
        if (tipo == filmes[i]->tipo) {
            cout << "ERRO: dados incorretos\n";
            return;
        }
    }

    Filme* novoFilme;
    if (tipo=="FITA") {
        novoFilme = new Fita(id, titulo, unidades);
    } else if (categoria=="Estoque") {
        novoFilme = new dvdEstoque(id, titulo, unidades);
    } else if (categoria=="Lancamento") {
        novoFilme = new dvdLancamento(id, titulo, unidades);
    } else if (categoria=="Promocao") {
        novoFilme = new dvdPromocao(id, titulo, unidades);
    }
    
    if (novoFilme) {
        filmes.push_back(novoFilme);
        cout << "Filme "<< novoFilme->id <<" cadastrado com sucesso\n";
    }
}

void Locadora::removerFilme(int codigo) {
    auto it = std::find_if(filmes.begin(), filmes.end(),
        [codigo](Filme* filme) { return filme->id == codigo; });

    if (it != filmes.end()) {
        delete *it; 
        filmes.erase(it);
        cout << "Filme " << codigo << " removido com sucesso\n";
    } else {
        cout << "ERRO: código inexistente\n";
    }
}

void Locadora::listarFilmes() {
    for (Filme* filme : filmes) {
        filme->lerFilme();
    }
}

void Locadora::cadastrarCliente(int cpf, string nome) {
    for (int i=0; i<clientes.size(); i++) {
        if (cpf == clientes[i]->cpf) {
            cout << "ERRO: CPF repetido\n";
            return;
        }
        if (false) {
            cout << "ERRO: dados incorretos\n";
            return;
        }
    }
    Cliente* cliente = new Cliente(cpf, nome);
    this -> clientes.push_back(cliente);
}

void Locadora::removerCliente(Cliente* cliente) {
    auto it = find (this->clientes.begin(), this->clientes.end(), cliente);
    if (it != this->clientes.end()) {
        this->clientes.erase(it);
    }
}

void Locadora::aluguel(Filme* filme, Cliente* cliente) {
    filme->serAlugado();
    cliente->alugar(filme);
}


void Locadora::devolucao(Filme* filme, Cliente* cliente) {

}