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

