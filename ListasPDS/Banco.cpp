#include "ContaBancaria.hpp"
#include "Banco.hpp"

    Banco::Banco()
    {
        contas = 0;
        for (int i= 0; i < 20; i++)
        {
        vetor [i] = nullptr;
        }
    }   

    ContaBancaria* Banco::Pesquisa(int id) 
    {
        for (int i = 0; i < 20; i++) 
        {
            if (vetor[i] != nullptr && vetor[i]->id == id) 
            {
            return vetor[i];
            }
        }
    return nullptr; 
    }  
        
    ContaBancaria* Banco::criaConta (ContaBancaria a)
    {
        
        if (Pesquisa(a.id) != nullptr) 
        {
        return nullptr; 
        }

        ContaBancaria* novaConta = new ContaBancaria(a.id, a.cliente, a.saldo);
        vetor[contas] = novaConta;
        contas++;
        return novaConta;
    }

    void Banco::ListaContas()
    {
        for(int i=0; i<20; i++)
        {
            if (vetor[i] != nullptr) 
            vetor[i]->imprime();   
        }
    }
    

    
