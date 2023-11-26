#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../Filmes/filme.hpp"
#include "../Cliente/cliente.hpp"

using namespace std;

#include "../Filmes/Subclasses/DVDestoque.hpp"


string saida_filme(Filme* filme){
stringstream saida;
auto cout_saida = cout.rdbuf();
cout.rdbuf(saida.rdbuf());
filme->lerFilme();
cout.rdbuf(cout_saida);
return saida.str();
}

TEST_CASE("Filmes-lerFilme"){
    dvdEstoque dvdE(0, "Divergente", 10);
    Filme* filme1=&dvdE;
    Filme* filme;
    CHECK(saida_filme(filme1) == "0 Divergente 10/n");
}

TEST_CASE("Filmes-serAlugado"){
    dvdEstoque dvdE(1, "Divergente", 0);
    Filme* filme1=&dvdE;
    dvdEstoque dvdE2(1, "Divergente", 2);
    Filme* filme2=&dvdE2;
    Filme* filme;
    int unid = filme2->unidades;
    filme2->serAlugado();
    CHECK(filme2->unidades == unid-1); 
    //CHECK(filme2->serAlugado() == "ERRO: filme indisponivel\n");  
}

TEST_CASE ("Filmes-serDevolvido"){

}
