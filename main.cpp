#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a;
    int b;
    char c;
    char passwd[1024];

    int total = 0;

    while (scanf("%d-%d %c: %s\n", &a, &b, &c, passwd)==4)
    {
        int count = 0;
        for (int i=0;i!=strlen(passwd);i++)
            if (passwd[i]==c)
                count++;
        if (count>=a && count<=b)
            total++;
    }

    printf( "%d\n", total );

    return EXIT_SUCCESS;
}
