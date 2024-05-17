#include <iostream>
#include <list>

using namespace std;

void Solve1();
void Solve2();

int main()
{
	srand(time(NULL));
	int n = 0; 
	cout << "choise 1-2.4, 2-2.6 ";
	cin >> n;
	switch (n)
	{
	case 1:
		Solve1();
		break;
	case 2:
		Solve2();
		break;
	default:
		break;
	}
}

void Solve1()
{
	list<char> l,l1,l2;
	int size1 =0;
	bool v[256]{0};
	cout << "Enter l1 size ";
	cin >> size1;
	cout << "Enter l1 ";
	for (int i = 0; i < size1; i++)
	{
		char h = 0;
		cin >> h;
		l1.push_back(h);
	}
	int size2 = 0;
	cout << "Enter l2 size ";
	cin >> size2;
	cout << "Enter l2 ";
	for (int i = 0; i < size2; i++)
	{
		char h = 0;
		cin >> h;
		l2.push_back(h);
	}
	while (!l1.empty())
	{
		list<char>::iterator p = l1.begin();
		if (!v[(int)*p])
		{
			l.push_back(*p);
			v[(int)*p] = 1;
		}
		l1.pop_front();
	}
	while (!l2.empty())
	{
		list<char>::iterator p = l2.begin();
		if (!v[(int)*p])
		{
			l.push_back(*p);
			v[(int)*p] = 1;
		}
		l2.pop_front();
	}
	list<char>::iterator pl = l.begin();
	while(pl != l.end())
	{
		cout << *pl<<" ";
		pl++;
	}
}

void Solve2()
{
	int n;
	cout << "Enter n " << endl;
	cin >> n;
	list<int>l;
	l.push_back(1);
	for (int i = 0; i < 2 * n; i++)
	{
		l.push_back(rand() % 20);
		cout << l.back() << " ";
	}
	list<int>::iterator pr = l.begin();
	pr++;
	list<int>::iterator pl = l.end();
	pl--;
	int answ = 1;
	for (int i = 0; i < n; i++)
	{
		answ *= (*pr - *pl);
		pr++;
		pr++;
		pl--;
		pl--;
	}
	cout <<endl<< answ << endl;
}