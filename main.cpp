#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <array>

struct interval
{
    int from;
    int to;

    bool check( int n ) { return n>=from && n<=to; }
};

int main()
{
    const int FIELDS = 20;

    std::array<std::array<bool,FIELDS>,FIELDS> matches;

    for (int f=0;f!=FIELDS;f++)
        for (int p=0;p!=FIELDS;p++)
            matches[f][p] = true;

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

        bool keep = true;
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
                keep = false;
        }
        if (keep)
        {
            for (int tf=0;tf!=FIELDS;tf++)          //  ticket fields
            {
                int v = ticket[tf];
                for (int pf=0;pf!=FIELDS;pf++)      //  potential fields
                    if (!valids[pf].first.check(v) && !valids[pf].second.check(v))
                    {
                        matches[tf][pf] = false;
                        // std::cout << "TICKET ATT #" << tf << " CANNOT MATCH FIELD #" << pf << " (VALUE " << v << ")\n";
                    }
            }
        }
    }

    auto ref = matches;
    for (;;)
    {
        for (int x=0;x!=FIELDS;x++)
        {
            int count = 0;
            int pos = 0;
            for (int y=0;y!=FIELDS;y++)
            {
                if (matches[x][y])
                {
                    count++;
                    pos = y;
                }
            }
            if (count==1)
            {
                std::cout << " X= " << x << " Y= " << pos << "\n";
                for (int y=0;y!=FIELDS;y++)
                {
                    matches[y][pos] = false;
                }
                matches[x][pos] = true;

                for (int f=0;f!=FIELDS;f++)
                {
                    for (int p=0;p!=FIELDS;p++)
                        std::cout << matches[f][p] << " ";
                    std::cout << "\n";
                }
                std::cout << "\n";
                std::cout << "\n";

            }
        }

        if (ref==matches)
            break;
        ref = matches;
    }

    std::vector my_ticket = { 139,67,71,59,149,89,101,83,107,103,79,157,151,113,61,109,73,97,137,53 };

    long prod = 1;
    for (int f=0;f!=6;f++)
    {
        for (int p=0;p!=FIELDS;p++)
            if (matches[p][f])
            {
                prod *= my_ticket[p];
                std::cout << p << " " << my_ticket[p] << "\n";
            }
    }

    std::cout << prod << "\n";

    return EXIT_SUCCESS;
}
