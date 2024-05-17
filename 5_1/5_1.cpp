#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Task1();
int Task2();
void Task3(string ent, string res);

int main()
{
	system("chcp 1251");
	//setlocale(LC_ALL, "rus");
	int n;
	string ent, res;
	cout << "choice: 1-erasing exect 2 symbols; 2-from x16 to x10; 3-max lettered words ";
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
		cout << "Enter text: " << endl;
		cin.ignore();
		getline(cin, ent);
		Task3(ent, res);
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

int Task2()
{
	string num;
	cout << "Enter number in x16: ";
	cin >> num;
	int i = 0, j = 0;
	bool h = 0;
	double res=0;
	for (int k = 0; k < num.size(); k++)
	{
		if (num[k] == ',' || num[k] == '.')
			h = 1;
		if (num[k] > 'F')
		{
			h = 0;
			break;
		}
	}
	if (h==0)
	{
		cout << "Not x16 or float";
		return 0;
	}
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

void Task3(string ent, string res)
{
	int counter_lett = 0, max = 0, all_lett=0;
	for (int i = 0; i < ent.size(); i++)
	{
		if (ent.at(i) == 'а' || ent.at(i) == 'о' || ent.at(i) == 'ю' || ent.at(i) == 'я' || ent.at(i) == 'и' || ent.at(i) == 'е' || ent.at(i) == 'у' || ent.at(i) == 'ы' || ent.at(i) == 'э' || ent.at(i) == 'ё')
			counter_lett++;
		if (ent.at(i) == ' ' || ent.at(i) == '.' || ent.at(i) == ',' || ent.at(i) == '!' || ent.at(i) == '?' || ent.at(i) == '-' || ent.at(i) == '<<' || ent.at(i) == '>>' || ent.at(i) == ':' || ent.at(i) == ';' || i == ent.size()-1)
		{
			if (max < counter_lett)
				max = counter_lett;
			counter_lett = 0;
		}
	}

	for (int i = 0; i < ent.size(); i++)
	{
		all_lett++;
		if (ent.at(i) == 'а' || ent.at(i) == 'о' || ent.at(i) == 'ю' || ent.at(i) == 'я' || ent.at(i) == 'и' || ent.at(i) == 'е' || ent.at(i) == 'у' || ent.at(i) == 'ы' || ent.at(i) == 'э' || ent.at(i) == 'ё')
			counter_lett++;
		if (ent.at(i) == ' ' || ent.at(i) == '.' || ent.at(i) == ',' || ent.at(i) == '!' || ent.at(i) == '?' || ent.at(i) == '-' || ent.at(i) == '<<' || ent.at(i) == '>>' || ent.at(i) == ':' || ent.at(i) == ';' || i == ent.size() - 1)
		{
			if (max == counter_lett)
			{
				res.assign(ent, i - all_lett, all_lett+1);
				break;
			}
			counter_lett = 0;
			all_lett = 0;
		}
	}
	cout << res;
}