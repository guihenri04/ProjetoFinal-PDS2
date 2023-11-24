#include <math.h>
#include <iostream>
#include <string>


using namespace std;

int main()
{

   string szpalavra1;
   string szpalavra2;

   getline(cin, szpalavra1);
   getline(cin, szpalavra2);

   int comprimento;

   for(int i = 0; i <= szpalavra1.length(); i++)
   {
      comprimento = i;
   }
   
   while(szpalavra2.length() <= comprimento)
   {
      szpalavra2 += szpalavra2;
   }

   if(szpalavra2.length() > comprimento)
   {
      szpalavra2 = szpalavra2.substr(0, comprimento);
   }
   
  string cripto = szpalavra2;

   for(int i = 0; i < comprimento; i++)
   {
       if(szpalavra1[i] + szpalavra2[i] <= 186 && 32 <= szpalavra1[i] <= 64)
         cripto[i] = szpalavra1[i];

      else if(szpalavra1[i] + szpalavra2[i] <= 219)
         cripto[i] = (szpalavra1[i] + szpalavra2[i]) - 97;
       
      else if(szpalavra1[i] + szpalavra2[i] >= 220)
         cripto[i] = (szpalavra1[i] + szpalavra2[i]) - 123;

   }

   cout << szpalavra1 <<"\n";
   cout << cripto;

}