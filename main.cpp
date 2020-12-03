#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    const int W = 31;
    const int H = 323;

    char data[W][H];

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

    int total = 0;
    for (int i=0;i!=H;i++)
        total += data[(3*i)%W][i]=='#';

    printf( "%d\n", total );

    return EXIT_SUCCESS;
}
