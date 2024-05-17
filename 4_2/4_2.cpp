#include "list.h"
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list<int> l1, l2;
	cout << "enter l1: ";
	for (int i = 0; i < 10; ++i)
		l1.push(i);
	cout << "enter l2: ";
	for (int i = 124; i < 128; ++i)
		l2.push(i);
	list<int> l;
	l.TASK(l1, l2);
	l.output();
}