#include "filme.hpp"

/** 
 * @file filme.cpp
 * @brief Construtor do arquivo "filme.hpp" para identificação e controle dos filmes da locadora.
 * @details Esse construtor registra o id, o nome e a quantidade de filmes disponíveis para aluguel, auxiliando a locadora no controle.
 * Além disso, registra as avaliações e quantas vezes determinado filme foi avaliado.
 * @param id Identifica o filme.
 * @param titulo Armzena o nome do filme.
 * @param unidades Registra quantas unidades de um filme estão disponíveis para aluguel.
 * @param vezesAvaliado Registra quantas vezes um filme foi avaliado.
 * @param avaliacao Regista a nota de avaliação recebida por um filme.
*/

Filme::Filme (int id, string titulo, int unidades) {
    this -> id = id;
    this -> titulo = titulo;
    this -> unidades = unidades;
    this -> vezesAvaliado = 0;
    this -> avaliacao = 5;
}

Filme::~Filme () {
}

void Filme::lerFilme() {
    cout << this -> id << " ";
    cout << this -> titulo << " ";
    cout << this -> unidades << " ";
    cout << this -> tipo << endl;
}

void Filme::serAlugado() {
    if (unidades==0) {
        cout << "ERRO: filme indisponivel\n";
    }
    this -> unidades--;
}

void Filme::serDevolvido() {
    this -> unidades++;
}

  void Filme::serAvaliado(int nota) {
    float soma = this -> avaliacao * this -> vezesAvaliado;
    soma = soma + nota;
    this -> avaliacao = soma / float(this -> vezesAvaliado);
  }
