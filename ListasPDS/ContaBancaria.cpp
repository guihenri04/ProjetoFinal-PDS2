#include "ContaBancaria.hpp"
     
    ContaBancaria::ContaBancaria (int nid, std::string& ncliente, double nsaldo)
    {
    id = nid;
    cliente = ncliente;
    saldo = 0;
    }

    void ContaBancaria::deposito (double valorDeposito)
    {
        saldo += valorDeposito;
    }

    void ContaBancaria::saque (double valorSaque)
    {
        saldo -= valorSaque;
    }

    void ContaBancaria::pix (ContaBancaria& receptor, double valorPix)
    {
        receptor.saldo += valorPix;
        this->saldo -= valorPix;
    }

    void ContaBancaria::imprime ()
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << this->id << ' ' << this->cliente << ' '  << this->saldo << std::endl;
    } 


    







