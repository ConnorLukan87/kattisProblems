#include <math.h>
#include <vector>
#include <cstdint>
#include <iostream>

void get_factors( unsigned int n, std::vector<unsigned int>& holder )
{
    holder.clear() ;

    unsigned int upper_limit = (int) sqrt( n ) ;
    for( unsigned int i = 1 ; i <= upper_limit ; ++i )
    {
        if( n % i == 0 )
        {
            holder.push_back( i ) ;
            if( i > 1 && i != n / i  && i * i != n )
                holder.push_back( n / i ) ;
        }
    }
}

unsigned int sum_of( std::vector<unsigned int>& list )
{
    unsigned int output = 0 ;
    for( auto& n : list )
        output += n ;
    return output ;
}

int main()
{
    std::vector<unsigned int> holder ;
    holder.reserve(1000) ;

    unsigned int p ;
    while( true )
    {
        std::cin >> p ;

        if( std::cin.eof() )
            break ;

        get_factors( p, holder ) ;
        auto s = sum_of( holder ) ;
        if( p == s )
        {
            std::cout << p << " perfect" << std::endl ;
        }
        else
        {
            bool almost = ( p > s ? p - s : s - p ) <= 2 ;
            if( almost )
                std::cout << p << " almost perfect" << std::endl ;
            else
                std::cout << p << " not perfect" << std::endl ;
        }
    }

    return 0 ;
}
