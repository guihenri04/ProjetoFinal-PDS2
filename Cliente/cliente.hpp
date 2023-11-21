#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "filme.hpp"
#ifndef CLIENTE_HPP
#define CLIENTE_HPP
using namespace std;

class Cliente {
protected:
  string nome;
  vector<Filme*> filmesAlugados;
public:
  int cpf;
  Cliente(int cpf, string nome);
  ~Cliente();
  void alugar (Filme* filme);
  void devolver (Filme* filme);
};

#endif