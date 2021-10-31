#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

void sievePrimes(std::vector<bool> &markers, unsigned int max)
{
    unsigned int upperLimit = (unsigned int)sqrt(max);
    for (unsigned int p=2; p<=upperLimit; p++)
    {
        if (markers.at(p))
        {
            for (unsigned int i=p*p;(i<=max);i+=p)
            {
                markers.at(i)=false;
            }
        }
    }
}

int main()
{
    unsigned int max, trials;
    std::cin >> max >> trials;
    std::vector<bool> markers (max+1);
    for (unsigned int i=2;i<=max;i++)
    {
        markers.at(i)=true;
    }
    sievePrimes(markers,max);
    std::vector<unsigned int> solutions;
    solutions.push_back(std::count(markers.begin(),markers.end(),true));
    unsigned int test;
    for (unsigned int i=0; i<trials;i++)
    {
        std::cin >> test;
        solutions.push_back(markers.at(test));
    }
    for (auto s : solutions)
    {
        std::cout << s << std::endl;
    }
}
