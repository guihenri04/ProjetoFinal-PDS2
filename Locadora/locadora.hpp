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
public:
  Locadora();
  ~Locadora();
  void cadastrarFilme(char tipo, int quantidade, int id, const string& titulo, const char& categoria);
  void removerFilme(int codigo);
  void listarFilmes(char opcao);
  void cadastrarCliente(long long cpf, string nome);
  void removerCliente(long long cpf);
  void listarClientes(char opcao);
  void aluguel(long long cpf, int id);
  void devolucao(long long cpf, int dias);
  void recomendarFilmes(long long cpf);
  void avaliarFilme(int id, int nota);
  vector<Filme*> filmes;
  vector<Cliente*> clientes;
};

#endif