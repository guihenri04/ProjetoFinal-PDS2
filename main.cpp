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

        cout << "Digite um comando: " << endl;                                          // fazer menu
        cin >> comando;

      
        if (comando.size() < 2) {
            cout << "Comando inválido." << endl;
            continue;
        }

        switch (comando[0]) {

            case 'C': {                                                       
                switch (comando[1]) {

                    case 'F': {

                        cout << "CADASTRAR FILME" << endl;

                        cout << "Digite o tipo (D para DVD ou F para fita): " << endl;
                        char tipo; 
                        cin >> tipo;

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
                            cout << "Digite a categoria do DVD (E, L ou P):" << endl;
                            cout << "-> E: DVDs em estoque" << endl;
                            cout << "-> L: DVDs no lançamento" << endl;
                            cout << "-> P: DVDs na promoção" << endl;
                            cin >> categoria;
                        }
                        CineMax.cadastrarFilme(tipo, unidades, id, titulo, categoria);

                        break;    
                    }
                    
                    case 'C': {
                        
                        cout << "CADASTRAR CLIENTE" << endl;

                        cout << "Digite o CPF do cliente:" << endl;
                        long cpf;
                        cin >> cpf;

                        cout << "Digite o nome do cliente:" << endl;
                        string nome;
                        getline(cin,nome);

                        CineMax.cadastrarCliente(cpf,nome);

                        break;
                    }

                    default: {

                        cout << "Comando inválido.\n";
                        continue;            
        
                    }
                }
            }

            case 'R': {                                               
                switch (comando[1]) {

                    case 'F': {
                        
                        cout << "REMOVER FILME" << endl;
                        cout << "Digite o ID do filme que deseja remover:" << endl;

                        int id;
                        cin >> id;

                        CineMax.removerFilme(id);

                        break;
                    }

                    case 'C': {

                        cout << "REMOVER CLIENTE" << endl;
                        cout << "Digite o CPF do cliente que deseja remover:" << endl;

                        long cpf;
                        cin >> cpf;
                        
                        CineMax.removerCliente(cpf);

                        break;
                    }
                    
                    default: {
                        cout << "Comando inválido.\n";
                        continue;    
                    }                                                               
                }
                break;
            }

            case 'L': {                          
                switch (comando[1]) {

                    case 'A': {
                        
                        cout << "LER ARQUIVO DE CADASTRO" << endl;
                        cout << "Digite o nome do arquivo: " << endl;

                        string nomeArquivo;
                        cin >> nomeArquivo;

                        ifstream arquivo(nomeArquivo);
                        string linha;

                        if (arquivo.is_open()) {

                            string linha;
                            int contador = 0;

                            while (std::getline(arquivo, linha)) {

                                contador++;
                            }

                        arquivo.close();

                        cout << contador << "Filmes cadastrados com sucesso!" << endl;

                        } 

                        else {

                            cout << "ERRO: Arquivo inexistente!" << endl;

                        }

                        break;
                    }

                    case 'F': {

                        cout << "LISTAR FILMES" << endl;
                        cout << " -> Caso queira listar os filmes pela ordem de seus títulos, digite T:" << endl;
                        cout << " -> Caso queira listar os filmes pela ordem de seus códigos, digite C: " << endl;

                        char opcaof;
                        cin >> opcaof;

                        CineMax.listarFilmes(opcaof);
                        
                        break;
                    }
                    
                    case 'C': {

                        cout << "LISTAR CLIENTES" << endl;
                        cout << " -> Caso queira listar os clientes pela ordem de seus códigos (CPFs), digite C:" << endl;
                        cout << " -> Caso queira listar os clientes pela ordem de seus nomes, digite N:" << endl;

                        char opcaoc;
                        cin >> opcaoc;

                        CineMax.listarClientes(opcaoc);
                        
                        break;
                    }

                    default: { 

                        cout << "Comando inválido." << endl;
                        continue ;

                    }
                }
                break;      
            }

            case 'A': {
                switch (comando[1]) {

                    case 'L': {
                        
                        cout << "ALUGUEL DE FILME" << endl;

                        cout << "Digite o CPF do cliente que alugou o filme:" << endl;
                        long cpf;
                        cin >> cpf;

                        cout << "DIgite o ID do filme alugado:" << endl;
                        int id;
                        cin >> id;
                        
                        CineMax.aluguel(cpf, id);

                        break;
                    }
                       
                    default: {

                        cout << "Comando inválido." << endl;
                        continue;    

                    }   
                
                }
                break;
            }

            case 'D': {
                switch (comando[1]) {

                    case 'V': {
                        
                        cout << "DEVOLUÇÃO DE FILME" << endl;

                        cout << "Digite o CPF do cliente que realiza a devolução dos filmes:" << endl;
                        long cpf;
                        cin >> cpf;

                        CineMax.devolucao(cpf);

                        break;
                    }
                    
                    default: {
                        cout << "Comando inválido." << endl;
                        continue;
                    }
                }
                break;
            }

            case 'N': {
                switch (comando[1]) {

                    case 'F': {
                        
                        cout << "AVALIAR FILME" << endl;

                        cout << "Digite o id do filme a ser avaliado:" << endl;
                        int id;
                        cin >> id;
                        cout << "Digite a nota do filme, de 0 a 5:" << endl;
                        int nota;
                        cin >> nota;

                        CineMax.avaliarFilme(id,nota);

                        break;
                    }
                    
                    default: {
                        cout << "Comando inválido." << endl;
                        continue;
                    }
                }
                break;
            }

            case 'S': {
                switch (comando[1]) {

                    case 'F': {
                        
                        cout << "SUGERIR FILMES" << endl;

                        cout << "Digite o cpf do cliente que busca recomendações:" << endl;
                        long cpf;
                        cin >> cpf;

                        CineMax.recomendarFilmes(cpf);

                        break;
                    }
                    
                    default: {
                        cout << "Comando inválido." << endl;
                        continue;
                    }
                }
                break;
            }

            case 'F': { 

                switch (comando[1]) {
                    case 'S': 

                        cout << "Programa encerrado!" << endl;
                        return 0;

                break;
            }
            
                default: {
                    cout << "Comando inválido." << endl;
                    continue;
                }

            }
        
        }
        
    }

    return 0;
}