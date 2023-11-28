#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <sstream>
#include "../Filmes/filme.hpp"
#include "../Cliente/cliente.hpp"

using namespace std;

#include "../Filmes/Subclasses/DVDestoque.hpp"

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

string saida_filme2(Filme* filme){
stringstream saida;
auto cout_saida = cout.rdbuf();
cout.rdbuf(saida.rdbuf());
filme->serAlugado();
cout.rdbuf(cout_saida);
return saida.str();
}

TEST_CASE("Filmes-lerFilme"){
    CHECK(saida_filme(filme1) == "1 Divergente 0/n");
}

TEST_CASE("Filmes-serAlugado"){
    filme2->serAlugado();
    CHECK(filme2->unidades == 1); 
    CHECK(saida_filme2(filme1) == "ERRO: filme indisponivel\n");  
}

TEST_CASE ("Filmes-serDevolvido"){
    filme1->serDevolvido();
    CHECK(filme1->unidades = 1);
}

/*TEST_CASE("Filmes-serAvaliado"){
    filme2->serAvaliado(4);
    CHECK(filme2->avaliacao = 4);
}*/