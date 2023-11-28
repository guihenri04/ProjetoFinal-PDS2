#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "../Filmes/filme.hpp"
#ifndef CLIENTE_HPP
#define CLIENTE_HPP
using namespace std;

/**
* @file cliente.hpp
* @brief Arquivo de cabeçalho no qual contém os atributos e a especifição dos métodos utilizados no arquivo "cliente.cpp".
* @details Esse arquivo define a classe na qual contém os métodos que serão utilizados no desenvolvimento do 
* código do arquivo "cliente.cpp", especifica o tipo desses métodos (o que eles irão retornar) e os parâmetros que 
* serão recebidos por eles.
* @class Cliente 
* @details Na classe "Cliente", a qual possui como classe amiga "Locadora", existem como atributos protegidos o 
* nome do cliente ("string nome") e seu cpf ("long long cpf").
* A classe também contém como atributos públicos um construtor que recebe o cpf e o nome do cliente ("Cliente(long long cpf, string nome)")
* um destrutor ("~Cliente()") e os pontos dos clientes com base nos filmes alugados ("int pontos"). Existe também um método para 
* identificação de clientes ("void lerCliente()"), um método para controlar a quantidade e quais filmes foram alugados ("void alugar (Filme* filme)"), 
* um método para controlar a quantidade e quais filmes foram devolvidos ("void devolver ()"), um método para recomendar filmes aos clientes 
* ("void recomendar(vector <Cliente*> clientes)"), um método para calcular a quantidade de filmes similares alugados pelos 
* clientes ("int calcularSimilaridade (Cliente* cliente)"), um  método para definir quais clientes possuem gostos 
* similares ("void definirSimilares (vector <Cliente*> clientes)"), um vetor de ponteiros para controlar quais filmes foram alugados 
* ("vector<Filme*> filmesAlugados") um vetor de ponteiros para adicionar filmes ao histórico dos clientes ("vector<Filme*> historico"),
* um vetor de ponteiros de filmes recomendados ("vector<Filme*> recomendados"), 
* um vetor de ponteiros  de filmes similares ("vector<Cliente*> similares") e, por fim, um vetor de ponteiros para recomendar os filmes 
* aos clientes com base na similaridade entre os gostos dos mesmos ("vector <Filme*> recomendarPorSimilar(Cliente* cliente)").
*
* @param nome Registra o nome do cliente.
* @param cpf Registra o cpf do cliente.
* @param recomendados Usado na recomendação de filmes aos clientes.
* @param similares Usado no calculo de similaridade entre os filmes alugados pelos clientes.
* @param recomendarPorSimilar Usado na recomendação de filmes por similaridade entre os clientes.
* @param pontos Registra a quantidade de pontos de cada cliente.
* @param filmesAlugados Usado no controle dos filmes alugados.
* @param historico Usado no controle dos filmes adicionados ao histórico dos clientes.
*/



class Cliente {
  friend class Locadora;
protected:
  string nome;
  long long cpf;
public:
  Cliente(long long cpf, string nome);
  ~Cliente();
  void lerCliente();
  void alugar (Filme* filme);
  void devolver ();
  void recomendar(vector <Cliente*> clientes);
  int pontos;
  int calcularSimilaridade (Cliente* cliente);
  void definirSimilares (vector <Cliente*> clientes);
  vector<Filme*> filmesAlugados;
  vector<Filme*> historico;
  vector<Cliente*> similares;
  vector<Filme*> recomendados;
  vector <Filme*> recomendarPorSimilar(Cliente* cliente);
};

#endif