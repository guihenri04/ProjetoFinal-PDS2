#ifndef BANCO_H                  //entender isso 
#define BANCO_H

#include <string>
#include <iostream>
#include <iomanip>
#include "ContaBancaria.hpp"

class Banco 
{
    public:

    int contas;
    Banco();
    ContaBancaria* vetor[20];
    ContaBancaria* CriaConta(ContaBancaria);
    ContaBancaria* Pesquisa(int);
    void ListaContas();
};

#endif