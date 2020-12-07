#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std::string_literals;

std::string scan_color()
{
    std::string c1,c2;
    std::cin >> c1;
    std::cin >> c2;
    return c1+"-"+c2;
}

void scan_contain()
{
    std::string contains;
    std::cin >> contains;
    // std::cout << "[" << contains << "]";
    assert( contains=="contain" );
}

int scan_number()
{
    std::string ns;
    std::cin >> ns;
    if (ns=="no")
    {
        std::cin >> ns;
        return 0;
    }
    return atoi(ns.c_str());
}

bool scan_end()
{
    std::string bag;
    std::cin >> bag;
    return bag[bag.size()-1]=='.';
}

int main()
{
    std::multimap<std::string,std::string> reverse_map;

    while (!std::cin.eof())
    {
        auto c = scan_color();
        if (std::cin.eof())
            break;
        scan_end();
        scan_contain();
        std::cout << c << ": ";
        do
        {
            int n = scan_number();
            if (n)
            {
                auto b = scan_color();
                std::cout << "[" << b << "]";
                reverse_map.insert({b,c});
            }
        }   while (!scan_end() && !std::cin.eof());
        std::cout << "\n";
    }

    std::set<std::string> bags;
    bags.insert( "shiny-gold"s );

    while (true)
    {
        std::set<std::string> more_bags;
        for (auto &c:bags)
        {
            more_bags.insert( c );
            auto i0 = reverse_map.lower_bound(c); 
            auto i1 = reverse_map.upper_bound(c);          
            while (i0!=i1)     
            { 
                if (i0->first==c) 
                    more_bags.insert( i0->second );         
                i0++; 
            }     
        }
        if (more_bags.size()>bags.size())
        {
            bags = more_bags;
        }
        else
            break;
    }

    std::cout << bags.size()-1 << "\n";

    return EXIT_SUCCESS;
}
