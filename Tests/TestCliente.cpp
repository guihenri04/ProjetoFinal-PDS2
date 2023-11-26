#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <sstream>
#include "../Cliente/cliente.hpp"
#include "../Filmes/Subclasses/DVDestoque.hpp"
#include "../Filmes/filme.hpp"

using namespace std;



/*#include "DVDpromocao.hpp"
#include "DVDlancamento.hpp"
#include "fita.hpp"*/


string saida_cliente(Cliente* cliente){
stringstream saida;
auto cout_saida = cout.rdbuf();
cout.rdbuf(saida.rdbuf());
cliente->lerCliente();
cout.rdbuf(cout_saida);
return saida.str();
}

    dvdEstoque dvdE(1, "Divergente", 10);
    dvdEstoque dvdE2(2, "Feliz", 11);
    Filme* filme=&dvdE;
    Filme* filme2=&dvdE2;
    Cliente cliente1(1, "maria");
    Cliente cliente2(2, "joao");
    Cliente* pointerCliente1 = &cliente1;
    Cliente* pointerCliente2 = &cliente2;


TEST_CASE("Cliente-lerCliente"){
    CHECK(saida_cliente(pointerCliente1) == "1 maria\n");
}

TEST_CASE("Cliente-alugar"){
    pointerCliente1 -> alugar(filme);
    CHECK(pointerCliente1->filmesAlugados.size() == 1);
    CHECK(pointerCliente1->historico.size() == 1);
    CHECK(pointerCliente1->pontos == 1);
    pointerCliente1->filmesAlugados.clear();
    pointerCliente1->historico.clear();
    pointerCliente1->pontos = 0;
}

TEST_CASE("Cliente-devolver"){
    pointerCliente1->alugar(filme);
    CHECK(pointerCliente1->filmesAlugados.size() == 1);
    pointerCliente1->devolver();
    CHECK(pointerCliente1->filmesAlugados.size() == 0);
}


TEST_CASE("Cliente-calcularSimilaridade"){
pointerCliente1->alugar(filme);
pointerCliente2->alugar(filme);
CHECK (pointerCliente1->calcularSimilaridade(pointerCliente2) == 1);
}