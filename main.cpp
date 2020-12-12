#include <stdlib.h>
#include <iostream>
#include <complex>

using namespace std::complex_literals;

int main()
{
    static const char *direction_names = "ESWN";
    static const std::complex<int> directions[] = { 1, -1i, -1, 1i };
    int d = 0;
    std::complex<int> p;
    for (;;)
    {
        char c;
        int n;
        std::cin >> c >> n;
        if (std::cin.eof())
            break;
        if (c=='F') p += directions[d]*n;
        else if (c=='R' || c=='L') d = (d+((c=='R')-(c=='L'))*n/90+4)%4;
        else p += directions[::strchr( direction_names, c )-direction_names]*n;
    }

    std::cout << ::fabs( std::real(p) ) + ::fabs( std::imag(p) ) << std::endl;

    return EXIT_SUCCESS;
}
