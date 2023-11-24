#include <iostream>

using namespace std;

int main(){
    
    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada

    int nvar;

    cin >> nvar; 
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    
    int* npoint = nullptr;
    
    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada

    int vetor;
    cin >> vetor;
    int*  datavetor = new int [vetor];      
    for (int i=0; i<vetor ;i++) 
    {            
        cin >> datavetor [i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    
    cout << &nvar << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    
    cout << nvar << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    
    cout << &npoint << endl; 

    // 7) Imprima o VALOR da variável declarada em (2)

    cout << npoint << endl;   

    // 8) Imprima o ENDEREÇO da variável declarada em (3)

    cout << &datavetor << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)

    cout << &datavetor [0] << endl;
    
    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    
    cout << datavetor [0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)   
    
    npoint = &nvar;

    // 12) Imprima o VALOR da variável declarada em (2)
    
    cout << npoint << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
    cout << *npoint << endl;

    // 14) Compare ENDEREÇO de (1) e o VALOR de (2), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    
    if (&nvar == npoint) 
    {
        cout << 'S' << endl;
    }
    else 
    {
        cout << 'N' <<endl;
    }

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    
    *npoint = 5;
    
    // 16) Imprima o VALOR da variável declarada em (1)

    cout << nvar << endl;
    
    // 17) Atribua o VALOR da variável (3) à variável declarada em (2)
    
    npoint = datavetor;

    // 18) Imprima o VALOR da variável declarada em (2)
    
    cout << npoint << endl;

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)

    cout << *npoint << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    
    npoint = &datavetor[0];

    // 21) Imprima o VALOR da variável declarada em (2)
    
    cout << npoint << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
    cout << *npoint << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    
    for (int i = 0; i < vetor; i++ )
    {
        *(npoint+i) = (*(npoint + i)) * 10; 
    }
    
    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    
    for (int i = 0; i < vetor; i++) 
    {
        if(vetor == i+1)
        cout << datavetor[i] << endl;
        else
        cout << datavetor[i] << ' ';  
    }

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    
    for (int i = 0; i < vetor; i++) 
    {
        if(vetor == i+1)
        cout << *(datavetor+i) << endl;
        else
        cout << *(datavetor+i) << ' ';
    }

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    
    for (int i = 0; i < vetor; i++) 
    {
        if(vetor == i+1)
        cout << *(npoint+i) << endl;
        else 
        cout << *(npoint+i) << ' ';
    }

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    
    npoint = &datavetor[4];

    // 28) Imprima o VALOR da variável declarada em (2)
    
    cout << npoint << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
    cout << *npoint << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    
    int** pointfptr = &npoint; 

    // 31) Imprima o VALOR da variável declarada em (30)
    
    cout << pointfptr << endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    
    cout << &pointfptr << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    
    cout << *pointfptr << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    
    cout << **pointfptr << endl;

    return 0;
}
