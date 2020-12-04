#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>
using namespace std::string_literals;

bool check_numbers( const std::string &v )
{
    for (auto c:v)
        if (c<'0' || c>'9')
            return false;
    return true;
}

bool check_length( const std::string &v, int n )
{
    return v.size()==n;
}

bool check_interval( const std::string &v, int mi, int ma )
{
    int n = atoi( v.c_str() );
    return n>=mi && n<=ma;
}

bool check_year( const std::string &v, int mi, int ma )
{
    if (!check_length( v, 4 )) return false;
    if (!check_numbers( v )) return false;
    return check_interval( v, mi, ma );
}

/*
    hgt (Height) - a number followed by either cm or in:
        If cm, the number must be at least 150 and at most 193.
        If in, the number must be at least 59 and at most 76.
*/
bool check_height( const std::string &v )
{
    if (v.size()<3)
        return false;
    auto unit = v.substr( v.length() - 2 );
    int n = atoi(v.c_str());
    if (unit=="cm")
        return check_interval( v, 150, 193 );
    if (unit=="in")
        return check_interval( v, 59, 76 );
    return false;
}

/*
    hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
*/
bool check_color( const std::string &v )
{
    if (v.size()!=7)
        return false;
    if (v[0]!='#')
        return false;
    auto v2 = v.substr( 1 );
    for (auto c:v2)
        if ("0123456789abcdefABCDEF"s.find(c)==std::string::npos)
            return false;
    return true;
}

/*
    ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
*/
bool check_eye_color( const std::string &v )
{
    if (v=="amb" || v=="blu" || v=="brn" || v=="gry" || v=="grn"  || v=="hzl" || v=="oth")
        return true;
    return false;
}

/*
    pid (Passport ID) - a nine-digit number, including leading zeroes.
*/
bool check_passport( const std::string &v )
{
    return check_numbers(v) && check_length(v,9);
}

void test()
{
    assert( check_year( "2000", 1999, 2001 ));
    assert( !check_year( "200", 1999, 2001 ));
    assert( !check_year( "20002", 1999, 2001 ));
    assert( !check_year( "200c", 1999, 2001 ));
    assert( !check_year( "2000", 1998, 1999 ));
    assert( !check_year( "", 1998, 1999 ));

    assert( check_height( "176cm" ));
    assert( check_height( "60in" ));
    assert( !check_height( "60IN" ));
    assert( !check_height( "" ));
    assert( !check_height( "195cm" ));
    assert( !check_height( "58in" ));

    assert( check_color( "#ff8831" ));
    assert( check_color( "#FF8831" ));
    assert( !check_color( "FF8831" ));
    assert( !check_color( "F#F8831" ));
    assert( !check_color( "#fg8831" ));
    assert( !check_color( "#FFF" ));

    assert( check_eye_color( "blu" ));
    assert( !check_eye_color( "" ));
    assert( !check_eye_color( "blue" ));

    assert( check_passport( "012345678" ) );
    assert( !check_passport( "" ) );
    assert( !check_passport( "0123456789" ) );
    assert( !check_passport( "01234789" ) );
    assert( !check_passport( "012347a9" ) );
}

int main()
{
    test();

    std::string k;
    std::string v;
    std::map<std::string,std::string> m;
    int valid = 0;
    int total = 0;

    while (!std::cin.eof())
    {
        std::cin >> k;
        // std::cout << "K" << k << " ";
        if (k=="DONE")
        {
            /*
    cid (Country ID) - ignored, missing or not.
            */
            if (check_year(m["byr"],1920,2002)
            && check_year(m["iyr"],2010,2020)
            && check_year(m["eyr"],2020,2030)
            && check_height(m["hgt"])
            && check_color(m["hcl"])
            && check_eye_color(m["ecl"])
            && check_passport(m["pid"])
            )
                valid++;
            m.clear();
            total++;
            continue;
        }
        if (k=="END")
        {
            printf( "%d\n", valid );
            // printf( "%d\n", total );
            break;
        }

        std::cin >> v;
        m[k] = v;

        // std::cout << v << " ";
        // if (v=="DONE")
        //     break;
    }

    std::cout << "EOF\n";

    return EXIT_SUCCESS;
}
