#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Filme {
  friend class Locadora;
protected:
  int id;
  int unidades;
  string titulo;
  string tipo;
public:
  Filme(int id, string titulo, int unidades);
  ~Filme();
  virtual int calcularValor(int dias) = 0;
  void lerFilme();
  void serAlugado();
  void serDevolvido();
};

#endif