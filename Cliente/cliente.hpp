#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "filme.hpp"
#ifndef CLIENTE_HPP
#define CLIENTE_HPP
using namespace std;

class Cliente {
  friend class Locadora;
protected:
  string nome;
  int cpf;
  int pontos;
  vector<Filme*> filmesAlugados;
  vector<Filme*> historico;
  vector<Filme*> recomendados;
  vector<Cliente*> similares;
public:
  Cliente(int cpf, string nome);
  ~Cliente();
  void lerCliente();
  void alugar (Filme* filme);
  void devolver ();
  int calcularSimilaridade (Cliente* cliente);
  void definirSimilares (vector <Cliente*> clientes);
  vector <Filme*> recomendarPorSimilar(Cliente* cliente);
  void recomendar(vector <Cliente*> clientes);
};

#endif