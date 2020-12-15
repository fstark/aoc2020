#include <stdlib.h>
#include <iostream>
#include <complex>
#include <limits>
#include <map>

int main()
{
    long mask = 0;
    long mask_val = 0;
    long keep = 0;

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
            keep = 0;
            std::cin >> token;  //  =
            std::cin >> token;
            for (auto c:token)
            {
                // std::cout << mask << " ";
                // std::cout << c;
                mask <<= 1;
                mask_val <<= 1;
                keep <<= 1;
                if (c=='X')
                    mask |= 1;
                if (c=='0')
                    keep |= 1;
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
            // mem[adrs] = (value & mask) + mask_val;
            // std::cout << "KEEP=" << keep << "\n";
            // std::cout << "MVAL=" << mask_val << "\n";
            // std::cout << "ADRS=" << adrs << "\n";
            adrs = (adrs & keep) | mask_val;
            // std::cout << "ADRS=" << adrs << "\n";
            for (int i=0;i!=512;i++)
            {
                long real_adrs = adrs;
                long p = 0;
                long ii = i;
                for (int j=0;j!=36;j++)
                    if (mask&(1L<<j))
                    {
                        real_adrs &= ~(1L<<j);
                        if (ii&1)
                            real_adrs |= (1L<<j);
                        ii>>=1;
                        p++;
                    }
                mem[real_adrs] = value;
                // printf( "mem[%lx] = %ld\n", real_adrs, value );
            }
        }
    }

    long total = 0;
    for (auto [k,v] : mem)
        total += v;

    std::cout << total << std::endl;

    return EXIT_SUCCESS;
}
