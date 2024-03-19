#include <fstream>
#include <iostream>

using namespace std;

int counter = 0;

void Read(fstream& ffile, int* massive);
void SortObmen(int* massive, short counter);
void Replace(int* massive, int counter);
void Record(ofstream& gfile, int* massive, int counter);
	
int main()
{


	fstream ffile("file.txt", ios::in | ios::out);
	ofstream gfile("g.txt");
	int c = 0;
	if (!ffile || !gfile)
	{
		cout << "error";
	}
	while (!ffile.eof())
	{
		ffile >> c;
		counter++;
		cout << c << " ";
	}
	int* massive = new int [counter] { 0 };
	Read(ffile, massive);
	SortObmen(massive, counter);
	Replace(massive, counter);
	Record(gfile, massive, counter);

	gfile.close();
	ffile.close();
	return 0;
}

void Read(fstream& ffile, int* massive)
{
	int l = 0;
	ffile.seekg(0);
	while (!ffile.fail())
	{
		ffile >> massive[l];
		l++;
	}	 
}


void SortObmen(int* massive, short counter)
{
	int min = massive[0];
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = counter - 1; j > i; j--)
		{
			if (massive[j - 1] > massive[j])
			{
				min = massive[j - 1];
				massive[j - 1] = massive[j];
				massive[j] = min;
			}
		}
	}
}

void Replace(int* massive, int counter)
{
	for (int i = 0; i < counter/2; i += 2)
	{
		swap(massive[i], massive[counter - i-1]);
	}
}

void Record(ofstream& gfile, int* massive, int counter)
{

	for (int i = 0; i < counter; i++)
	{
		gfile << massive[i]<<" ";
	}
}