#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

struct student
{
    char FIO[50];
    int age = 0;
    char sex=0;
    double perform=0;
    int kurs=0;
};

void Show(ifstream& basein, student n_student);
void Delete(ofstream& baseout, ifstream& basein, ofstream& midout, ifstream& midin, int n);
void Add(ofstream& baseout, student n_student);
void Show_kurs(ifstream& basein, ofstream& output, student s_student);
void Edit(ofstream& baseout, ifstream& basein, ofstream& midout, ifstream& midin, student e_student);

int main()
{
    setlocale(LC_ALL, "ru");
    int n = 0;
    student n_student;
    ofstream baseout("base.bin", ios::binary | ios::app);
    ifstream basein("base.bin", ios::binary);
    ifstream midin("mid.bin", ios::binary);
    ofstream midout("mid.bin", ios::binary);
    ofstream output("output.bin", ios::binary);
    basein.close();
    baseout.close();
    midin.close();
    midout.close();
    output.close();
    if (!baseout)
    {
        cout << "Error. Missing file";
        return 1;
    }
    int choice = 0;
    while (true)
    {
        cout << "\nChoose an action.\n 1 - show list of students\n 2 - delete student\n 3 - add new student\n 4 - show students of n kurs\n 5 - edit student\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            basein.open("base.bin", ios::binary);
            while (basein.read(reinterpret_cast<char*> (&n_student.FIO), sizeof(student)))
            {
                n++;
                cout << "number:  " << n << " "<< endl;
                cout << "name:  " << n_student.FIO << endl;
                Show(basein, n_student);
            }
            n = 0;
            basein.close();
            break;
        case 2:
            basein.open("base.bin", ios::binary);
            Delete(baseout, basein, midout, midin, n);
            baseout.close();
            basein.close();
            midin.close();
            midout.close();
            cout << "Deleted";
            break;
        case 3:
            cout << "Enter name ";
            cin.ignore();
            cin.getline(n_student.FIO, 50);
            cout << "Enter age ";
            cin >> n_student.age;
            cout << "Enter sex (m/f) ";
            cin >> n_student.sex;
            cout << "Enter perform ";
            cin >> n_student.perform;
            cout << "Enter kurs ";
            cin >> n_student.kurs;
            baseout.open("base.bin", ios::binary | ios::app);
            Add(baseout, n_student);
            baseout.close();
            break;
        case 4:
            basein.open("base.bin", ios::binary);
            output.open("output.bin", ios::binary);
            Show_kurs(basein, output, n_student);
            basein.close();
            output.close();
            break;
        case 5:
            basein.open("base.bin", ios::binary);
            Edit(baseout, basein, midout, midin, n_student);
            baseout.close();
            basein.close();
            break;
        default:
            cout << "Wrong choice\n";
            break;
        }
    }
    

}

void Show(ifstream& basein, student s_student)
{
    basein.read(reinterpret_cast<char*> (&s_student.age), sizeof(int));
    cout <<"age:  " << s_student.age<< endl;
    basein.read(reinterpret_cast<char*> (&s_student.sex), sizeof(char));
    cout <<"gender:  "<< s_student.sex << endl;
    basein.read(reinterpret_cast<char*> (&s_student.perform), sizeof(double));
    cout <<"performance:  "<< s_student.perform << endl;
    basein.read(reinterpret_cast<char*> (&s_student.kurs), sizeof(int));
    cout <<"kurs:  "<< s_student.kurs<< endl;
    cout << endl;
}
   
void Delete(ofstream& baseout, ifstream& basein, ofstream& midout, ifstream& midin, int n)
{
    student d_student;
    int counter = 0;
    cout << "enter number of student to delete ";
    cin >> n;
    while (basein.read(reinterpret_cast<char*> (&d_student.FIO), sizeof(student)))
    {
        if (counter == n-1)
        {
            basein.seekg(n*97);
        }
        else
        {
            basein.read(reinterpret_cast<char*> (&d_student.age), sizeof(int));
            basein.read(reinterpret_cast<char*> (&d_student.sex), sizeof(char));
            basein.read(reinterpret_cast<char*> (&d_student.perform), sizeof(double));
            basein.read(reinterpret_cast<char*> (&d_student.kurs), sizeof(int));
            midout.open("mid.bin", ios::binary | ios::app);
            Add(midout, d_student);
        }
        counter++;
    }  
    baseout.close();
    basein.close();
    remove("base.bin");
    rename("mid.bin", "base.bin");
    midout.close();
    basein.close();
}

void Add(ofstream& baseout, student n_student)
{
    baseout.write(reinterpret_cast<char*> (&n_student.FIO), sizeof(student));
    baseout.write(reinterpret_cast<char*> (&n_student.age), sizeof(int));
    baseout.write(reinterpret_cast<char*> (&n_student.sex), sizeof(char));
    baseout.write(reinterpret_cast<char*> (&n_student.perform), sizeof(double));
    baseout.write(reinterpret_cast<char*> (&n_student.kurs), sizeof(int));
    baseout.close();
}

void Show_kurs(ifstream& basein, ofstream& output, student s_student)
{
    int kurs;
    bool l = 0;
    cout << "chose kurs ";
    cin >> kurs;
    while (basein.read(reinterpret_cast<char*> (&s_student.FIO), sizeof(student)))
    {
        basein.read(reinterpret_cast<char*> (&s_student.age), sizeof(int));
        basein.read(reinterpret_cast<char*> (&s_student.sex), sizeof(char));
        basein.read(reinterpret_cast<char*> (&s_student.perform), sizeof(double));
        basein.read(reinterpret_cast<char*> (&s_student.kurs), sizeof(int));
        if (s_student.kurs == kurs)
        {
            cout << "name:  " << s_student.FIO << endl;
            cout << "age:  " << s_student.age<< endl;
            cout << "gender:  " << s_student.sex<< endl;
            cout << "performance:  " << s_student.perform << endl;
            cout << "kurs:  " << s_student.kurs<< endl;
            cout << endl;
            Add(output, s_student);
            l=1;
        }
    }
    if (!l)
    {
        cout << endl << "No students on this kurs" << endl;
    }
}

void Edit(ofstream& baseout, ifstream& basein, ofstream& midout, ifstream& midin, student e_student)
{
    int n = 0, counter =0;
    bool k = 0;
    cout << "Enter number of student to edit "<<endl;
    cin >> n;
    while (basein.read(reinterpret_cast<char*> (&e_student.FIO), sizeof(student)))
    {
        if (counter == n - 1)
        {
            basein.seekg(n * 97);
            cout << "Enter name ";
            cin.ignore();
            cin.getline(e_student.FIO, 50);
            cout << "Enter age ";
            cin >> e_student.age;
            cout << "Enter sex (m/f) ";
            cin >> e_student.sex;
            cout << "Enter perform ";
            cin >> e_student.perform;
            cout << "Enter kurs ";
            cin >> e_student.kurs;
            baseout.open("base.bin", ios::binary | ios::app);
            Add(baseout, e_student);
            baseout.close();
        }
        else
        {
            basein.read(reinterpret_cast<char*> (&e_student.age), sizeof(int));
            basein.read(reinterpret_cast<char*> (&e_student.sex), sizeof(char));
            basein.read(reinterpret_cast<char*> (&e_student.perform), sizeof(double));
            basein.read(reinterpret_cast<char*> (&e_student.kurs), sizeof(int));
            midout.open("mid.bin", ios::binary | ios::app);
            Add(midout, e_student);
        }
        counter++;
    }
    baseout.close();
    basein.close();
    remove("base.bin");
    rename("mid.bin", "base.bin");
    midout.close();
    basein.close();
    
}