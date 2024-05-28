#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List <int> l;
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
    for (int i = 0; i < n; i++)
    {
        proisv *= l[i] - l[n*2 - 1 - i];
    }

    cout << proisv << endl;
}