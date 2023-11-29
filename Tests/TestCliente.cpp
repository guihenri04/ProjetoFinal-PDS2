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


string saida_cliente(Cliente* lercliente){
stringstream saida;
auto cout_saida = cout.rdbuf();
cout.rdbuf(saida.rdbuf());
lercliente->lerCliente();
cout.rdbuf(cout_saida);
return saida.str();
}

void zerar_v(Cliente* cliente){
    cliente->filmesAlugados.clear();
    cliente->historico.clear();
    cliente->pontos = 0;
}


    dvdEstoque dvdE(1, "Divergente", 10);
    dvdEstoque dvdE2(2, "Feliz", 11);
    dvdEstoque dvdE3(3, "CBUM", 4);
    Filme* filme=&dvdE;
    Filme* filme2=&dvdE2;
    Filme* filme3=&dvdE3;
    Cliente cliente1(1, "luisa");
    Cliente cliente2(2, "bruna");
    Cliente cliente3(3, "warley");
    Cliente cliente4(4, "samuel");
    Cliente* pointerCliente1 = &cliente1;
    Cliente* pointerCliente2 = &cliente2;
    Cliente* pointerCliente3 = &cliente3;
    Cliente* pointerCliente4 = &cliente4;
    vector <Cliente*> clientes = {pointerCliente2, pointerCliente3, pointerCliente4};


TEST_CASE("Cliente-lerCliente"){
    CHECK(saida_cliente(pointerCliente1) == "1 luisa\n");
}

TEST_CASE("Cliente-alugar"){
    pointerCliente1 -> alugar(filme);
    CHECK(pointerCliente1->filmesAlugados.size() == 1);
    CHECK(pointerCliente1->historico.size() == 1);
    CHECK(pointerCliente1->filmesAlugados[0] == filme);
    CHECK(pointerCliente1->historico[0] == filme);
    CHECK(pointerCliente1->pontos == 1);
    zerar_v(pointerCliente1);
}

TEST_CASE("Cliente-devolver"){
    pointerCliente1->alugar(filme);
    pointerCliente1->devolver();
    CHECK(pointerCliente1->filmesAlugados.size() == 0);
    zerar_v(pointerCliente1);
}


TEST_CASE("Cliente-calcularSimilaridade"){
    pointerCliente1->alugar(filme);
    pointerCliente2->alugar(filme);
    CHECK (pointerCliente1->calcularSimilaridade(pointerCliente2) == 1);
    zerar_v(pointerCliente1);
    zerar_v(pointerCliente2);
}

TEST_CASE("Cliente-definirSimilares"){
    pointerCliente1->alugar(filme);
    pointerCliente2->alugar(filme);
    pointerCliente3->alugar(filme);
    pointerCliente1->alugar(filme2);
    pointerCliente2->alugar(filme2);
    pointerCliente1->definirSimilares(clientes);
    CHECK(pointerCliente1->similares.size() == 3);
    CHECK(pointerCliente1->similares[0] == pointerCliente2);
    CHECK(pointerCliente1->similares[1] == pointerCliente3);
    CHECK(pointerCliente1->similares[2] == pointerCliente4);
    zerar_v(pointerCliente1);
    zerar_v(pointerCliente2);
    zerar_v(pointerCliente3);
}

TEST_CASE("Cliente-recomendarPorSimiliar"){
    pointerCliente1->alugar(filme);
    pointerCliente2->alugar(filme);
    pointerCliente2->alugar(filme2);
    vector <Filme*> filme_recomendado = pointerCliente1->recomendarPorSimilar(pointerCliente2);
    CHECK(filme_recomendado.size() == 1);
    CHECK(filme_recomendado[0] == filme2);
    zerar_v(pointerCliente1);
    zerar_v(pointerCliente2);
}


TEST_CASE("Cliente-recomendar"){
    pointerCliente4->alugar(filme3);
    pointerCliente1->alugar(filme);
    pointerCliente2->alugar(filme);
    pointerCliente3->alugar(filme);
    pointerCliente1->alugar(filme2);
    pointerCliente2->alugar(filme2);
    pointerCliente1->recomendar(clientes);
    CHECK(pointerCliente1->recomendados[0] == filme);
    CHECK(pointerCliente1->recomendados[1] == filme2);
    CHECK(pointerCliente1->recomendados[2] == filme3);
}