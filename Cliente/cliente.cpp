#include "cliente.hpp"
#include <set>

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
    if (filme->unidades==0) {
        return;
    }
    this -> filmesAlugados.push_back(filme);
    this -> pontos++;
    this -> historico.push_back(filme);
}

void Cliente::devolver() {
    for (const auto& filme : this->filmesAlugados) {
        delete filme;
    }
    this->filmesAlugados.clear();
}

int Cliente::calcularSimilaridade (Cliente* cliente2) {
    int similaridade = 0;
    for (Filme* filme1 : this -> historico) {
        for (Filme* filme2 : cliente2 -> historico) {
            if (filme1 == filme2) {
                similaridade++;
            }
        }
    }
    return similaridade;
}

void Cliente::definirSimilares (vector <Cliente*> clientes) {
    if (clientes.size()<=3) {
        this -> similares = clientes;
        return;
    }   
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    Cliente* c1;
    Cliente* c2;
    Cliente* c3;
    for (Cliente* cliente : clientes) {
        int similaridade = this -> calcularSimilaridade(cliente);
        if (similaridade > s1) {
            s3 = s2;
            s2 = s1;
            s1 = similaridade;
            c3 = c2;
            c2 = c1;
            c1 = cliente;
        } else if (similaridade > s2) {
            s3 = s2;
            s2 = similaridade;
            c3 = c2;
            c2 = cliente;
        } else if (similaridade > s3) {
            s3 = similaridade;
            c3 = cliente;
        }
    }
    this -> similares.push_back(c1);
    this -> similares.push_back(c2);
    this -> similares.push_back(c3);
}

vector <Filme*> Cliente::recomendarPorSimilar(Cliente* cliente) {
    if (cliente->historico.size() > 0) {
        cout << "Ainda não há filmes recomendados." << endl;
        return;
    }
    vector <Filme*> recomendados;
    set<Filme*> conjuntoRecomendados;
    bool aindaTemFilmes = true;
    
    while (aindaTemFilmes) {
        bool inedito = true;
        for (int i = 1; true; i++) {
            Filme* recomendado = cliente->historico[cliente->historico.size()-i];
            for (Filme* filmeVisto : this -> historico) {
                if (recomendado == filmeVisto) {
                    inedito = false;
                    break;
                }
            }
            if (inedito) {
                recomendados.push_back(recomendado);
                conjuntoRecomendados.insert(recomendado);
                break;
            }
            if (cliente->historico.size()-i == 0) {
                aindaTemFilmes = false;
                break;
            }
        }
    }
    recomendados.assign(conjuntoRecomendados.begin(), conjuntoRecomendados.end());
    return recomendados;
}

void Cliente::recomendar(vector <Cliente*> clientes) {
    if (this -> similares.size() == 0) {
        cout << "Ainda não há filmes recomendados." << endl;
        return;
    }
    this->recomendados.clear();
    for (Cliente* cliente : clientes) {
        vector <Filme*> recomendados = this -> recomendarPorSimilar(cliente); 
        for (Filme* filme : recomendados) {
            this -> recomendados.push_back(filme);
        }
    }
}