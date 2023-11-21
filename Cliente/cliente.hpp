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
  int cpf;
  string nome;
  vector<Filme*> filmesAlugados;
public:
  Cliente(int cpf, string nome);
  ~Cliente();
  void alugar (Filme* filme);
  void devolver (Filme* filme);
};

#endif