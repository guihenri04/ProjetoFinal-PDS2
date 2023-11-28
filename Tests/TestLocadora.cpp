#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Locadora/locadora.hpp"

    Locadora minhalocadora;
    enum Metodo {ler_filme, ser_alugado, ser_avaliado  };

string saida_filme(Filme* filme, Metodo metodo){
stringstream saida;
auto cout_saida = cout.rdbuf();
cout.rdbuf(saida.rdbuf());
if( metodo == ler_filme){
filme->lerFilme();
}else if(metodo == ser_alugado){
filme->serAlugado();
}else if (metodo == ser_avaliado){
filme->serAvaliado(6);
}
cout.rdbuf(cout_saida);
return saida.str();
}


    TEST_CASE("Locadora-cadastrarFilme"){
        
         minhalocadora.cadastrarFilme('D', 3, 0, "Vou tomar um tacacá", 'E' );
         CHECK( minhalocadora.filmes.size() == 1);
         CHECK( saida_filme(minhalocadora.filmes[0], ler_filme) == "0 Vou tomar um tacacá 3 DVD" );
    }