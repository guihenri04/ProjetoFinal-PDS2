#ifndef DVDPROMOCAO_HPP
#define DVDPROMOCAO_HPP

#include "../filme.hpp"

class dvdPromocao : public Filme {
public:
    dvdPromocao(int id, string titulo, int unidades);
    int calcularValor(int dias) override;
};

#endif