#include <stdlib.h>
#include <iostream>
#include <array>

int main()
{
    // const int LEN = 30000000;
    const int LEN = 30000000;
    const int INPUT = 6;

    static std::array<int,INPUT> data = { 1,12,0,20,8,16 };
    static std::array<int,LEN> last_used_index;

    // static std::array<int,LEN> expected = { 0, 3, 6, 0, 3, 3, 1, 0, 4, 0};


    last_used_index.fill( -1 );

    for (int i=0;i!=INPUT-1;i++)
    {
        last_used_index[data[i]] = i;
    }
    int last = data[INPUT-1];
    int index = INPUT;

    while (index<LEN)
    {
        // for (int i=0;i!=10;i++)
        //     std::cout << i << "/" << last_used_index[i] << " ";
        // std::cout << "\n";

        //  Where did we last saw last?
        int previous = last_used_index[last];
        // std::cout << index << ": last=" << last << " used at=" << previous;

        last_used_index[last] = index-1;
        index++;
        if (previous==-1)
        {
            //  Never, so we now have last == 0
            last = 0;
        }
        else
        {
            last = index-previous-2;
        }

        // std::cout << " => " << last << "/" << expected[index-1] << "\n";
    }

    std::cout << last << "\n";

    return EXIT_SUCCESS;
}
