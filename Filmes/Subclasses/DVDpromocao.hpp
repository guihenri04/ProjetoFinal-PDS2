#include "filme.hpp"
#ifndef DVDPROMOCAO_HPP
#define DVDPROMOCAO_HPP

class dvdPromocao : public Filme {
public:
    int calcularValor(int dias) override;
};

#endif