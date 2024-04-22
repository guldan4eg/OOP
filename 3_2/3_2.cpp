#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

int counterp = 0, countern = 4;

void Write_file(fstream& ffile, int n);
void Sort(fstream& ffile, ofstream& gfile);
void Show(ifstream& output);

int main()
{
	cout << "Enter amount of numbers ";
	int n = 0, c =0;
	cin >> n;
	srand(time(NULL));
	ifstream read("f.bin", ios::binary);
	fstream ffile("f.bin", ios::in | ios::out | ios::binary | ios::trunc);
	ofstream gfile("g.bin", ios::binary | ios::trunc);
	ifstream output("g.bin", ios::binary);

	//Write_file(ffile, n);
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		ffile.write(reinterpret_cast<char*> (&c), sizeof(int));
	}

	if (!ffile)
	{
		cout << "error file missing";
		return 1;
	}
	ffile.close(); 
	Sort(ffile, gfile);
	Show(output);

	ffile.close();
	gfile.close();

	return 0;
}

void Write_file(fstream& ffile, int n)
{
	for (int i = 0; i < n/2; i++)
	{
		int c = rand() % 10 - 100;
		ffile.write(reinterpret_cast<char*> (&c), sizeof (int));
		cout << c << " ";
	}
	for (int i = 0; i < n/2; i++)
	{
		int c = rand() % 200;
		ffile.write(reinterpret_cast<char*> (&c), sizeof(int));
		cout << c << " ";
	}
	ffile.close();
	cout << endl;
}

void Sort(fstream& ffile, ofstream& gfile)
{
	int c;
	ffile.open("f.bin");
	ffile.seekg(0);
	while (!ffile.fail())
	{
		ffile.read(reinterpret_cast<char*> (&c), sizeof(int));
		if (c > 0)
		{
			gfile.seekp(counterp);
			gfile.write(reinterpret_cast<char*> (&c), sizeof(int));
			counterp += 8;
		}
		else
		{
			gfile.seekp(countern);
			gfile.write(reinterpret_cast<char*> (&c), sizeof(int));
			countern += 8;
		}
			
	}
	ffile.close();
	cout << endl;
}

void Show(ifstream& output)
{
	int v;

	while (output.read(reinterpret_cast<char*>(&v), sizeof(int)))
	{
		cout << v << " ";
	}
	cout << endl;
}
