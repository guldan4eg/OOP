#include <fstream>
#include <iostream>

using namespace std;

int counter = 0;
void Sort(ifstream& ffile, ifstream& ffile2, ofstream& gfile, ifstream& output);

int main()
{
	ifstream ffile("file.txt");
	ifstream ffile2("file.txt");
	ofstream gfile("g.txt");
	ifstream output("g.txt");

	if (!ffile)
	{
		cout << "error ffile";
		return 1;
	}
	Sort(ffile, ffile2, gfile, output);
	gfile.close();
	ffile.close();
	return 0;
}

void Sort(ifstream& ffile, ifstream& ffile2, ofstream& gfile, ifstream& output)
{
	int c = 0;
	while (ffile>>c)
	{
		if (c > 0)
		{
			gfile.seekp(counter);
			gfile << c;
			counter += 10;
		}
	}
	counter = 5;
	while (ffile2>>c)
	{
		if (c < 0)
		{
			gfile.seekp(counter);
			gfile << c;
			counter += 10;
		}
	}

	if (!output)
	{
		cout << "error output";
	}

	counter = 5;
	while (output >> c)
	{		
		cout << c << " ";
		output.seekg(counter);
		counter += 5;
	}
	
}