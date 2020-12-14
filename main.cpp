#include <stdlib.h>
#include <iostream>
#include <complex>
#include <limits>
#include <map>

int main()
{
    long mask = 0;
    long mask_val = 0;

    std::map<long,long> mem;

    for (;;)
    {
        std::string token;
        std::cin >> token;
        if (std::cin.eof())
            break;
        if (token=="mask")
        {
            mask = 0;
            mask_val = 0;
            std::cin >> token;  //  =
            std::cin >> token;
            for (auto c:token)
            {
                // std::cout << mask << " ";
                // std::cout << c;
                mask <<= 1;
                mask_val <<= 1;
                if (c=='X')
                    mask |= 1;
                // if (c=='0')
                if (c=='1')
                    mask_val |= 1;                
            }
        }
        else if (token=="mem")
        {
            char c;
            long adrs;
            long value;
            std::cin >> c;
            std::cin >> adrs;
            std::cin >> c;
            std::cin >> token;  //  =
            std::cin >> value;
            // printf( "mem[%ld] = %ld [%0lx %0lx]\n", adrs, value, mask, mask_val );
            // std::cout << adrs << " = " << value << " MASK " << mask << " MVAL=" << mask_val << "\n";
            mem[adrs] = (value & mask) + mask_val;
        }
    }

    long total = 0;
    for (auto [k,v] : mem)
        total += v;

    std::cout << total << std::endl;

    return EXIT_SUCCESS;
}
