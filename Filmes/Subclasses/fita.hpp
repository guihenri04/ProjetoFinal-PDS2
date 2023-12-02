#ifndef FITA_HPP
#define FITA_HPP

#include "../filme.hpp"
#include <cstdlib>
#include <ctime>

/**
 * @file fita.hpp
 * @brief Arquivo de cabeçalho no qual contém os atributos e a especifição dos métodos utilizados no arquivo "fita.cpp".
 * @details Esse arquivo define a classe na qual contém os métodos que serão utilizados no desenvolvimento do 
 * código do arquivo "fita.cpp", especifica o tipo desses métodos (o que eles irão retornar) e os parâmetros que 
 * serão recebidos por eles.
 * @class Fita
 * @details Na classe "Fita", que herda publicamente a classe "Filme", existe como atributo privado a variável booleana "rebobinada",
 * que determina se a fita foi rebobinada ou não. A classe também contém como atributos públicos um construtor, o qual
 * recebe como parâmetros um id de identificação de uma fita, seu título e a quantidade de unidades dela disponíveis para locação
 * ("Fita(int id, string titulo, int unidades)"), um método para calcular quanto será pago pelo aluguel da fita de acordo com a quantidade de dias que ela ficou 
 * alugada ("("int calcularValor(int dias) override")") e um método para alugar as fitas disponíveis na locadora ("void serAlugado() override").
 * Ambos métodos substituem funções virtuais na classe base, no caso,"Filme".
 * @param rebobinada Determina se a fita foi rebobinada ou não.
 * @param id Determina o id do filme (no caso, fita) para identificação.
 * @param titulo Armazena o nome do filme (no caso, fita).
 * @param unidades Registra quantas unidades de um filme (no caso, fita) estão disponíveis para locação.
 * @param dias Registra quantos dias um determinado filme (no caso, fita) ficou alugado.
*/

class Fita : public Filme {
private:
    bool rebobinada;
public:
    Fita(int id, string titulo, int unidades);
    int calcularValor(int dias) override;
    bool serAlugado() override;
};

#endif