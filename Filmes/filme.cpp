#include "filme.hpp"

/** 
 * @file filme.cpp
 * @brief Construtor do arquivo "filme.hpp" para identificação e controle dos filmes da locadora.
 * @details Esse construtor registra o id, o nome e a quantidade de filmes disponíveis para locação, auxiliando a locadora no controle.
 * Além disso, registra as avaliações (inicializada em 5) e quantas vezes determinado filme foi avaliado (inicializada em 1).
 * @param id Identifica o filme.
 * @param titulo Armzena o nome do filme.
 * @param unidades Registra quantas unidades de um filme estão disponíveis para locação.
 * @param vezesAvaliado Registra quantas vezes um filme foi avaliado.
 * @param avaliacao Regista a nota de avaliação recebida por um filme.
*/

Filme::Filme (int id, string titulo, int unidades) {
    this -> id = id;
    this -> titulo = titulo;
    this -> unidades = unidades;
    this -> vezesAvaliado = 1;
    this -> avaliacao = 5;
}

/**
 * @brief Método "lerFilme" da classe "Filme", utilizado especialmente para exibição.
 * @details Esse método exibe para o usuário o id do filme, seu título, a quantidade de unidades restantes para locação 
 * na locadora e o tipo do filme.
 * @param tipo Armazena o tipo do filme.
*/
void Filme::lerFilme() {
    cout << this -> id << " ";
    cout << this -> titulo << " ";
    cout << this -> unidades << " ";
    cout << this -> tipo << endl;
}

/**
 * @brief Método "serAlugado" da classe "Filme", utilizado especialmente para controle.
 * @details Esse método controla a quantidade de exemplares de um determinado filme que está na locadora para ser alugado.
 * Caso não existam mais unidades para serem alugadas, o método exibe uma mensagem de erro, informando sobre isso.
*/

void Filme::serAlugado() {
    if (unidades==0) {
        cout << "ERRO: filme indisponivel\n";
    }
    this -> unidades--;
}

/**
 * @brief Método "serDevolvido" da classe "Filme", utilizado especialmente para controle.
 * @details Esse método controla as unidades dos filmes da locadora conforme são devolvidos pelos clientes pós aluguel.
*/

void Filme::serDevolvido() {
    this -> unidades++;
}

/**
 * @brief Método "serAvaliado" da classe "Filme", utilizado para avaliação dos filmes.
 * @details Esse método registra as avalizações dos filmes e também calcula quantas vezes esse filme foi avaliado com
 * uma determinada nota. Além disso, atribui uma média dessas avaliações para esse mesmo filme.
 * @param nota Armazena uma nota recebida pelo filme.
 * @param soma Armazena a soma das notas recebidas pelo filme.
*/

  void Filme::serAvaliado(int nota) {
    float soma = this -> avaliacao * this -> vezesAvaliado;
    soma = soma + nota;
    this -> avaliacao = soma / float(this -> vezesAvaliado);
    this->vezesAvaliado++;
  }
