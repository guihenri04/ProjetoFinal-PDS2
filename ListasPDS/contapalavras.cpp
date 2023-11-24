#include <iostream>
#include <string>
#include <map>
#include <sstream>


bool ehAlfa(char c) 
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}


std::string converteMinusculo(const std::string &palavra) 
{
    std::string minusculo = palavra;
    for (char &c : minusculo) 
    {
        if (c >= 'A' && c <= 'Z') 
        {
            c = c - 'A' + 'a';
        }
    }
    return minusculo;
}

int main() 
{
    
    std::string armazenatexto;
    std::getline(std::cin, armazenatexto);

    
    std::map<std::string, int> contaPalavra;

    
    std::string palavra = "";
    std::stringstream ss(armazenatexto);
    std::string separa;

    while (ss >> separa) 
    {
        for (char c : separa) 
        {
            if (ehAlfa(c)) 
            {
                
                palavra += c;
            } 
            else 
            {
                
                if (!palavra.empty()) 
                {
                    
                    std::string minusculo = converteMinusculo(palavra);
                    
                    contaPalavra[minusculo]++;
                    palavra = "";
                }
            }
        }
       
        if (!palavra.empty()) 
        {
           
            std::string minusculo = converteMinusculo(palavra);
            
            contaPalavra[minusculo]++;
            palavra = "";
        }
    }

    
    for (const auto &pair : contaPalavra) 
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}
