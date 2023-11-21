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
  vector<Filme*> filmesAlugados;
public:
  Cliente(int cpf, string nome);
  ~Cliente();
  void lerCliente();
  void alugar (Filme* filme);
  void devolver (Filme* filme);
};

#endif