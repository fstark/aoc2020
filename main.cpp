#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

struct interval
{
    int from;
    int to;

    bool check( int n ) { return n>=from && n<=to; }
};

int main()
{
    std::string attribute;
    std::string token;

    std::vector<std::pair<interval,interval>> valids;

    for (;;)
    {
        std::cin >> attribute;

        if (attribute=="your")
            break;

        int from;
        char c;
        int to;

        std::pair<interval,interval> data;

        std::cin >> data.first.from;
        std::cin >> c;
        std::cin >> data.first.to;

        std::cin >> token;

        std::cin >> data.second.from;
        std::cin >> c;
        std::cin >> data.second.to;

        valids.push_back( data );
    }

    do
    {
        std::cin >> token;
        // std::cout << token << "|";
    }   while (token!="tickets:");

    int err = 0;

    for (;;)
    {
        std::vector<int> ticket;

        int n;
        for (;;)
        {
            char c;
            std::cin >> n;
            if (std::cin.eof())
                break;
            if (n==-1)
                break;
            std::cin >> c;
            ticket.push_back( n );
        }
        if (std::cin.eof())
            break;

        for (auto &v:ticket)
        {
            bool good = false;
            for (auto &range:valids)
            {
                if (range.first.check(v) || range.second.check(v))
                {
                    good = true;
                    break;
                }
            }
            
            if (!good)
                err += v;
        }
    }

    std::cout << err << "\n";

    return EXIT_SUCCESS;
}
