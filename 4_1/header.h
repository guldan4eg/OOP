#pragma once


using namespace std;

class Vector
{  
    int size=0;
    int* arr= nullptr, *arr1 = nullptr; 
public:
    Vector();
    Vector(int size);
    Vector(const Vector& other);
    Vector(Vector&& other);
    int operator [](const int i);
    Vector& operator =(Vector&& other);
    Vector& operator=(const Vector& arr);
    void SortObmen();
    void Sort();
    int Getsize();
    void SetSize(int size);
    void Random();
    void Print();
    int Push_back(int l);
    ~Vector();
};