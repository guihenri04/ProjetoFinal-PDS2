#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>
#include "cliente.cpp"

#include "DVDestoque.hpp"
#include "cliente.hpp"
#include "DVDpromocao.hpp"
#include "DVDlancamento.hpp"
#include "fita.hpp"

using namespace std;

dvdEstoque dvdE(0, "Divergente", 10);
dvdLancamento dvdL(1, "Luisa Carla", 8);
dvdPromocao dvdP(2, "Luisa Acidentada", 5);
Fita fita(2, "Luisa Mulher", 7);


string saida_cliente(Cliente* cliente){
stringstream saida;
auto cout_saida = cout.rdbuf();
cout.rdbuf(saida.rdbuf());
cliente->lerCliente();
cout.rdbuf(cout_saida);
return saida.str();
}

TEST_CASE("Cliente"){
    Cliente cliente1(1, "maria");
    Cliente cliente2(2, "joao");
    Cliente cliente3(3, "andre");
    Cliente* pointerCliente1 = &cliente1;
    Cliente* pointerCliente2 = &cliente2;
    Cliente* pointerCliente3 = &cliente3;

    CHECK(saida_cliente(pointerCliente1) == "1 maria\n");
}
