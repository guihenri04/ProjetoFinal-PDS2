#ifndef DVDPROMOCAO_HPP
#define DVDPROMOCAO_HPP

#include "../filme.hpp"

/**
 * @file DVDpromocao.hpp
 * @brief Arquivo de cabeçalho no qual contém os atributos e a especifição dos métodos utilizados no arquivo "DVDpromocao.cpp".
 * @details Esse arquivo define a classe na qual contém os métodos que serão utilizados no desenvolvimento do 
 * código do arquivo "DVDpromocao.cpp", especifica o tipo desses métodos (o que eles irão retornar) e os parâmetros que 
 * serão recebidos por eles.
 * @class dvdPromocao
 * @details Na classe "dvdPromocao", que herda publicamente a classe "Filme", existem como atributos públicos um construtor, o qual
 * recebe como parâmetros o id de identificação de um filme, seu título e a quantidade de unidades disponíveis dele para locação
 * ("dvdPromocao(int id, string titulo, int unidades)"). Existe também um método para calcular quanto será pago pelo aluguel do filme
 * de acordo com a quantidade de dias que ele ficou alugado, o qual substitui uma função virtual na classe base, no caso, "Filme"
 * ("int calcularValor(int dias) override").
 * @param id Determina o id do filme para identificação.
 * @param titulo Armazena o nome do filme.
 * @param unidades Registra quantas unidades de um filme estão disponíveis para locação.
 * @param dias Registra quantos dias um determinado filme ficou alugado.
*/

class dvdPromocao : public Filme {
public:
    dvdPromocao(int id, string titulo, int unidades);
    int calcularValor(int dias) override;
};

#endif