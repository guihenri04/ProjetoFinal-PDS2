#ifndef DVDESTOQUE_HPP
#define DVDESTOQUE_HPP

#include "filme.hpp"

class dvdEstoque : public Filme {
public:
    dvdEstoque(int id, string titulo, int unidades);
    int calcularValor(int dias) override;
};

#endif