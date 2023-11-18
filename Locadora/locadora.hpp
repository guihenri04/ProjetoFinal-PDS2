#ifndef LOCADORA_HPP
#define LOCADORA_HPP

#include "filme.hpp"
#include "cliente.hpp"
#include <vector>
using namespace std;

class Locadora {
private:
  vector<Filme> filmes;
  vector<Cliente> clientes;
public:
  Locadora();
  void cadastrarFilme(Filme filme);
  void removerFilme(Filme filme);
  void listarFilmes();
  void cadastrarCliente(Cliente cliente);
  void removerCliente(Cliente cliente);
  void aluguel(Filme filme, Cliente cliente);
  void devolucao(Filme filme, Cliente cliente);
};

#endif