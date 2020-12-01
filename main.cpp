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
            for (auto c:v)
                if (a+b+c==2020)
                    cout << a*b*c << endl;

    return EXIT_SUCCESS;
}
