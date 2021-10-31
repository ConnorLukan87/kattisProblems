#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct interval
{
  int min, max;
};

bool sharesPrimeFactor(std::vector<int> &primeFactors, int p1, int p2)
{
  bool shares = false;
  for (int &prime : primeFactors)
  {
    if ((p1%prime==0)&&(p2%prime==0))
    {
      shares = true;
      break;
    }
  }
  return shares;
}

void sievePrimes(std::vector<bool> &markers, int max)
{
    int upperLimit = (int)sqrt(max);
    for (int p=2; p<=upperLimit; p++)
    {
        if (markers.at(p))
        {
            for (int i=p*p;(i<=max);i+=p)
            {
                markers.at(i)=false;
            }
        }
    }
}

void getPlayablePrimes(std::vector<int> &primeFactors, int max)
{
  std::vector<bool> markers(max+1);
  markers.flip();
  markers.at(0)=false;
  markers.at(1)=false;
  sievePrimes(markers,max);
  int n = 0;
  for (auto is: markers)
  {
    if (is)
    {
      primeFactors.push_back(n);
    }
    n++;
  }
}

int main()
{
  interval f,g;
  std::cin >> f.min >> f.max >> g.min >> g.max;
  int count=0;
  interval restrictingMaxInterval, absoluteMaxInterval;
  if (g.max<f.max)
  {
    restrictingMaxInterval = g;
    absoluteMaxInterval = f;
  }
  else
  {
    restrictingMaxInterval = f;
    absoluteMaxInterval = g;
  }
  std::vector<int> primeFactors;
  int sz = (int)((double)restrictingMaxInterval.max/(log((double)restrictingMaxInterval.max)));
  primeFactors.reserve(sz);
  getPlayablePrimes(primeFactors, restrictingMaxInterval.max);
  for (int pos=absoluteMaxInterval.min;pos<=absoluteMaxInterval.max;pos++)
  {
    if (pos==1)
    {
      count += 1+restrictingMaxInterval.max-restrictingMaxInterval.min;
      continue;
    }
    for (int pos2=restrictingMaxInterval.min;pos2<=restrictingMaxInterval.max;pos2++)
    {
      
      if (((pos%pos2==0)||(pos2%pos==0))&&(pos2!=1)) 
      {
        continue;
      }
      else if (sharesPrimeFactor(primeFactors,pos,pos2))
      {
        continue;
      }
      else
      {
        count++;
      }
    } 
  }
  std::cout << count;
  
}
