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

struct bags
{
    int count;
    std::string color;
};

std::multimap<std::string,bags> map;

int count_bags( const std::string &color )
{
    // std::cout << "{" << color << "}" << std::flush;

    int total = 1;
    auto it = map.find(color);
    if (it==std::end(map))
        return total;
    while (it->first==color)
    {
        // std::cout << "<" << color << "/" << it->first << ":" << it->second.count << "*" << it->second.color << ">" << std::flush;
        total += it->second.count*count_bags( it->second.color );
        it++;
    }
    return total;
}

int main()
{
    while (!std::cin.eof())
    {
        auto c = scan_color();
        if (std::cin.eof())
            break;
        scan_end();
        scan_contain();
        // std::cout << c << ": ";
        do
        {
            int n = scan_number();
            if (n)
            {
                auto b = scan_color();
                // std::cout << "[" << b << "]";
                map.insert({c,{n,b}});
            }
        }   while (!scan_end() && !std::cin.eof());
        // std::cout << "\n";
    }

    std::cout << count_bags( "shiny-gold" )-1 << "\n";

    return EXIT_SUCCESS;
}
