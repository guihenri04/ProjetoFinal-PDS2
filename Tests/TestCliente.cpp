#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "DVDestoque.hpp"
#include "cliente.hpp"
#include "DVDpromocao.hpp"
#include "DVDlancamento.hpp"
#include "fita.hpp"

dvdEstoque dvdE(0, "Divergente", 10);
dvdLancamento dvdL(1, "Luisa Carla", 8);
dvdPromocao dvdP(2, "Luisa Acidentada", 5);
Fita fita(2, "Luisa Mulher", 7);

Cliente cliente1(1, "maria");
Cliente cliente2(2, "joao");
Cliente cliente3(3, "andre");
Cliente* pointerCliente1 = &cliente1;
Cliente* pointerCliente2 = &cliente2;
Cliente* pointerCliente3 = &cliente3;

