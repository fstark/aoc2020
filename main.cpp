#include <stdlib.h>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std::string_literals;

int main()
{
    const int S = 25;

    std::vector<long long> data;

    data.push_back( 0 );

    for (int i=0;i!=S;i++)
    {
        long long n;
        std::cin >> n;
        data.push_back( n );
    }

    loop:
    data.erase(std::begin(data));
    long long n;
    std::cin >> n;
    data.push_back( n );
    for (int i=0;i!=S;i++)
        for (int j=0;j!=S;j++)
            if (i!=j && data[i]+data[j]==n)
                goto loop;

    std::cout << n << "\n";

    return EXIT_SUCCESS;
}
