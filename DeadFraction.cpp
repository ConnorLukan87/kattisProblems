#include <iostream>
#include <string>
#include <cmath>

long gcd(long n, long d) { return (n%d==0) ? d : gcd(d,n%d);}

int main()
{
  std::string digits;
  std::cin >> digits;
  while (digits.length()!=1)
  {
    digits = digits.substr(2,digits.length()-5);
    int c = 1; 
    std::string m;
    long best_n=0, best_d = 999999999;
    for (int j=digits.length()-1; j>=0; --j,++c)
    {
      m = digits.substr(j,digits.length());
      long current_d = pow(10,j)*(pow(10,c)-1), current_n =0;
      for (int i=j;i>0;i--)
      {
        current_n += (digits[i-1]-'0')*pow(10,j-i);
      }
      current_n = (current_n)*(pow(10,c)-1) + atol(m.c_str());
      long gcf = gcd(current_n,current_d);
      current_d = current_d/gcf;
      if (current_d<best_d)
      {
        best_n = current_n/gcf;
        best_d = current_d;
      }
    }
    std::cout << best_n << "/" << best_d << std::endl;
    std::cin >> digits;
  }
}
