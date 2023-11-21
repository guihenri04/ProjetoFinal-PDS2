#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <string>
using namespace std;

class Filme {
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