#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    list <int> l;
    int n;
    cout << "enter size ";
    cin >> n;
    cout << "enter numbers: ";
    for (int i = 0; i < n * 2; ++i)
    {
        int a;
        cin >> a;
        l.push(a);
    }
    int proisv = 1;
    for (int i = 0; i < n; ++i)
    {
        proisv *= (l[i*2] - l[2*n - i * 2 - 1]);
    }
    cout << proisv << endl;
}