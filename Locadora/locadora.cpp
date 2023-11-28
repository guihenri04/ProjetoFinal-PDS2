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

void Locadora::cadastrarFilme(char tipo, int unidades, int id, const string& titulo, const char& categoria) {
    int n=filmes.size();
    for (int i=0; i<n; i++) { // codigo repetido
        if (id == filmes[i]->id) {
            cout << "ERRO: codigo repetido\n";
            return;
        }
    }
    if (tipo != 'F' && tipo !='D') { // tipo invalido
        cout << "ERRO: dados incorretos\n";
        return;
    }
    if (tipo == 'D') {
        if(categoria!= 'E' && categoria!= 'L' && categoria!= 'P') { // categoria invalida
            cout << "ERRO: dados incorretos\n";
            return;
        }
    } 
    if (unidades<0 || id<0) { // unidades ou id negativos
        cout << "ERRO: dados incorretos\n";
        return;
    }

    Filme* novoFilme;
    if (tipo=='F') {
        novoFilme = new Fita(id, titulo, unidades);
    } else if (categoria == 'E') {
        novoFilme = new dvdEstoque(id, titulo, unidades);
    } else if (categoria == 'L') {
        novoFilme = new dvdLancamento(id, titulo, unidades);
    } else if (categoria == 'P') {
        novoFilme = new dvdPromocao(id, titulo, unidades);
    } 

    if (novoFilme) {
        filmes.push_back(novoFilme);
        cout << "Filme "<< novoFilme->id <<" cadastrado com sucesso\n";
    }
}

void Locadora::removerFilme(int id) {
    auto it = std::find_if(filmes.begin(), filmes.end(),
        [id](Filme* filme) { return filme->id == id; });

    if (it != filmes.end()) {
        delete *it; 
        filmes.erase(it);
        cout << "Filme " << id << " removido com sucesso.\n";
    } else {
        cout << "ERRO: código inexistente.\n"; // Id invalido
    }
}

void Locadora::listarFilmes(char opcao) {
    if (opcao != 'C' && opcao != 'T') {
        cout << "ERRO: opção de ordenação inválida.\n";
        return;
    }
    if(this->filmes.size()==0) {
        cout << "Ainda não há filmes para listar." << endl;
        return;
    }
    vector<Filme*> filmesOrdenados = filmes;

    auto compara = [opcao](const Filme* a, const Filme* b) {
        if (opcao == 'C') {
            return a->id < b->id;
        } else {
            return a->titulo < b->titulo;
        }
    };

   sort(filmesOrdenados.begin(), filmesOrdenados.end(), compara);

    for (const auto& filme : filmesOrdenados) {
        filme->lerFilme();
    }
}

void Locadora::cadastrarCliente(long cpf, string nome) {
    int n= clientes.size();
    for (int i=0; i<n; i++) {
        if (cpf == clientes[i]->cpf) { // CPF repetido
            cout << "ERRO: CPF repetido\n";
            return;
        }
        if (cpf<10000000000) { // CPF invalido
            cout << "ERRO: dados incorretos\n";
            return;
        }
    }
    Cliente* cliente = new Cliente(cpf, nome);
    this -> clientes.push_back(cliente);
    cout << "Cliente "<< cliente->nome <<" cadastrado com sucesso\n";
}

void Locadora::removerCliente(long cpf) {
    auto it = find_if(this->clientes.begin(), this->clientes.end(),
                           [cpf](const Cliente* cliente) { return cliente->cpf == cpf; });

    if (it == clientes.end()) { // CPF não encontrado
        cout << "ERRO: dados incorretos.\n";
        return;
    } else {
        delete *it;
        cout << "Cliente removido com sucesso\n";
        this->clientes.erase(it);
    }
}

 void Locadora::listarClientes(char opcao){

    if (opcao != 'C' && opcao != 'N') {
        cout << "ERRO: opção de ordenação inválida.\n";
        return;
    }
    if (this->clientes.size()==0) {
        cout << "Ainda não há clientes para listar." << endl;
        return;
    }

    vector<Cliente*> clientesOrdenados = clientes;

    auto compara = [opcao](const Cliente* a, const Cliente* b) {
        if (opcao == 'C') {
            return a->cpf < b->cpf;
        } else {
            return a->nome < b->nome;
        }
    };

   sort(clientesOrdenados.begin(), clientesOrdenados.end(), compara);

    for (const auto& cliente : clientesOrdenados) {
        cliente->lerCliente();
    }
}

void Locadora::aluguel(long cpf, int id) {
    auto itCliente = find_if(this->clientes.begin(), this->clientes.end(),
        [cpf](const Cliente* cliente) { return cliente->cpf == cpf; });
    Cliente* cliente;
    if (itCliente != this->clientes.end()) {
        cliente = *itCliente;
    } else { // cpf inexistente
        cout << "ERRO: CPF inexistente\n";
        return;
    }

    auto itFilme = std::find_if(filmes.begin(), filmes.end(),
        [id](Filme* filme) { return filme->id == id; });
    Filme* filme;
    if (itFilme != this->filmes.end()) {
        filme = *itFilme;
    } else { // filme inexistente
        cout << "ERRO: Filme " << id<< " inexistente\n";
        return;
    }

    cliente->alugar(filme);
    filme->serAlugado();
    cout << "Filme "<< filme->id <<" alugado por " << cliente->nome << " com sucesso\n";
}

void Locadora::devolucao(long cpf) {
    auto itCliente = find_if(this->clientes.begin(), this->clientes.end(),
        [cpf](const Cliente* cliente) { return cliente->cpf == cpf; });
    Cliente* cliente;
    if (itCliente != this->clientes.end()) {
        cliente = *itCliente;
    } else {
        cout << "ERRO: CPF inexistente\n";
        return;
    }

    cout << "Cliente " << cpf << " " << cliente -> nome << " devolveu os filmes:" << endl;
    int total = 0;
    for (const auto& filme : cliente -> filmesAlugados) {
        cout << filme -> id << " " ;
        cout << filme -> calcularValor(1) << endl;
        total += filme -> calcularValor(1);
    }

    if(cliente->pontos>10) {
        total = 0.9 * total;
        cliente->pontos = cliente->pontos - 10;
    }
    cout << "Total a pagar: " << total << endl;
    for (const auto& filme : cliente -> filmesAlugados) {
        filme -> serDevolvido();
    }
    cliente -> devolver();
}

void Locadora::recomendarFilmes(long cpf) {
    auto itCliente = find_if(this->clientes.begin(), this->clientes.end(),
        [cpf](const Cliente* cliente) { return cliente->cpf == cpf; });
    Cliente* cliente;
    if (itCliente != this->clientes.end()) {
        cliente = *itCliente;
    } else {
        cout << "ERRO: CPF inexistente\n";
        return;
    }

    cliente -> recomendar(this -> clientes);
    cout << "Filmes recomendados para " << cliente->nome << ":" << endl;
    for (Filme* filme : cliente -> recomendados) {
        filme -> lerFilme();
    }

}

void Locadora::avaliarFilme(int id, int nota) {
    auto itFilme = std::find_if(filmes.begin(), filmes.end(),
        [id](Filme* filme) { return filme->id == id; });
    Filme* filme;
    if (itFilme != this->filmes.end()) {
        filme = *itFilme;
    } else { // filme inexistente
        cout << "ERRO: Filme " << id<< " inexistente\n";
        return;
    }

    filme->serAvaliado(nota);
    cout << "Filme "<< filme->id <<" avaliado com sucesso\n";    
}