#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Filme {
protected:
  int unidades;
  string titulo;
public:
  int id;
  string tipo;
  Filme(int id, string titulo, int unidades);
  ~Filme();
  virtual int calcularValor(int dias) = 0;
  void lerFilme();
  void serAlugado();
  void serDevolvido();
};

#endif