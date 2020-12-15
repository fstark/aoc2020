#include <stdlib.h>
#include <iostream>
#include <array>

int main()
{
    // std::array<int,2020> spoken = { 0,3,6 };
    std::array<int,2020> spoken = { 1,12,0,20,8,16 };


    int delta = 0;

    for (int i=6;i!=2020;i++)
    {
        delta = 0;
        int last = spoken[i-1];
        for (int j=i-2;j>=0;j--)
            if (spoken[j]==last)
            {   delta = i-j-1;
                break;
            }

        // std::cout << "[";
        // for (int n=0;n!=i;n++)
        //     std::cout << spoken[n] << " ";
        // std::cout << "] ";

        // std::cout << i << " v=" << last << " delta=" << delta << "\n";
        spoken[i] = delta;
    }

    std::cout << delta << std::endl;

    return EXIT_SUCCESS;
}
