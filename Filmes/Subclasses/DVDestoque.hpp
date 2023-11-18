#include "filme.hpp"
#ifndef DVDESTOQUE_HPP
#define DVDESTOQUE_HPP

class dvdEstoque : public Filme {
public:
    int calcularValor(int dias) override;
};

#endif