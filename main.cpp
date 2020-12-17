#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <array>

int main()
{
    const int SIZE = 101;
    const int MIN = -SIZE/2;
    const int MAX = (SIZE+1)/2;
    const int ISIZE = 8;
    const int IMIN = -ISIZE/2;
    const int IMAC = (ISIZE+1)/2;

    const int MID = SIZE/2;

    static std::array<std::array<std::array<bool,SIZE>,SIZE>,SIZE> cells;

    char c;

    for (int x=0;x!=ISIZE;x++)
        for (int y=0;y!=ISIZE;y++)
        {
            std::cin >> c;
            cells[y+MID+IMIN][x+MID+IMIN][MID] = c=='#';
            // std::cout << x+MID+IMIN << " " << y+MID+IMIN << " " << MID << " = " << cells[x+MID+IMIN][y+MID+IMIN][MID] << "\n";
        }

//    for (;;)
    for (int k=0;k!=6;k++)
    {
        auto next = cells;

        // std::cout << "------------\n";
        // for (int z=0;z!=SIZE;z++)
        // {
        //     std::cout << "z = " << z+MIN << "\n";
        //     for (int y=0;y!=SIZE;y++)
        //     {
        //         for (int x=0;x!=SIZE;x++)
        //             std::cout << (cells[x][y][z]?'#':'.');
        //         std::cout << "\n";
        //     }
        // }        

        for (int x=1;x!=SIZE-1;x++)
            for (int y=1;y!=SIZE-1;y++)
                for (int z=1;z!=SIZE-1;z++)
                {
                    int count = 0;
                    for (int dx=-1;dx!=2;dx++)
                        for (int dy=-1;dy!=2;dy++)
                            for (int dz=-1;dz!=2;dz++)
                                if (dx || dy || dz)
                                    count += cells[x+dx][y+dy][z+dz];
                    // std::cout << "@"<<x<<y<<z<<":"<<count<<" ";
                    if (cells[x][y][z])
                        next[x][y][z] = count==2 || count==3;
                    else
                        next[x][y][z] = count==3;
                }

        if (next==cells)
            break;
        cells = next;
    }

    int count = 0;

    for (int x=0;x!=SIZE;x++)
        for (int y=0;y!=SIZE;y++)
            for (int z=0;z!=SIZE;z++)
                count += cells[x][y][z];

    std::cout << count << "\n";

    return EXIT_SUCCESS;
}
