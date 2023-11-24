#include <iostream>
#include <vector>
#include <algorithm>




int main ()
{
    std::vector<int> conjunto1;
    int elementosConjunto1;
    
    while (true)
    {
        std::cin >> elementosConjunto1;
        
            if(elementosConjunto1 < 0)
            {
            break;
            }

        conjunto1.push_back(elementosConjunto1);
    }
    
    std::sort (conjunto1.begin(), conjunto1.end());

    std::vector<int> conjunto2;
    int elementosConjunto2;
    
    while (true)
    {
        std::cin >> elementosConjunto2;
        
            if(elementosConjunto2 < 0)
            {
            break;
            }

        conjunto2.push_back(elementosConjunto2);
    }
    
    std::sort (conjunto2.begin(), conjunto2.end());


    for(const int &n1 : conjunto1)
    {
        std::cout << n1 << " ";
    }
    std::cout << std::endl;
                                            
    for(const int &n2 : conjunto2)
    {
        std::cout << n2 << " ";
    }
    std::cout << std::endl;

    
    std::vector<int> uniao;
    std::set_union(conjunto1.begin(), conjunto1.end(), conjunto2.begin(), conjunto2.end(), std::back_inserter(uniao));

    for(const int &u : uniao)
    {
        std::cout << u << " ";
    }
    std::cout << std::endl;

    std::vector<int> intersecao;
    std::set_intersection(conjunto1.begin(), conjunto1.end(), conjunto2.begin(), conjunto2.end(), std::back_inserter(intersecao));

     for(const int &i : intersecao)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;


return 0;
}
