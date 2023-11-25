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


TEST_CASE("Cliente-lerCliente"){
    Cliente cliente1(1, "maria");
    Cliente* pointerCliente1 = &cliente1;
    CHECK(saida_cliente(pointerCliente1) == "1 maria\n");
}

TEST_CASE("Cliente-alugar"){
    dvdEstoque dvdE(0, "Divergente", 10);
    Filme* filme1=&dvdE;
    Cliente* cliente;
    cliente -> alugar(filme1);
    CHECK(cliente->filmesAlugados.size() == 1);
    CHECK(cliente->historico.size() == 1);
    CHECK(cliente->pontos == 1);
}

TEST_CASE("Cliente-devolver"){
    Cliente* cliente;
    cliente -> devolver();
    CHECK(cliente->filmesAlugados.size() == 0);
}



/*
TEST_CASE("Cliente-recomendar"){

}


TEST_CASE("Cliente-calcularSimilaridade"){
    Cliente* cliente;
    Cliente cliente1(1, "maria");
    Cliente cliente2(2, "joao");
    Cliente* pointerCliente1 = &cliente1;
    Cliente* pointerCliente2 = &cliente2;
    dvdEstoque dvdE(0, "Divergente", 10);
    dvdEstoque dvdE2(2, "Feliz", 3);
    Filme* filme1=&dvdE;
    Filme* filme2=&dvdE2;

}*/