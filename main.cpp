#include <stdlib.h>
#include <iostream>
#include <complex>

using namespace std::complex_literals;

int main()
{
    static const char *direction_names = "ENWS";
    std::complex<double> p;
    std::complex<double> w = 10.+1i;
    for (;;)
    {
        char c;
        double n;
        std::cin >> c >> n;
        if (std::cin.eof())
            break;
        if (c=='F') p += w*n;
        else if (c=='R' || c=='L') w *= std::pow( ((c=='L')-(c=='R'))*1.*1i, n/90 );
        else w += std::pow( 1i, (::strchr( direction_names, c )-direction_names) )*n;
    }

    std::cout << ::fabs( std::real(p) ) + ::fabs( std::imag(p) ) << std::endl;

    return EXIT_SUCCESS;
}
