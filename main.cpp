#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std::string_literals;

struct instr
{
    std::string code;
    int value;
};

int exec( std::vector<instr> prog, int i )
{
    if (prog[i].code=="nop")
        prog[i].code = "jmp";
    else
        if (prog[i].code=="jmp")
            prog[i].code = "nop";

    int pc = 0;
    int a = 0;
    int count = 0;
    while (count++ <= prog.size())
    {
        // std::cout << pc << "," << a << ":" << prog[pc].code << " " << prog[pc].value << "\n";
        auto i = prog[pc].code;
        if (i=="acc")
        {
            a = a + prog[pc].value;
            pc++;
        }
        else if (i=="nop")
        {
            pc++;
        }
        else if (i=="jmp")
        {
            pc += prog[pc].value;
        }

        if (pc<0 || pc>=prog.size())
            return a;
    }

    // std::cout << "\n";

    return 0; // ?ugh
}

int main()
{
    std::vector<instr> prog;

    while (!std::cin.eof())
    {
        std::string instr;
        int value;

        std::cin >> instr;
        if (std::cin.eof())
            break;
        std::cin >> value;

        prog.push_back( { instr, value } );
    }

    int a;
    for (int i=0;i!=prog.size();i++)
    {
        // std::cout << i << "\n";
        a = exec( prog, i );
        if (a)
            break;
    }
    std::cout << a << "\n";

    return EXIT_SUCCESS;
}
