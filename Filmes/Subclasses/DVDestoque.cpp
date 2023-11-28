#include "DVDestoque.hpp"

/**
 * @file DVDestoque.cpp
 * @brief Construtor do arquivo "DVDestoque.hpp", para identificação e controle dos filmes da locadora.
 * @details Esse construtor inclui uma chamada para o construtor da classe base ("Filme"), o qual contém os mesmos parâmetros para
 * identificação do filme ("(int id, string titulo, int unidades)"). Além disso, define o valor de "tipo" como "DVD".
 * @param tipo Armazena o tipo do filme.
*/

dvdEstoque::dvdEstoque(int id, string titulo, int unidades) : Filme(id, titulo, unidades) {
    this -> tipo = "DVD";
}

/**
 * @brief Método "lerFilme" da classe "Filme", utilizado especialmente para exibição.
 * @details Esse método exibe para o usuário o id do filme, seu título, a quantidade de unidades restantes para locação 
 * na locadora e o tipo do filme.
 * @param tipo Armazena o tipo do filme.
*/

int dvdEstoque::calcularValor(int dias) {
    return 10 * dias;
}