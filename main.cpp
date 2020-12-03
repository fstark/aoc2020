#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

const int W = 31;
const int H = 323;

char data[W][H];

int count_trees( int w, int h )
{
    int total = 0;
    int i=0;
    int x=0;
    for (int i=0;i<H;i+=h)
    {
        total += data[x][i]=='#';
        x += w;
        x %= W;
    }
    return total;
}

int main()
{
    for (int y=0;y!=H;y++)
        for (int x=0;x!=W;x++)
        {
            int c;
            do
            {
                c = getchar();
                data[x][y] = c;
            }   while (c!='.' && c!='#');
        }

    printf( "%d\n", count_trees(1,1)*count_trees(3,1)*count_trees(5,1)*count_trees(7,1)*count_trees(1,2) );

    return EXIT_SUCCESS;
}
