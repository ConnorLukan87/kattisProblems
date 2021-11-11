#include <iostream>
#include <iomanip>

int main()
{
  double n;
  std::cin >> n;
  if (n==0) {
    std::cout << 1; return 0;
  }
  double sum = 1; 
  double factoflast = 1;
  for (int i=1;i<=n;i++)
  {
    factoflast *= (double)i;
    sum += 1/(factoflast);
    
  }
  std::cout << std::setprecision(15) << std::fixed << sum;
}
