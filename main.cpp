#include <stdlib.h>
#include <iostream>
#include <complex>
#include <limits>

int main()
{
    int time;
    std::cin >> time;

    time--;

    int min_time = std::numeric_limits<int>::max();
    int min_n;

    for (;;)
    {
        int n;
        std::cin >> n;
        if (std::cin.eof())
            break;
        if (n==0)
            continue;
        int t = time+(n-(time%n));
        if (t<min_time)
        {
            min_time = t;
            min_n = n;
        }
    }

    std::cout << (min_time-time-1)*min_n << std::endl;

    return EXIT_SUCCESS;
}
