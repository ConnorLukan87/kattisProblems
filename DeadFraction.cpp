#include <iostream>
#include <string>
#include <algorithm>

unsigned int gcd(unsigned int n, unsigned int d) 
{return ((n%d==0) ? d : gcd(d,n%d));}

unsigned int pow10(int exponent)
{
  unsigned int t = 1;
  for (int i=0;i<exponent;i++)
  {
    t *= 10;
  }
  return t;
}

int main()
{
  std::string s; std::cin >> s;
  while (s.length()!=1)
  {
    std::reverse(s.begin(),s.end());
    unsigned int i=4, n = 0;
    while (s[i]!='.')
    {
      n += pow10(i-4)*(s[i]-'0');
      i++;
    }
    n = (n*9) +(s[3]-'0');
    unsigned int d = 9*pow10(i-4);
    unsigned int f = gcd(n,d);
    n = n/f;
    d = d/f;
    std::cout << n << "/" << d << std::endl;
    std::cin >> s;
  }
}
