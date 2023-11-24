#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>


class logins 
{
    public:
    std::vector<std::string> usuarios;
    int numeroLogins;
    
};

 
int main ()
{

    logins registro;
    std::string usuarioOuComando;

    std::map<int,logins> dias;
    int dia = 1;

    registro.numeroLogins = 0;

    bool fimDeEntrada = false;

    while (true) 
    {
        std::cin >> usuarioOuComando;

        if (usuarioOuComando == "END")
        {
        registro.usuarios.clear();
        registro.numeroLogins = 0;
        fimDeEntrada = true;
        }

    
        if (fimDeEntrada) 
        {
        
        dias[dia] = registro;
        dia++;
        registro.usuarios.clear();
        registro.numeroLogins = 0;
        }
    
        if (fimDeEntrada) 
        {
        break;
        }


        if (usuarioOuComando == "DEL")
        {
            if (usuarioOuComando == "DEL" && !fimDeEntrada) 
            {
            registro.usuarios.clear();
            registro.numeroLogins = 0;
             
            }
            continue;
        }
            

        if (usuarioOuComando == "LOG") 
        {
        
            if (registro.numeroLogins > 0) 
            {
            dias[dia] = registro;
            dia++;
            registro.usuarios.clear();
            registro.numeroLogins = 0;
            }
            continue;
        } 
        
        if(usuarioOuComando == "CLS") 
        {
            for (auto& kpar : dias) 
            {
                kpar.second.usuarios.clear();
                kpar.second.numeroLogins = 0;
            }
            registro.usuarios.clear();  
            registro.numeroLogins = 0;
            dia=1;
            continue;
          
        }

        else 
        {
        
        registro.usuarios.push_back(usuarioOuComando);
        registro.numeroLogins++;
        }
    }
            

        



    
for (const auto& parKey : dias) 
{
    int dia = parKey.first;
    const logins& registroDia = parKey.second;

    std::cout <<  dia << " " << registroDia.numeroLogins;

    for (const std::string& usuario : registroDia.usuarios) 
    {
        std::cout << " " << usuario;
    }

    std::cout << std::endl;
}
    
 

return 0;
}