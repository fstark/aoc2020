#include <stdlib.h>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std::string_literals;

//  I am deeply ashamed of this code

const int W = 95;
const int H = 99;
// const int W = 10;
// const int H = 10;

std::array<std::array<int,W>,H> room;
std::array<std::array<int,W>,H> room2;

int count_seats( int x0, int y0 )
{
    int count = 0;
    for (int dx=-1;dx!=2;dx++)
        for (int dy=-1;dy!=2;dy++)
            if (dx!=0 || dy!=0)
            {
                bool found = false;
                for (int d=1;d!=W+H;d++)
                {
                    int x = x0+dx*d;
                    int y = y0+dy*d;
                    if (x>=0 && x<W && y>=0 && y<H)
                        if (room[y][x]==0)
                        {
                            break;
                        }
                        else if (room[y][x]==1)
                        {
                            found = true;
                            break;
                        }
                }
                count += found;
            }
    return count;
}

int main()
{

    for (int y=0;y!=H;y++)
        for (int x=0;x!=W;x++)
        {
            while (true)
            {
                int c = getchar();
                if (c=='L')
                    room[y][x] = 0;    // free
                else if (c=='.')
                    room[y][x] = -1;   //  floor
                else
                    continue;
                break;
            }
        }

    // for (int y=0;y!=H;y++)
    // {
    //     for (int x=0;x!=W;x++)
    //         std::cout << (room[y][x]==1?'#':(room[y][x]==-1?'.':'L'));
    //     std::cout << "\n";
    // }
    // std::cout << "\n";


    while (true)
    {
        for (int y=0;y!=H;y++)
            for (int x=0;x!=W;x++)
            {   
                int count = count_seats( x, y );
                room2[y][x] = room[y][x];
                if (room[y][x]==0)
                    room2[y][x] = count==0?1:0;
                if (room[y][x]==1)
                    room2[y][x] = count>=5?0:1;
            }
        if (room==room2)
            break;
        room = room2;

        // for (int y=0;y!=H;y++)
        // {
        //     for (int x=0;x!=W;x++)
        //         std::cout << (room[y][x]==1?'#':(room[y][x]==-1?'.':'L'));
        //     std::cout << "\n";
        // }
        // std::cout << "\n";


    }

    int total = 0;
    for (int y=0;y!=H;y++)
        for (int x=0;x!=W;x++)
            total +=room[y][x]==1;

    std::cout << total << "\n";

    return EXIT_SUCCESS;
}
