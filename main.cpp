#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>
using namespace std::string_literals;

int main()
{
    std::string s;

    bool seen[26];
    for (int i=0;i!=26;i++)
        seen[i] = false;

    int total = 0;

    while (std::getline(std::cin,s))
    {
        // std::cout << "[" << s << "]";
        if (s=="")
        {
            for (auto b:seen)
                total+=b;
            for (int i=0;i!=26;i++)
                seen[i] = false;
        }
        else
        {
            for (auto c:s)
                seen[c-'a'] = true;
        }
    }
    for (auto b:seen)
        total+=b;

    std::cout << total << "\n";

    return EXIT_SUCCESS;
}
