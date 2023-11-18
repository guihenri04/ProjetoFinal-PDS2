#ifndef CONTROLE_HPP
#define CONTROLE_HPP

#include "filme.hpp"
#include "cliente.hpp"
#include <vector>
using namespace std;

class Controle {
private:
  vector<Filme> filmes;
public:
  void cadastrarFilme(Filme filme);
  void removerFilme(Filme filme);
  void listarFilmes();
  void cadastrarCliente(Cliente cliente);
  void removerCliente(Cliente cliente);
  void aluguel(Filme filme, Cliente cliente);
  void devolucao(Filme filme, Cliente cliente);
};

#endif