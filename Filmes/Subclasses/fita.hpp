#ifndef FITA_HPP
#define FITA_HPP

#include "../Filmes/filme.hpp"

class Fita : public Filme {
private:
    bool rebobinada;
public:
    Fita(int id, string titulo, int unidades);
    void rebobinar();
    void assistir();
    int calcularValor(int dias) override;
};

#endif