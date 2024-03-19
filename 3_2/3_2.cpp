#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    const int N = 12;
    int counter = 0;
    fstream ffile("ffile.bin", ios::binary | ios::in | ios::out);
    fstream gfile("gfile.bin", ios::binary | ios::in | ios::out);
    int array[N] {0};
    if (!ffile/* || !gfile*/)
    {
        cout << "Error: file cant be opened" << endl;
        return 1;
    }
    
    for (int i = 1; i <= N; i++)
    {
        int v = rand() % 100;
        ffile.write(reinterpret_cast <char*> (&v), sizeof(int));
    }
    int ads = 0;
    while (!ffile.eof())
    {
        cout<<ads<<" ";
        ffile.read(reinterpret_cast<char*> (&ads),sizeof(int));
        
    }

    gfile.flush();
}