#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    while (!cin.eof())
    {
        int val;
        cin >> val;
        v.push_back(val);
    }

    for (auto a:v)
        for (auto b:v)
            if (a+b==2020)
                cout << a*b << endl;

    return EXIT_SUCCESS;
}
