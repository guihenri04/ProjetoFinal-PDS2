#include "../Filmes/Subclasses/DVDpromocao.hpp"

dvdPromocao::dvdPromocao(int id, string titulo, int unidades) : Filme(id, titulo, unidades) {
    this -> tipo = 'DVD';
}

int dvdPromocao::calcularValor(int dias) {
    return 10 * dias;
}

