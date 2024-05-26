#include "List.h"
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

template<class T>

void TASK(List<T>& l1, List<T>& l2)
{
    bool v[256]{ 0 };
    while (&l1[0] != nullptr)
    {
        if (!v[l1[0]])
        {
            cout << l1[0]<<" ";
            v[l1[0]] = 1;
        }
        l1.pop();
    }
    while (&l2[0] != nullptr)
    {
        if (!v[l2[0]])
        {
            cout << l2[0] << " ";
            v[l2[0]] = 1;
        }
        l2.pop();
    }
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List<char> l1, l2;
	cout << "enter l1: ";
    for (int i = 0; i < 5; ++i)
    {
        char b;
        cin >> b;
        l1.push(b);
    }
	cout << "enter l2: ";

    for (int i = 0; i < 4; ++i)
    {
        char b;
        cin >> b;
        l2.push(b);
    }
	TASK(l1, l2);
}