#ifndef LOCADORA_HPP
#define LOCADORA_HPP

#include "../Filmes/filme.hpp"
#include "../Cliente/cliente.hpp"
#include "../Filmes/Subclasses/DVDestoque.hpp"
#include "../Filmes/Subclasses/DVDlancamento.hpp"
#include "../Filmes/Subclasses/DVDpromocao.hpp"
#include "../Filmes/Subclasses/fita.hpp"
#include <vector>
#include <algorithm>

using namespace std;

class Locadora {
private:
  vector<Filme*> filmes;
  vector<Cliente*> clientes;
public:
  Locadora();
  ~Locadora();
  void cadastrarFilme(char tipo, int quantidade, int id, const string& titulo, const char& categoria);
  void removerFilme(int codigo);
  void listarFilmes(char opcao);
  void cadastrarCliente(int cpf, string nome);
  void removerCliente(int cpf);
  void listarClientes(char opcao);
  void aluguel(int cpf, int id);
  void devolucao(int cpf);
  void recomendarFilmes(int cpf);
  void avaliarFilme(int id, int nota);
};

#endif