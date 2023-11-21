#ifndef LOCADORA_HPP
#define LOCADORA_HPP

#include "filme.hpp"
#include "cliente.hpp"
#include "DVDestoque.hpp"
#include "DVDlancamento.hpp"
#include "DVDpromocao.hpp"
#include "fita.hpp"
#include <vector>
#include <algorithm>
using namespace std;

class Locadora {
private:
  vector<Filme*> filmes;
  vector<Cliente*> clientes;
public:
  Locadora();
  void cadastrarFilme(string tipo, int quantidade, int id, const string& titulo, const string& categoria);
  void removerFilme(int codigo);
  void listarFilmes();
  void cadastrarCliente(Cliente* cliente);
  void removerCliente(Cliente* cliente);
  void aluguel(Filme* filme, Cliente* cliente);
  void devolucao(Filme* filme, Cliente* cliente);
};

#endif