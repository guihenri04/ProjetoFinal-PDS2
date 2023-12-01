#include "Locadora/locadora.hpp"
#include "errors/erros.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {

/**
 * @file main.cpp
 * @brief Arquivo principal para execução de todo o código fonte.
 */

/**
 * @details Primeiramente, ocorre a criação do objeto "CineMax" a partir da classe "Locadora" e criação de uma string ("comando") para ser utilizada pelo usuário de acordo com
 * os comandos de execução digitados por ele. Depois, são exibidos para o usuário todos os comandos disponíveis para ele usar.
*/
    Locadora CineMax;
    string comando;

    cout << endl;
    printColoredText( "Bem-vindo ao software da CINEMAX ! Digite o comando e pressione enter para executá-lo.\n", 35 );
    cout << endl;
    printColoredText("+----------------------------------+\n", 34); 
    printColoredText("| Comandos disponíveis:            |\n", 34); 
    printColoredText("+----------------------------------+\n", 34); 
    
    printColoredText("| CC: Cadastrar Cliente            |\n", 36); 
    printColoredText("| CF: Cadastrar Filme              |\n", 36); 
    printColoredText("| RC: Remover Cliente              |\n", 36); 
    printColoredText("| RF: Remover Filme                |\n", 36);                                             //  31 red 32verde 33amarelo 31vermelho 34azul  35roxo 36ciano
    printColoredText("| LA: Ler Arquivo de Cadastro      |\n", 36); 
    printColoredText("| LC: Listar Clientes              |\n", 36); 
    printColoredText("| LC: Listar Clientes Bloqueados   |\n", 36); 
    printColoredText("| LF: Listar Filmes                |\n", 36);
    printColoredText("| AL: Aluguel de Filme             |\n", 36);
    printColoredText("| DV: Devolução de Filme           |\n", 36); 
    printColoredText("| PA: Avaliar Filme                |\n", 36); 
    printColoredText("| PS: Sugerir Filmes               |\n", 36); 
    printColoredText("| FS: Finalizar Sistema            |\n", 36); 
    printColoredText("+----------------------------------+\n", 34); 


/**
 * @details O código pede para que um comando seja digitado pelo usuário. Caso o comando seja 
 * "CF" (cadastrar filme), o código solicita ao usuário que seja informado o tipo do filme (DVD ou Fita),
 * o número de unidades, o id de identificação do filme, seu título e categoria (caso ele seja do tipo DVD).
 * Em seguida, o método "cadastrarFilme" é chamado a partir do objeto "CineMax", utilizando os parâmetros 
 * informados pelo usuário.
 * 
*/
    while (true) {

        
        cout << endl; 
        printColoredText("+----------------------------------+\n", 34);   
        cout << "Digite um comando: " << endl;
        cin >> comando;
        printColoredText("+----------------------------------+\n", 34); 

        if (comando.size() > 2 || comando.size() < 2) {
            printColoredText("Comando Inválido!\n", 31);
            continue;
        }

/**
 * @details O código pede para que um comando seja digitado pelo usuário. Caso o comando seja 
 * "CF" (cadastrar filme), o código solicita ao usuário que seja informado o tipo do filme (DVD ou Fita),
 * o número de unidades, o id de identificação do filme, seu título e categoria (caso ele seja do tipo DVD).
 * Em seguida, o método "cadastrarFilme" é chamado a partir do objeto "CineMax", utilizando os parâmetros 
 * informados pelo usuário.
 * 
*/

        switch (comando[0]) {

            case 'C': {                                                       
                switch (comando[1]) {

                    case 'F': {

                        cout << endl << "CADASTRAR FILME" << endl;

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
                        cin.ignore();
                        string titulo; 
                        getline(cin, titulo);

                        char categoria = 'X';
                        if (tipo == 'D') {
                            cout << "Digite a categoria do DVD (E, L ou P):" << endl;
                            cout << "-> E: DVDs em estoque" << endl;
                            cout << "-> L: DVDs no lançamento" << endl;
                            cout << "-> P: DVDs na promoção" << endl;
                            cin >> categoria;
                            cin.ignore();
                        }
                        CineMax.cadastrarFilme(tipo, unidades, id, titulo, categoria);

                        break;    
                    }
/**
 * @details Caso o comando seja "CC" (cadastrar cliente), é solicitado  ao usuário o cpf e o nome do cliente.
 * Em seguida, o método "cadastrarCliente" é chamado a partir do objeto "CineMax", utilizando os parâmetros fornecidos. 
*/                  
                    case 'C': {
                        
                        cout << endl << "CADASTRAR CLIENTE" << endl;

                        cout << "Digite o CPF do cliente:" << endl;
                        long long cpf;
                        cin >> cpf;

                        cout << "Digite o nome do cliente:" << endl;
                        string nome;
                        cin.ignore();
                        getline(cin, nome);

                        CineMax.cadastrarCliente(cpf,nome);

                        break;
                    }

                    default: {

                        printColoredText("Comando Inválido!\n", 31);
                        break;            
        
                    }
                }
                break;
            }

/**
 * @details Caso o comando digitado seja "RF" (remover filme), é solicitado ao usuário o id de identificação
 * do filme no qual ele deseja remover. Em seguida, o método "removerFilme" é chamado a partir do objeto "CineMax",
 * utilizando o parâmetro informado.
*/

            case 'R': {                                               
                switch (comando[1]) {

                    case 'F': {
                        
                        cout << endl << "REMOVER FILME" << endl;
                        cout << "Digite o ID do filme que deseja remover:" << endl;

                        int id;
                        cin >> id;

                        CineMax.removerFilme(id);

                        break;
                    }

/**
 * @details Caso o comando digitado seja "RC" (remover cliente), é solicitado ao usuário o cpf do cliente
 * que se deseja remover. Em seguida, o método "removerCliente" é chamado a partir do objeto "CineMax",
 * utilizando o parâmetro informado.
*/

                    case 'C': {

                        cout << endl << "REMOVER CLIENTE" << endl;
                        cout << "Digite o CPF do cliente que deseja remover:" << endl;

                        long long cpf;
                        cin >> cpf;
                        
                        CineMax.removerCliente(cpf);

                        break;
                    }
                    
                    default: {
                        printColoredText("Comando Inválido!\n", 31);
                        break;    
                    }                                                               
                }
                break;
            }
        
/**
 * @details Caso o comando digitado seja "LA" (ler arquivo de cadastro), é solicitado ao usuário o nome
 * do arquivo desejado. A partir daí, o arquivo de cadastro é aberto e lido linha por linha e, para cada linha,
 * é chamado o método "cadastrarFilme" a partir do objeto "CineMax", com o objetivo de adicionar um novo filme
 * utilizando os parâmetros lidos.
*/

            case 'L': {                          
                switch (comando[1]) {

                    case 'A': {
                        
                        cout << endl << "LER ARQUIVO DE CADASTRO" << endl;
                        cout << "Digite o nome do arquivo: " << endl;

                        string nomeArquivo;                                                                             
                        cin >> nomeArquivo;   
                        
                        cin.ignore();                                                                             

                        ifstream arquivo(nomeArquivo);
                        string linha;

                        if (arquivo.is_open()) {

                            char tipo; 
                            int unidade;
                            int id;
                            string titulo;
                            char categoria;

                            string linha;
                            int contador = 0;

                            while (getline(arquivo, linha)) {

                                istringstream iss(linha);

                                if (iss >> tipo >> unidade >> id >> titulo >> categoria) {

                                CineMax.cadastrarFilme(tipo, unidade, id, titulo, categoria);

                                }

                                contador++;
                            }

                        arquivo.close();

                        cout << contador << "Filmes cadastrados com sucesso!" << endl;

                        } 

                        else {

                           printColoredText("ERRO: Arquivo inexistente!\n",31);

                        }

                        break;
                    }

/**
 * @details Caso o comando "LF" (listar filmes), é solicitado ao usuário a opção de ordenação desejada
 * por ele, seja por id de identificação ou título. Em seguida, o método "listarFilmes" é chamado a partir
 * do objeto "CineMax" utilizando o parâmetro informado. 
*/
                    case 'F': {

                        cout << endl <<"LISTAR FILMES" << endl;
                        cout << " -> Caso queira listar os filmes por ordem de seus títulos, digite T:" << endl;
                        cout << " -> Caso queira listar os filmes por ordem de seus códigos, digite C: " << endl;

                        char opcaof;
                        cin >> opcaof;

                        CineMax.listarFilmes(opcaof);
                        
                        break;
                    }

/**
 * @details Caso o comando digitado seja "LC" (listar clientes), é solicitado ao usuário a opção de ordenação
 * desejada, seja por cpf ou por nome. A partir daí, o método "listarClientes" é chamado a partir do objeto
 * "CineMax", utilizando o parâmetro informado.
*/                  
                    case 'C': {

                        cout << endl <<"LISTAR CLIENTES" << endl;
                        cout << " -> Caso queira listar os clientes por ordem de seus códigos (CPFs), digite C:" << endl;
                        cout << " -> Caso queira listar os clientes por ordem de seus nomes, digite N:" << endl;

                        char opcaoc;
                        cin >> opcaoc;

                        CineMax.listarClientes(opcaoc);
                        
                        break;
                    }

/**
 * @details Caso o comando digitado seja "LB" (listar bloqueados), o método "listarBloqueados" é chamado a partir do objeto
 * "CineMax", gerando assim uma lista de clientes que ainda não devolveram seus filmes alugados e não podem alugar novos.
*/   

                    case 'B': {

                        cout << endl <<"LISTAR CLIENTES BLOQUEADOS" << endl;
                        CineMax.listarBloqueados();
                        break;
                    }

                    default: { 

                        printColoredText("Comando Inválido!\n", 31);
                        break ;

                    }

                }
                break;      
            }

/**
 * @details Caso o comando "AL" (aluguel de filme) seja digitado, é solicitado ao usuário o cpf do cliente que alugou o filme e
 * o número de filmes que foram alugados. Em seguida, é pedido o id de identificação de cada filme alugado, de forma
 * que eles são armazenados em um vetor. Se a quantidade de filmes alugados for menor ou igual a zero, uma mensagem 
 * de erro é exibida. Se não, o método "aluguel" é chamado a partir do objeto "CineMax", utilizando os parãmetros informados. 
*/

            case 'A': {
                switch (comando[1]) {

                    case 'L': {
                        
                        cout << endl << "ALUGUEL DE FILME" << endl;

                        cout << "Digite o CPF do cliente que alugou o filme:" << endl;
                        long long cpf;
                        cin >> cpf;
                        
                        cout << "Digite o número de filmes alugados pelo cliente:" << endl;
                        int quantidade;
                        cin >> quantidade;
                        vector<int> filmesAlugados;
                        
                        for (int i = 0; i < quantidade; i++) {
                            cout << "Id do filme " << i+1 << ": ";
                            int id;
                            cin >> id;
                            filmesAlugados.push_back(id);
                        }

                        if (quantidade<=0) {
                            printColoredText("ERRO: a quantidade de filmes alugados deve ser maior que 0\n", 31);
                        } else {
                            CineMax.aluguel(cpf,filmesAlugados);
                        }

                        break;
                    }
                       
                    default: {

                        printColoredText("Comando Inválido!\n", 31);
                        break;    

                    }   
                
                }
                break;
            }

/**
 * @details Caso o comando digitado seja "DV" (devolução de filme), é solicitado ao usuário o cpf do cliente que está devolvendo
 * filmes e o número de dias que o cliente ficou com esses filmes alugados. Em seguida, o método "devolucao" é chamado a partir do 
 * objeto ("CineMax"), utilizando esses parâmetros.
*/

            case 'D': {
                switch (comando[1]) {

                    case 'V': {
                        
                        cout << endl <<"DEVOLUÇÃO DE FILME" << endl;

                        cout << "Digite o CPF do cliente que realiza a devolução dos filmes:" << endl;
                        long long cpf;
                        cin >> cpf;

                        cout << "Digite o número de dias que o cliente manteve os filmes:" << endl;
                        int dias;
                        cin >> dias;

                        CineMax.devolucao(cpf, dias);

                        break;
                    }
                    
                    default: {
                        printColoredText("Comando Inválido!\n", 31);
                        break;
                    }
                }
                break;
            }

/**
 * @details Caso o código digitado seja "PA" (avaliar filme), é solicitado ao usuário o id de identificação
 * do filme que se deseja avaliar e nota do filme de 0 a 5. Em seguida, o método "avaliarFilme" é chamado a
 * partir do objeto "CineMax", utilizando esses parâmetros.
*/

            case 'P': {                               
                switch (comando[1]) {

                    case 'A': {
                        
                        cout << endl <<"AVALIAR FILME" << endl;

                        cout << "Digite o ID do filme a ser avaliado:" << endl;
                        int id;
                        cin >> id;
                        cout << "Digite a nota do filme, de 0 a 5:" << endl;
                        float nota;
                        cin >> nota;
                    
                        CineMax.avaliarFilme(id,nota);

                        break;
                    }

/**
 * @details Caso o comando digitado seja "PS" (sugerir filmes), é solicitado ao usuário o cpf do cliente que busca recomendações.
 * Em seguida, o método "recomendarFilmes" é chamado a partir do objeto "CineMax", utilizando esse parâmetro.
*/                   
                    case 'S': {
                        
                        cout << endl <<"SUGERIR FILMES" << endl;

                        cout << "Digite o CPF do cliente que busca recomendações:" << endl;
                        long long cpf;
                        cin >> cpf;

                        CineMax.recomendarFilmes(cpf);

                        break;
                    }

                    default: {
                        printColoredText("Comando Inválido!\n", 31);
                        break;
                    }
                }
                break;
            }

/**
 * @details Caso o comando "FS" (finalizar sistema) seja digitado, o programa é encerrado.
*/

            case 'F': { 
                switch (comando[1]) {

                    case 'S': {

                        cout << "Você tem certeza que deseja encerrar o programa?" << endl;
                        cout << "-> Digite S para encerrar!" << endl;
                        cout << "-> Digite N para cancelar o encerramento!" << endl;

                        char comandoEncerra;
                        cin >> comandoEncerra;

                        if (comandoEncerra == 'S'){

                            cout << endl << "Programa encerrado!" << endl;
                            cout << "Até Logo !";
                            printColoredText("  :)\n", 33);
                            
                        return 0;
                        }
                        if (comandoEncerra == 'N') {
                            continue;
                        } 

                    break;
                    }
            
                    default: {
                        printColoredText("Comando Inválido!\n", 31);
                        break;
                    }

                }
                default:
                printColoredText("Comando Inválido!\n", 31);
                break;
            }
        
        }
        
    }

    return 0;
}