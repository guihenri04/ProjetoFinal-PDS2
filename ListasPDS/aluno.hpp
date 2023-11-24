#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>

#ifndef ALUNO_H
#define ALUNO_H

struct Aluno
{
   
    
    std::string nome;
    int matricula;
    std::vector<int> notas;

    Aluno(std::string,int, std::vector<int>); 

    void CalculaMedia();
    void NotaMaxima();
    void DisplayDados();

};

#endif