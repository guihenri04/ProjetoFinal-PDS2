
#include "locadora.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>


using namespace std;


int main () {

    
    

    // estruturassssss    vector<Filme*> filmes;        vector<Cliente*> clientes; ???? precisa add? esse bug di .hpp tilt sou mt burro perdao garotas





    string comando;

    while (true) {
        
        string  comando;
    

    do {
        
        cin >> comando;

        switch (comando) {
            case 'CF':
                cadastrarFilme();              //cadastro de filme
                break;

            case 'RF':
                removerFilme(); 
                                                 // remove filme
                break;

            case 'LF':
                listarFilmes();               //  listagem de filme
                break;

            case 'CC':
                cadastrarCliente(); //cadastro de cliente
                break;

            case 'RC':
                removerCliente(); //remoVE cliente
                break;


            case 'LC':
                listarClientes(); // lista clientes 
                break;

            case 'AL':
                aluguel(); // aluga filme
                break;

            case 'DV':
                devolucao(); // devolve filme
                break;

            case 'FS':
            
                std::cout << "end";
                break;

        }
    } while (comando != 'FS');

    return 0;
    }
}
