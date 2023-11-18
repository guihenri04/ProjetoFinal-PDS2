#include "filme.hpp"
#ifndef DVDLANCAMENTO_HPP
#define DVDLANCAMENTO_HPP

class dvdLancamento : public Filme {
public:
    int calcularValor(int dias) override;
};

#endif