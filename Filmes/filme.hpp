#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Filme {
  friend class Locadora;
  friend class Cliente;
protected:
  int id;
  float avaliacao;
  int vezesAlugado;
  string titulo;
  string tipo;
public:
  Filme(int id, string titulo, int unidades);
  ~Filme();
  virtual int calcularValor(int dias) = 0;
  void lerFilme();
  void serAlugado();
  void serDevolvido(int nota);
  int unidades;
};

#endif