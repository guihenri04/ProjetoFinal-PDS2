#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../Locadora/locadora.hpp"
#include "../Filmes/filme.hpp"
#include "../Cliente/cliente.hpp"
#include "../Filmes/Subclasses/DVDestoque.hpp"
#include "../Filmes/Subclasses/DVDlancamento.hpp"
#include "../Filmes/Subclasses/DVDpromocao.hpp"
#include "../Filmes/Subclasses/fita.hpp"
#include "../errors/erros.hpp"

    Locadora minhalocadora;
    Locadora locadorazerada;
    

string saida_filme(Filme* filme){
    stringstream saida;
    auto cout_saida = cout.rdbuf();
    cout.rdbuf(saida.rdbuf());
    filme->lerFilme();
    cout.rdbuf(cout_saida); 
    return saida.str();
}

string saida_cliente(Cliente* lercliente){
stringstream saida;
auto cout_saida = cout.rdbuf(); 
cout.rdbuf(saida.rdbuf());
lercliente->lerCliente();
cout.rdbuf(cout_saida);
return saida.str();
}

    TEST_CASE("Locadora-cadastrarFilme"){
         minhalocadora.cadastrarFilme('D', 3, 3, "Vou tomar um tacacá", 'E' );
         CHECK( minhalocadora.filmes.size() == 1);
         CHECK( saida_filme(minhalocadora.filmes[0]) == "3 Vou tomar um tacacá 3 DVD 4.0★\n" );
         minhalocadora.cadastrarFilme('D', 4, 2, "Dançar", 'L' );
         CHECK( minhalocadora.filmes.size() == 2);
         CHECK( saida_filme(minhalocadora.filmes[1]) == "2 Dançar 4 DVD 4.0★\n" );
         minhalocadora.cadastrarFilme('D', 5, 7, "Curtir", 'P' );
         CHECK( minhalocadora.filmes.size() == 3);
         CHECK( saida_filme(minhalocadora.filmes[2]) == "7 Curtir 5 DVD 4.0★\n" );
         minhalocadora.cadastrarFilme('F', 6, 1, "Ficar de boa", 'E' );
         CHECK( minhalocadora.filmes.size() == 4);
         CHECK( saida_filme(minhalocadora.filmes[3]) == "1 Ficar de boa 6 FITA 4.0★\n" );

    }

    TEST_CASE("Locadora-removerFilme"){
        minhalocadora.removerFilme(3);
        CHECK(minhalocadora.filmes.size() ==  3);
        CHECK(saida_filme(minhalocadora.filmes[0]) == "2 Dançar 4 DVD 4.0★\n");
        
    }


    TEST_CASE("Locadora-listarFilmes"){
        minhalocadora.listarFilmes('C');
        CHECK(saida_filme(minhalocadora.filmesOrdenados[0]) == "1 Ficar de boa 6 FITA 4.0★\n" );
        CHECK(saida_filme(minhalocadora.filmesOrdenados[1]) == "2 Dançar 4 DVD 4.0★\n");
        CHECK( saida_filme(minhalocadora.filmesOrdenados[2]) == "7 Curtir 5 DVD 4.0★\n" );
        minhalocadora.listarFilmes('T');
        CHECK( saida_filme(minhalocadora.filmesOrdenados[0]) == "7 Curtir 5 DVD 4.0★\n" );
        CHECK(saida_filme(minhalocadora.filmesOrdenados[1]) == "2 Dançar 4 DVD 4.0★\n");
        CHECK(saida_filme(minhalocadora.filmesOrdenados[2]) == "1 Ficar de boa 6 FITA 4.0★\n" );


    }

    TEST_CASE("Locadora-cadasstrarCliente"){
        minhalocadora.cadastrarCliente(15522645707, "guilherme");
        CHECK(saida_cliente(minhalocadora.clientes[0]) == "15522645707 guilherme\n");
        minhalocadora.cadastrarCliente(11111111111, "ramon");
        CHECK(saida_cliente(minhalocadora.clientes[1]) == "11111111111 ramon\n");
        minhalocadora.cadastrarCliente(44444444444, "carlos");
        CHECK(saida_cliente(minhalocadora.clientes[2]) == "44444444444 carlos\n");
        minhalocadora.cadastrarCliente(33333333333, "alice");
        CHECK(saida_cliente(minhalocadora.clientes[3]) == "33333333333 alice\n");

    }

     TEST_CASE("Locadora-removerCliente"){
        minhalocadora.removerCliente(15522645707);
        CHECK(minhalocadora.clientes.size() == 3);

    }

     TEST_CASE("Locadora-listarClientes"){
        minhalocadora.listarClientes('C');
        CHECK(saida_cliente(minhalocadora.clientesOrdenados[0]) == "11111111111 ramon\n");
        CHECK(saida_cliente(minhalocadora.clientesOrdenados[1]) == "33333333333 alice\n");
        CHECK(saida_cliente(minhalocadora.clientesOrdenados[2]) == "44444444444 carlos\n");
        minhalocadora.listarClientes('N');
        CHECK(saida_cliente(minhalocadora.clientesOrdenados[0]) == "33333333333 alice\n");
        CHECK(saida_cliente(minhalocadora.clientesOrdenados[1]) == "44444444444 carlos\n");
        CHECK(saida_cliente(minhalocadora.clientesOrdenados[2]) == "11111111111 ramon\n");

    }

     TEST_CASE("Locadora-aluguel"){
         vector <int> id_2 = {minhalocadora.filmes[0]->id, minhalocadora.filmes[1]->id};
        minhalocadora.aluguel(11111111111, id_2 );
        CHECK(minhalocadora.clientes[0]->historico.size() == 2);
        CHECK(minhalocadora.clientes[0]->filmesAlugados.size() == 2);
        CHECK(minhalocadora.clientes[0]->filmesAlugados[0] == minhalocadora.filmes[0]);
        CHECK(minhalocadora.clientes[0]->historico[0] == minhalocadora.filmes[0]);
        CHECK(minhalocadora.clientes[0]->filmesAlugados[1] == minhalocadora.filmes[1]);
        CHECK(minhalocadora.clientes[0]->historico[1] == minhalocadora.filmes[1]);
        CHECK(minhalocadora.clientes[0]->pontos ==2);
        CHECK(minhalocadora.filmes[0]->unidades == 3);
        CHECK(minhalocadora.filmes[1]->unidades == 4);

    }

    TEST_CASE("Locadora-devolução"){
        minhalocadora.devolucao(11111111111, 3);
        CHECK(minhalocadora.clientes[0]->filmesAlugados.size() == 0);;
        CHECK(minhalocadora.filmes[0]->unidades == 4);
        CHECK(minhalocadora.filmes[1]->unidades == 5);

    }

     TEST_CASE("Locadora-avaliarFilme"){
        minhalocadora.avaliarFilme(2, 1);
        CHECK(minhalocadora.filmes[0]->avaliacao == 2.5);
        minhalocadora.avaliarFilme(2, 4);
        CHECK(minhalocadora.filmes[0]->avaliacao == 3);

    }
