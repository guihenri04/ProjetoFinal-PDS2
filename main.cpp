#include "Locadora/locadora.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>


using namespace std;


int main() {
    Locadora CineMax;
    string comando;

    while (true) {

        cout << "Digite um comando: "; // fazer uma listinha com opçoes faz bem??
        cin >> comando;

      
        if (comando.size() >= 2) { //divide a string e verifica
            switch (comando[0]) {

                case 'C':
                    switch (comando[1]) {

                        case 'F': {
                            cout << "CADASTRAR FILME" << endl;

                            cout << "Digite o tipo (D para DVD ou F para fita): " << endl;
                            char tipo; 
                            cin >> tipo;
                            if (tipo != 'F' && tipo != 'D') {
                                cout << "ERRO: dados incorretos\n";
                                return;
                            }

                            cout << "Digite o número de unidades:" << endl;
                            int unidades;
                            cin >> unidades;

                            cout << "Digite o código:" << endl;
                            int id; 
                            cin >> id;

                            cout << "Digite o título:" << endl;
                            string titulo; 
                            getline(cin,titulo);

                            char categoria = 'X';
                            if (tipo == 'D') {
                                cout << "Digite o categoria do DVD (E, L ou P):" << endl;
                                cin >> categoria;
                                if (categoria != 'E' && categoria != 'L' && categoria != 'P') {
                                    cout << "ERRO: dados incorretos\n";
                                    return;
                                }
                            }

                            CineMax.cadastrarFilme(tipo, unidades, id, titulo, categoria);
                            break;
                        }

                        case 'C': // cadastrar cliente   
                           
                            break;
                    
                        default:
                            cout << "Comando inválido.\n";
                            break;
                    }
                    break;
                case 'R':
                    switch (comando[1]) {
                        case 'F':
                            // remover filme  
                           
                            break;

                        case 'C':
                            // remover cliente
                           
                            break;
                                                                                       //outros casos?
                        default:
                           
                            break;
                    }
                    break;
               
                case 'L':
                    switch (comando[1]) {
                        case 'F':
                            // lista  filmes
                            
                           
                            break;

                        case 'C':
                            // lista clientes
                          
                            break;
                        
                        default:
                            cout << "Comando inválido.\n";
                            break;
                    }
                    break;
                
                case 'A':
                    switch (comando[1]) {
                        case 'L':
                            
                            // aluguel
                            
                            break;
                        
                        default:
                            cout << "Comando inválido.\n";
                            break;
                    }
                    break;
                case 'D':
                    switch (comando[1]) {
                        case 'V':    
                            // devolucao
                            break;

                        default:
                            cout << "Comando inválido.\n";
                            break;
                    }
                    break;
                case 'F':
                    switch (comando[1]) {
                        case 'S':

                            cout << "Programa encerrado!\n";
                            return 0;

                        default:
                            cout << "Comando inválido.\n";
                            break;
                    }
                    break;

                default:
                    cout << "Comando inválido.\n";
                    break;
            }

        } 
        
        else {
            cout << "Comando inválido \n";
        }
    }
    return 0;
}