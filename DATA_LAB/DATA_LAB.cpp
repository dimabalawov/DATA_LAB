#include "Data.h"

#include <iostream>
using namespace std;

int main()
{
    Data a;
    Data b(4,5,2004);
    a.Input();
    a.Print();
    a++;
    a.Print();
    a--;
    a.Print();
    a += 4;
    a.Print();
    a -= 4;
    a.Print();
    a = a + 4;
    a.Print();
    a = a - 4;
    a.Print();
    a = a - b;
    a.Print();
    cout << (a > b) << endl;
    cout << (a < b) << endl;
    cout << (a <= b) << endl;
    cout << (a <= b) << endl;
    cout << (a == b) << endl;
    cout << (a != b) << endl;
}

