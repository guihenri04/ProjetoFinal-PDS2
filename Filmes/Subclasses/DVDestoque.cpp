#include "DVDestoque.hpp"

dvdEstoque::dvdEstoque(int id, string titulo, int unidades) : Filme(id, titulo, unidades) {
    this -> tipo = "DVD";
}

int dvdEstoque::calcularValor(int dias) {
    return 10 * dias;
}