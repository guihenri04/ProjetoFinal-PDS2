#include <iostream>
#ifndef FILME_HPP
#define FILME_HPP

class Filme {
protected:
  int id;
  int titulo;
  static int unidades;
public:
  Filme(int id, int titulo);
  ~Filme();
  virtual float calcularValor() = 0;
};

#endif