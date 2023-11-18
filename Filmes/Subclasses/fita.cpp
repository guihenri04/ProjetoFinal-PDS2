#include "fita.hpp"

Fita::Fita(int id, int titulo, bool rebobinada) : Filme(id, titulo) {
    this -> rebobinada = rebobinada;
}

void Fita::rebobinar() {
    this -> rebobinada = true;
}

void Fita::assistir() {
    this -> rebobinada = false;
}

float Fita::calcularValor() {
    if (this -> rebobinada) {
        return 5;
    } else {
        return 7;
    }
}