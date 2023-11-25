#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "../Filmes/filme.hpp"
#ifndef CLIENTE_HPP
#define CLIENTE_HPP
using namespace std;

class Cliente {
  friend class Locadora;
protected:
  string nome;
  int cpf;
  vector<Filme*> recomendados;
  vector<Cliente*> similares;
  int calcularSimilaridade (Cliente* cliente);
  void definirSimilares (vector <Cliente*> clientes);
  vector <Filme*> recomendarPorSimilar(Cliente* cliente);
public:
  Cliente(int cpf, string nome);
  ~Cliente();
  void lerCliente();
  void alugar (Filme* filme);
  void devolver ();
  void recomendar(vector <Cliente*> clientes);
  int pontos;
  vector<Filme*> filmesAlugados;
  vector<Filme*> historico;
};

#endif