#include "filme.hpp"

Filme::Filme (int id, string titulo, int unidades) {
    this -> id = id;
    this -> titulo = titulo;
    this -> unidades = unidades;
    this -> vezesAvaliado = 0;
    this -> avaliacao = 5;
}

Filme::~Filme () {
}

void Filme::lerFilme() {
    cout << this -> id << " ";
    cout << this -> titulo << " ";
    cout << this -> unidades << " ";
    cout << this -> tipo << endl;
}

void Filme::serAlugado() {
    if (unidades==0) {
        cout << "ERRO: filme indisponivel\n";
    }
    this -> unidades--;
}

void Filme::serDevolvido() {
    this -> unidades++;
}

  void Filme::serAvaliado(int nota) {
    float soma = this -> avaliacao * this -> vezesAvaliado;
    soma = soma + nota;
    this -> avaliacao = soma / float(this -> vezesAvaliado);
  }
