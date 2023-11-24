#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class ContaBancaria 
{
    public:  

    int id;
    std::string cliente;
    double saldo ;
    ContaBancaria(int, std::string&, double);
    void deposito (double);
    void saque (double);
    void pix (ContaBancaria&, double);
    void imprime ();

};

#endif


