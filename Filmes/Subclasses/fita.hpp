#include "filme.hpp"
#ifndef FITA_HPP
#define FITA_HPP

class Fita : public Filme {
private:
    bool rebobinada;
public:
    Fita(int id, string titulo, int unidades, bool rebobinada);
    void rebobinar();
    void assistir();
    int calcularValor(int dias) override;
};

#endif