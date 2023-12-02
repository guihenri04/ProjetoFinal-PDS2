#include "DVDlancamento.hpp"

/**
 * @file DVDlancamento.cpp
 */

/** 
 * @brief Construtor do arquivo "DVDlancamento.hpp", para identificação e controle dos filmes da locadora.
 * @details Esse construtor inclui uma chamada para o construtor da classe base ("Filme"), o qual contém os mesmos parâmetros para
 * identificação do filme ("(int id, string titulo, int unidades)"). Além disso, define o valor de "tipo" como "DVD".
 * @param tipo Armazena o tipo do filme.
*/

dvdLancamento::dvdLancamento(int id, string titulo, int unidades) : Filme(id, titulo, unidades) {
    this -> tipo = "DVD";
}

/**
 * @brief Método "calcularValor" da classe "dvdLancamento", utilizado especialmente para controle e registro.
 * @details Esse método calcula quanto o cliente terá de pagar pelo aluguel do filme de acordo com a quantidade de dias
 * que ele ficou alugado.
 * @param dias Armazena quantos dias um determinado filme ficou alugado.
 * @return Retorna o preço que o cliente terá de pagar pelo aluguel do filme, sendo 20 reais por dia o preço da locação
 * de um DVD da categoria "Lançamento".
*/

int dvdLancamento::calcularValor(int dias) {
    return 20 * dias;
}