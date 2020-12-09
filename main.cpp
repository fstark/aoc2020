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
    const int N = 15690279;

    std::vector<long long> data;

    while (1)
    {
        long long n;
        std::cin >> n;
        data.push_back( n );
        long long total = 0;
        for (int i=data.size()-1;i>=0;i--)
        {
            total += data[i];
            if (total==N)
            {
                std::cout << *std::min_element( std::begin(data)+i, std::end(data) ) + *std::max_element( std::begin(data)+i, std::end(data) ) << "\n";
                return 0;
            }
        }
    }

    return EXIT_SUCCESS;
}
