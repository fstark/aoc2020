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

    int pc = 0;
    int a;
    while (prog[pc].code!="")
    {
        // std::cout << pc << "," << a << ":" << prog[pc].code << " " << prog[pc].value << "\n";
        auto i = prog[pc].code;
        prog[pc].code = "";
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

    }

    std::cout << a << "\n";

    return EXIT_SUCCESS;
}
