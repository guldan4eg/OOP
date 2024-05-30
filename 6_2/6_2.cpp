#include <iostream>
#include <vector>
#include <fstream>
#include "OS.h"

void ClearArr(vector<OS*>& arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
        delete arr[i];
    arr.clear();
}

void Vyvod(const vector<OS*>& arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
        cout << *arr[i];
}

void VVOd(vector <OS*>& arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
        cin >> *arr[i];
}

int main()
{
    OS komp;
    Ellips o;
    TextBox c;
    vector<OS*> a;
    a.push_back(&o);
    a.push_back(&c);
    VVOd(a);
    Vyvod(a);
}
