#include "fita.hpp"

Fita::Fita(int id, string titulo, int unidades, bool rebobinada) : Filme(id, titulo, unidades) {
    this -> rebobinada = rebobinada;
}

void Fita::rebobinar() {
    this -> rebobinada = true;
}

void Fita::assistir() {
    this -> rebobinada = false;
}

int Fita::calcularValor(int dias) {
    if (this -> rebobinada) {
        return 5;
    } else {
        return 7;
    }
}