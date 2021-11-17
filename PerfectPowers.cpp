#include <iostream>
#include <cmath>

int main()
{
  long long x;
  const double error = 0.0001;
  while (true)
  {
    std::cin >> x;
    if (x==0) break;
    double b;
    for (long long power=31;power>0;power--)
    {
      b = std::pow(std::abs(x),1.0/(double)power);
      if (std::ceil(b)-b < error)
      {
        if (std::pow(std::ceil(b),power)==std::abs(x) && (x>0 || power%2!=0))
        {
          std::cout << power << std::endl;
          break;
        }
      }
      else if (b-std::floor(b)<error)
      {
        if (std::pow(std::floor(b),power)==std::abs(x) && (x>0 || power%2!=0))
        {
          std::cout << power << std::endl;
          break;
        }
      }
      
    }
   
  }
  return 0;
}
