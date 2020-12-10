#include <stdlib.h>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std::string_literals;

static std::vector<long long> memo;

template <typename IT> long long count_possibilities( int current, IT b, IT e )
{
    int n = e-b;
    while (memo.size()<=n)
        memo.push_back( 0 );
    if (memo[n]!=0)
        return memo[n];

    if (b==e)
        return 1;
    long long total = 0;
    
    while (b!=e)
    {
        if (*b<=current+3)
            total += count_possibilities( *b, b+1, e );
        else
            break;
        b++;
    }

    memo[n] = total;

    return total;
}

int main()
{
    std::vector<int> data;

    while (!std::cin.eof())
    {
        int long n;
        std::cin >> n;
        if (!std::cin.eof())
            data.push_back( n );
    }

    std::cout << count_possibilities( 0, std::begin(data), std::end(data) ) << "\n";

    return EXIT_SUCCESS;
}
