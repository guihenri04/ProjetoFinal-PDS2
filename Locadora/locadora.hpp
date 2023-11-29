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

/**
 * @file locadora.hpp
 * @brief Arquivo de cabeçalho no qual contém os atributos e a especifição dos métodos utilizados no arquivo "locadora.cpp".
 * @details Esse arquivo define a classe na qual contém os métodos que serão utilizados no desenvolvimento do 
 * código do arquivo "locadora.cpp", especifica o tipo desses métodos (o que eles irão retornar) e os parâmetros que 
 * serão recebidos por eles.
 * @class Locadora
 * @details Na classe "Locadora",existem como atributos públicos um construtor ("Locadora()") e um destrutor ("~Locadora()"). 
 * Existe também um método para cadastranr filmes, que recebe como parâmetros o tipo do filme, a quantidade dele, seu id de identificação,
 * seu título e sua e sua categoria, seja estoque, promoção ou lançamento ("void cadastrarFilme(char tipo, int quantidade, int id, const string& titulo, const char& categoria)"),
 * um método para remover filmes de acordo com seu código ("void removerFilme(int codigo)"), um método para listar filmes de
 * de acordo com a opção selecionada, seja a partir do id de identificação ou título do filme ("void listarFilmes(char opcao)"),
 * um método para cadastrar clientes, de acordo com o cpf e o nome informados ("void cadastrarCliente(long long cpf, string nome)"),
 * um método para remover clientes utilizando somente o cpf informado ("void removerCliente(long long cpf)"), um método para listar clientes
 * a partir da opção selecionada, seja por nome ou cpf cadastrados ("void listarClientes(char opcao)"), um 
 * método para registrar os clientes que alugaram filmes e quais filmes foram alugados, com base em seus id's
 * ("void aluguel(long long cpf, vector <int> id)"), um método para controlar quais clientes fazem a devolução dos filmes e com quantos dias esse cliente ficou
 * com o filme alugado ("void devolucao(long long cpf, int dias)"), um método para recomendar filmes aos clientes, de acordo com o cpf informado
 * ("void recomendarFilmes(long long cpf)") e um método para avaliar os filmes, de acordo com seu id e a nota dada ("void avaliarFilme(int id, int nota)").
 * Além disso, a classe conta um vetor de ponteiros para armazenar os filmes da locadora ("vector<Filme*> filmes") e, por fim, um vetor de ponteiros
 * para armazenar os clientes da locadora ("vector<Cliente*> clientes").
 * @param tipo Armazena o tipo do filme (fita ou DVD).
 * @param quantidade Armazena a quantidade de filmes que serão cadastrados na locadora.
 * @param id Armazena o id de identificação do filme.
 * @param titulo Armazena o título do filme.
 * @param categoria Armazena a categoria do filme (estoque, promoção ou lançamento).
 * @param codigo Armazena o código do filme (id).
 * @param opcao Determina o tipo de listagem de filmes ou clientes a ser selecionada.
 * @param cpf Armazena o cpf do cliente.
 * @param nome Armazena o nome do cliente.
 * @param nota Armazena a nota recebida por um filme.
 * @param filmes Armazena todos os filmes da locadora.
 * @param clientes Armazena todos os clientes da locadora.
 * @param erro Informa caso haja erros no código.
*/

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
  void aluguel(long long cpf, vector<int> id);
  void devolucao(long long cpf, int dias);
  void recomendarFilmes(long long cpf);
  void avaliarFilme(int id, int nota);
  vector<Filme*> filmes;
  vector<Cliente*> clientes;
  vector<Cliente*> clientesOrdenados; 
  vector<Filme*> filmesOrdenados;
  bool erro;
};

#endif