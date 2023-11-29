#include "fita.hpp"

/**
 * @file fita.cpp
 * @brief Construtor do arquivo "fita.hpp", para identificação e controle dos filmes da locadora.
 * @details Esse construtor inclui uma chamada para o construtor da classe base ("Filme"), o qual contém os mesmos parâmetros para
 * identificação da fita ("(int id, string titulo, int unidades)"). Além disso, define o valor de "tipo" como "FITA" e o valor de 
 * "rebobinada" como "true".
 * @param tipo Armazena o tipo do filme (no caso, filme).
 * @param rebobinada Determina se a fita foi rebobinada ou não.
*/

Fita::Fita(int id, string titulo, int unidades) : Filme(id, titulo, unidades) {
    this -> tipo = "FITA";
    this -> rebobinada = true;
}

/**
 * @brief Método "rebobinar" da classe "Filme", utilizado especialmente para controle.
 * @details Esse método determina que uma determinada fita foi rebobinada.
*/

void Fita::rebobinar() {
    this -> rebobinada = true;
}

/**
 * @brief Método "calcularValor" da classe "Fita", utilizado especialmente para controle e registro.
 * @details Esse método calcula quanto o cliente terá de pagar pelo aluguel da fita de acordo com a quantidade de dias
 * que ela ficou alugada. Caso o cliente devolva a fita já rebobinada, o aluguel é fixo em 5 reais, caso contrário, é fixo em 7
 * reais.
 * @param dias Armazena quantos dias um determinado filme (no caso, fita) ficou alugado.
 * @return Retorna o preço que o cliente terá de pagar pelo aluguel da fita, sendo 5 reais fixos o preço da locação
 * de uma fita rebobinada e 7 reais fixos o de uma não rebobinada.
*/

int Fita::calcularValor(int dias) {
    if (this -> rebobinada) {
        return 5;
    } else {
        return 7;
    }
}

/**
 * @brief Método "serAlugado" da classe "Filme", utilizado especialmente para controle.
 * @details Esse método determina que, sempre que uma fita for alugada, ela será automaticamente considerada desrebobinada.
*/

bool Fita::serAlugado() {
    bool podeSerAlugado = Filme::serAlugado(); 
    if (podeSerAlugado) {
        this->rebobinada = false;
        return true; 
    }
    return false;
}
