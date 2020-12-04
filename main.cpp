#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

int main()
{
    std::string k;
    std::string v;
    std::map<std::string,std::string> m;
    int valid = 0;
    int total = 0;

    while (!std::cin.eof())
    {
        std::cin >> k;
        std::cout << "K" << k << " ";
        if (k=="DONE")
        {
            if (m.count("byr")
            && m.count("iyr")
            && m.count("eyr")
            && m.count("hgt")
            && m.count("hcl")
            && m.count("ecl")
            && m.count("pid")
            )
                valid++;
            m.clear();
            total++;
            continue;
        }
        if (k=="END")
        {
            printf( "%d\n", valid );
            printf( "%d\n", total );
            break;
        }

        std::cin >> v;
        m[k] = v;

        std::cout << v << " ";
        // if (v=="DONE")
        //     break;
    }

    std::cout << "EOF\n";

    return EXIT_SUCCESS;
}
