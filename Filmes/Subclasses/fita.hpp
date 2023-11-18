#include "filme.hpp"
#ifndef FITA_HPP
#define FITA_HPP

class Fita : public Filme {
private:
    bool rebobinada;
public:
    Fita(int id, int titulo, bool rebobinada);
    void rebobinar();
    void assistir();
    float calcularValor() override;
};

#endif