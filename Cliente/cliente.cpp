#include "cliente.hpp"
#include <set>

/**
* @file cliente.cpp
* @brief Método do arquivo "cliente.hpp" para identificação dos clientes.
* Este método registra o cpf, o nome e a quantidade de pontos que cada cliente tem, para controle da própria locadora, 
* além de auxiliar em futuras promoções(pontos).
* @param cpf Armazena o cpf do cliente para identificação.
* @param nome Armazena o nome do cliente.
* @param pontos Armazena a quantidade de pontos que cada cliente tem para falicitar o controle de futuras promoções.
*/

Cliente::Cliente(int cpf, string nome) {
    this -> cpf = cpf;
    this -> nome = nome;
    this -> pontos = 0;
}

/** @brief Destrutor da classe "Cliente".
 * 
 * 
 * 
 * 
 */

Cliente::~Cliente() {
    for (Filme* filme : filmesAlugados) {
        delete filme;
    }
    for (Filme* filme : historico) {
        delete filme;
    }
    for (Filme* filme : recomendados) {
        delete filme;
    }
    for (Cliente* cliente : similares) {
        delete cliente;
    }
};

/** @brief Método "lerCliente" classe "Cliente", utilizado especialmente para exibição.
 * Esse método exibe para o usuário o cpf e o nome do cliente registrado na locadora.
 */

void Cliente::lerCliente(){
    cout << this -> cpf << " ";
    cout << this -> nome << endl;
}

/** @brief Método "alugar" da classe "Cliente", utilizado para registro.
 * Esse método registra a quantidade de filmes alugados pelo cliente, lista esses filmes, adiciona pontos para uma
 * possível futura promoção e registra o histórico de filmes que já foram alugados pelo cliente.
 *  @param unidades Indica a quantidade de filmes alugados pelo cliente.
 *  @param filme Indica o filme alugado pelo cliente.
 *  @param filmesAlugados Armazena os filmes alugados da locadora pelos clientes.
 *  @param historico Armazena os filmes alugados pelo cliente em seu historico.
 */

void Cliente::alugar(Filme* filme) {
    if (filme->unidades==0) {
        return;
    }
    this -> filmesAlugados.push_back(filme);
    this -> pontos++;
    this -> historico.push_back(filme);
}

/** @brief Método "devolver" da classe "Cliente", utilizado especialmente para controle.
 * Esse método controla a quantidade de filmes alugados pelos clientes (o filme devolvido à locadora é retirado do vetor
 * filmesAlugados, para controle).
 */

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
    int s1, s2, s3 = 0;
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
    vector <Filme*> recomendados;
    set<Filme*> conjuntoRecomendados;
    bool aindaTemFilmes = true;

    for (int i = 1; aindaTemFilmes; i++) {
        bool inedito = true;
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
    
    recomendados.assign(conjuntoRecomendados.begin(), conjuntoRecomendados.end());
    return recomendados;
}

void Cliente::recomendar(vector <Cliente*> clientes) {
    this -> definirSimilares(clientes);
    if (this -> similares.size() == 0 || this-> historico.size()==0) {
        cout << "Ainda não há filmes recomendados." << endl;
        return;
    }
    this->recomendados.clear();
    for (Cliente* cliente : clientes) {
        if (this->cpf == cliente->cpf) {
            break;
        } else {
            vector <Filme*> recomendados = this -> recomendarPorSimilar(cliente); 
            for (Filme* filme : recomendados) {
                this -> recomendados.push_back(filme);
            }
        }
    }
}