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
    int current = 0;
    int n1 = 0;
    int n3 = 1;

    while (!std::cin.eof())
    {
        long long n;
        std::cin >> n;
        int diff = n-current;
        if (diff==1)
            n1++;
        if (diff==3)
            n3++;
        // std::cout << current << " + " << n-current << " => " << n << "\n";
        current = n;
    }

    std::cout << n1 * n3 << "\n";

    return EXIT_SUCCESS;
}
