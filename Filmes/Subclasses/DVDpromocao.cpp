#include "DVDpromocao.hpp"

/**
 * @file DVDpromocao.cpp
 */

/**
 * @brief Construtor do arquivo "DVDpromocao.hpp", para identificação e controle dos filmes da locadora.
 * @details Esse construtor inclui uma chamada para o construtor da classe base ("Filme"), o qual contém os mesmos parâmetros para
 * identificação do filme ("(int id, string titulo, int unidades)"). Além disso, define o valor de "tipo" como "DVD".
 * @param tipo Armazena o tipo do filme.
*/

dvdPromocao::dvdPromocao(int id, string titulo, int unidades) : Filme(id, titulo, unidades) {
    this -> tipo = "DVD";
}

/**
 * @brief Método "calcularValor" da classe "dvdPromocao", utilizado especialmente para controle e registro.
 * @details Esse método calcula quanto o cliente terá de pagar pelo aluguel do filme de acordo com a quantidade de dias
 * que ele ficou alugado. Como o DVD está é da categoria "promoção", seu valor é fixo em 10 reais.
 * @param dias Armazena quantos dias um determinado filme ficou alugado.
 * @return Retorna o preço que o cliente terá de pagar pelo aluguel do filme, sendo 10 reais fixos o preço da locação
 * de um DVD da categoria "Promoção".
*/

int dvdPromocao::calcularValor(int dias) {
    return 10;
}

