#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <sstream>
#include "../Filmes/filme.hpp"
#include "../Cliente/cliente.hpp"
#include "../Filmes/Subclasses/DVDestoque.hpp"
#include "../errors/erros.hpp"
using namespace std;


    dvdEstoque dvdE(1, "Divergente", 0);
    Filme* filme1=&dvdE;
    dvdEstoque dvdE2(1, "Divergente", 2);
    Filme* filme2=&dvdE2;

string saida_filme(Filme* filme){
stringstream saida;
auto cout_saida = cout.rdbuf();
cout.rdbuf(saida.rdbuf());
filme->lerFilme();
cout.rdbuf(cout_saida);
return saida.str();
}


TEST_CASE("Filmes-lerFilme"){
    CHECK(saida_filme(filme1) == "1 Divergente 0 DVD 4.0★\n");
}

TEST_CASE("Filmes-serAlugado"){
    filme2->serAlugado();
    CHECK(filme2->unidades == 1); 
    CHECK(filme1->serAlugado() == false);
}

TEST_CASE ("Filmes-serDevolvido"){
    filme2->serDevolvido();
    CHECK(filme2->unidades == 2);
}

TEST_CASE("Filmes-serAvaliado"){
    filme2->serAvaliado(1);
    CHECK(filme2->avaliacao == 2.5);
    filme2->serAvaliado(4);
    CHECK(filme2->avaliacao == 3);
    //Checagem de ERROS
    CHECK_THROWS(filme2->serAvaliado(10), AvaliacaoErrada());
}