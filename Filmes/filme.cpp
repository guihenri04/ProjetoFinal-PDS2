#include "filme.hpp"

Filme::Filme (int id, string titulo, int unidades) {
    this -> id = id;
    this -> titulo = titulo;
    this -> unidades = unidades;
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
