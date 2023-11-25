#include "DVDlancamento.hpp"

dvdLancamento::dvdLancamento(int id, string titulo, int unidades) : Filme(id, titulo, unidades) {
    this -> tipo = 'DVD';
}

int dvdLancamento::calcularValor(int dias) {
    return 20 * dias;
}