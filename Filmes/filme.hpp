#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * @file filme.hpp
 * @brief Arquivo de cabeçalho no qual contém os atributos e a especifição dos métodos utilizados no arquivo "filme.cpp".
 * @details Esse arquivo define a classe na qual contém os métodos que serão utilizados no desenvolvimento do 
 * código do arquivo "filme.cpp", especifica o tipo desses métodos (o que eles irão retornar) e os parâmetros que 
 * serão recebidos por eles.
 * @class Filme
 * @details Na classe "Filme", a qual possui como classe amiga "Locadora" e "Cliente", existem como atributos protegidos 
 * quantas vezes um determinado filme foi avaliado ("int vezesAvaliado"), o nome do filme ("string titulo") e o tipo desse filme, seja fita, DVD, etc ("string tipo"). 
 * A classe também contém como atributos públicos um construtor que recebe o id, o nome e a quantidade disponível de determinado filme
 * ("Filme(int id, string titulo, int unidades)") e um destrutor virtual, inicializado como default ("~Filme()"). Existe também um método para calcular quanto será pago pelo
 * aluguel do filme, de acordo com o tempo de aluguel ("virtual int calcularValor(int dias) = 0"), um método para identificar
 * os filmes ("void lerFilme()"), um método para alugar os filmes disponíveis ("virtual void serAlugado()"), um método para devolver
 * os filmes que foram alugados ("void serDevolvido()") e um método para avaliar o filme alugado ("void serAvaliado(int nota)"). Além
 * disso, contém um atributo público para controlar a quantidade de filmes disponíveis na locadora ("int unidades"), outro atributo para registrar
 * a nota de avaliação recebida pelo filme ("float avaliação") e, por fim, um atributo que para registrar o id de identificação de um filme ("int id"). 
 * @param id Determina o id do filme para identificação.
 * @param avaliacao Registra a avaliação recebida pelo filme.
 * @param vezesAvaliado Registra quantas vezes um filme foi avaliado.
 * @param titulo Armazena o nome do filme.
 * @param tipo Armazena o tipo do filme.
 * @param unidades Registra quantas unidades de um filme estão disponíveis para locação.
 * @param erro Informa caso haja erros do código.
*/

class Filme {
  friend class Locadora;
  friend class Cliente;
protected:
  int vezesAvaliado;
  string titulo;
  string tipo;
public:
  Filme(int id, string titulo, int unidades);
  virtual ~Filme() = default;
  virtual int calcularValor(int dias) = 0;
  void lerFilme();
  virtual bool serAlugado();
  void serDevolvido();
  void serAvaliado(int nota);
  int unidades;
  float avaliacao;
  bool erro;
  int id;
};

#endif