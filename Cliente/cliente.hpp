#include <iostream>
#include <string>
#ifndef CLIENTE_HPP
#define CLIENTE_HPP
using namespace std;

class Cliente {
protected:
  int cpf;
  string nome;
public:
  Cliente(int cpf, string nome);
  ~Cliente();
};

#endif