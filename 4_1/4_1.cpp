#include <iostream>
#include <time.h>
#include "header.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Vector arr(5);
    arr.Random();
    arr.Print();
    cout << endl;
    arr.SortObmen();
    arr.Print();
    cout << endl;
    arr.Sort();
}
