#include <iostream>
#include <time.h>
#include <iomanip>
#include <vector>

using namespace std;

void Initial(vector<int>& massent, vector<vector<int>>& mass, int n);
void Fill(vector<int>& massent, vector<vector<int>>& mass, int n);
void Vivod(vector<int>& massent, vector<vector<int>>& mass, int n);

int main()
{
	srand(time(NULL));
	int n = 0;
	cout << "Enter matrix size ";
	cin >> n;

	int k = 0;
	cout << "How?\n1-matrix\n2-massive" << endl;
	cin >> k;

	if (k == 1)
	{
		vector<int> massent;
		vector<vector<int>> mass(n, vector<int> (n));

		Initial(massent, mass, n);
		Fill(massent, mass, n);
		Vivod(massent, mass, n);
	}
	else
	{
		vector<int> massive{ 0 };
		vector<int> massent;

		for (int i = 0; i < n * n; i++)
		{
			massive.push_back(rand() % 500);
		}

		for (int i = 0; i < n * 2 - 1; i++)
		{
			massent.push_back(INT_MAX);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(10) << massive[i * n + j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < n * n; i++)
		{
			massent[n - 1 - i / n + i % n] = min(massent[n - 1 - i / n + i % n], massive[i]);
		}

		for (int i = 0; i < 2 * n - 1; i++)
		{
			cout << massent[i] << " ";
		}
		cout << endl;
	}
}

void Fill(vector<int>& massent, vector<vector<int>>& mass, int n)
{
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			massent[j + n - i - 1] = min(mass[i][j], massent[j + n - i - 1]);
		}
	}
}

void Initial(vector<int>& massent, vector<vector<int>>& mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mass[i][j] = rand() % 20;
		}
	}
	for (int i = 0; i < n * 2 - 1; i++)
	{
		massent.push_back(INT_MAX);
	}
}

void Vivod(vector<int>& massent, vector<vector<int>>& mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(5) << mass[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (int j = 0; j < 2 * n - 1; j++)
	{
		cout << massent[j] << " ";
	}
}
