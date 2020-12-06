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

    int seen[26];
    for (int i=0;i!=26;i++)
        seen[i] = 0;

    int total = 0;
    int count = 0;

    while (std::getline(std::cin,s))
    {
        // std::cout << "[" << s << "]";
        if (s=="")
        {
            for (auto b:seen)
                total+=b==count;
            for (int i=0;i!=26;i++)
                seen[i] = 0;
            count = 0;
        }
        else
        {
            for (auto c:s)
                seen[c-'a']++;
            count++;
        }
    }
    for (auto b:seen)
        total+=b==count;

    std::cout << total << "\n";

    return EXIT_SUCCESS;
}
