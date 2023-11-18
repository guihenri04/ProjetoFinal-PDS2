#include <iostream>
#include <string>
#ifndef FILME_HPP
#define FILME_HPP
using namespace std;

class Filme {
protected:
  int id;
  string titulo;
  int unidades;
public:
  Filme(int id, string titulo, int unidades);
  ~Filme();
  virtual int calcularValor(int dias) = 0;
};

#endif