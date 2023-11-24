#include <iostream>
#include <math.h>

using namespace std;

void calculamedia (int &v) // esse eh um caso em que a pssagem por valor nao altera o resutado: retire o "&" e de run.
{       
    cout << "Digite os algarismos que deseja utilizar no seu cálculo: " << endl;

    float* vetor = new float [v];       // vetor de tamanho v inteiro declarado na main
    for (int i=0; i<v ;i++) {           // atribui valores float ao vetor, lembrar que vetor [2], i=0 i=1  
        cin >> vetor [i];
    }
    
    float somavetor = 0;            // calcular media de quaisquer valores atribuidos com somatorio
    for (int i=0; i<v ;i++) {
        somavetor += vetor[i];      // += : somavetor = somavetor + vetor[i], faz o looping e manda pra float somavetor
    }    

    float media = somavetor/v;

    cout << "A média desses algarismos é: " << media << endl;
    
    float somaDoDesvio=0;               //receptor da soma do looping

    for (int i=0; i<v; i++) {
        somaDoDesvio += (pow((vetor[i]-media),2));    //operaçao do somatorio do desvio padrão
    }

    float desvioP = sqrt(somaDoDesvio/v);
    
    cout << "O desvio padrão desses algarismos é: " << desvioP << endl;       

}

int main () {

    cout << "Digite o número de algarismos que deseja utilizar: " << endl;

    int v;
    cin >> v;
    calculamedia (v);

    return 0;
}