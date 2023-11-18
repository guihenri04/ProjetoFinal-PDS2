#ifndef DVDLANCAMENTO_HPP
#define DVDLANCAMENTO_HPP

#include "filme.hpp"

class dvdLancamento : public Filme {
public:
    dvdLancamento(int id, string titulo, int unidades);
    int calcularValor(int dias) override;
};

#endif