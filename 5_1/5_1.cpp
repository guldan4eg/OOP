#include <iostream>
#include <string>

using namespace std;

void Task1();
void Task2();
void Task3();

int main()
{
	system("chcp 1251");
	//setlocale(LC_ALL, "rus");
	int n;
	cout << "choice: 1-erasing exect 2 symbols; 2-from x16 to x10; 3-budet. ";
	cin >> n;
	switch (n)
	{
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;
	default:
		cout << "wrong choice ";
		break;
	}

}

void Task1()
{
	bool k = 0;
	int b {0};
	string ent;
	cout << "Enter text: " << endl;
	cin.ignore();
	getline(cin, ent);

	for (int i = 0; i < ent.size(); i++)
	{
		for (int j = 0; j < ent.length(); j++)
		{
			if (ent.at(i) == ent.at(j) && i != j && k==0)
			{
				k = 1;
				b = j;
			}
			else if (ent.at(i) == ent.at(j) && i != j && k == 1)
			{
				k = 0;
				break;
			}
		}
		if (k == 1 && ent.at(i) != ' ' && ent.at(b) != ' ')
		{
			ent.erase(i, 1);
			ent.erase(b-1, 1);
			i = -1;
			k = 0;
		}
	}

	cout << endl << ent;
}
void Task2()
{
	string num;
	cout << "Enter number in x16: ";
	cin >> num;
	int i = 0, j = 0;
	double res=0;
	while (num[i] != ',' && num[i] != '.')
	{
		i++;
		j++;
	}
	i--;
	j--;
	while (i>=0)
	{
		if(num[i] < 65)
		res += ((int)num[i]-48) * pow(16, j-i);
		else
		{
			res += (((int)num[i] - 65)+10) * pow(16, j - i);
		}
		i--;
	}
	j +=2;
	while (j<num.size())
	{
		if (num[j] < 65)
			res += ((int)num[j] - 48) * pow(16, i);
		else
		{
			res += (((int)num[j] - 65) + 10) * pow(16, i);
		}
		j++;
		i--;
	}
	cout.precision(46);
	cout << res;
}

void Task3()
{
	string ent, res;
	cout << "Enter phrase: "<<endl;
	cin.ignore();
	getline(cin, ent);
	int max = 0, counter =0;
	
}