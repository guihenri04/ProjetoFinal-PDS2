#include "aluno.hpp"

Aluno::Aluno(std::string nome_, int matricula_, std::vector<int> notas_) {
    nome=nome_;
    matricula=matricula_;
    notas=notas_;
}
   
   
   

void Aluno::CalculaMedia() 
{
    int auxsoma = 0;
    for (size_t i = 0; i < notas.size(); i++)
    {
        auxsoma += notas[i];
    }
    float media = (auxsoma/notas.size());   
    std::cout << std::fixed << std::setprecision(2);
    std::cout << media << " ";
}

void Aluno::NotaMaxima() 
{
    auto maxNota = std::max_element(notas.begin(), notas.end());
    int maiornota = *maxNota;
    std::cout << maiornota << std::endl;
}

void Aluno::DisplayDados() 
{
    
    std::cout <<  matricula << " " <<  nome;
    for (int nota : notas)
    {
        std::cout << " " << nota;
    }
    std::cout << std::endl;
}
