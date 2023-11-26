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
  int vezesAvaliado;
  string titulo;
  string tipo;
public:
  Filme(int id, string titulo, int unidades);
  ~Filme();
  virtual int calcularValor(int dias) = 0;
  void lerFilme();
  void serAlugado();
  void serDevolvido();
  void serAvaliado(int nota);
  int unidades;
};

#endif