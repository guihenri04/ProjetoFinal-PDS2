#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
void concatString (char szTarget [], const char szSource [])
{
    int targetIndex = 0;
    while (szTarget[targetIndex])
    {
        targetIndex++;
    }

    int sourceIndex = 0;
    while (szSource[sourceIndex])
    {
        szTarget[targetIndex] = szSource[sourceIndex];
        targetIndex++;
        sourceIndex++;
    }

    szTarget [targetIndex] = '\0';
}

int main ()
{
    char szString1[256];
    cout << "Enter the 1st string: ";
    cin.getline(szString1, 128);

    char szString2[128];
    cout << "Enter the 2nd string: ";
    cin.getline(szString2, 128);                       //getline faz a leitura da linha inteira interagindo com spaces

    concatString (szString1, " - ");

    concatString (szString1, szString2);

    cout << "\n" << szString1 << endl;
}
