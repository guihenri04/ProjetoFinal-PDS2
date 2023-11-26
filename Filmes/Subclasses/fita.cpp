#include "fita.hpp"

Fita::Fita(int id, string titulo, int unidades) : Filme(id, titulo, unidades) {
    this -> tipo = "FITA";
    this -> rebobinada = true;
}

void Fita::rebobinar() {
    this -> rebobinada = true;
}

int Fita::calcularValor(int dias) {
    if (this -> rebobinada) {
        return 5;
    } else {
        return 7;
    }
}
void Fita::serAlugado() {
    this -> rebobinada = false;
}