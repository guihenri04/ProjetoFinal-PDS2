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
  vector<Filme*> filmesAlugados;
public:
  string nome;
  int cpf;
  Cliente(int cpf, string nome);
  ~Cliente();
  void lerCliente();
  void alugar (Filme* filme);
  void devolver (Filme* filme);
};

#endif