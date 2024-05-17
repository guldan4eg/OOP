#include "header.h"
#include <iostream>
#include <time.h>
using namespace std;
Vector::Vector()
{

	this->size = size;
}
Vector::Vector(int size)
{
	this->size = size;
	int* arr = new int[size];
}

Vector::Vector(const Vector& other)
{
	size = other.size;
	arr = new int[size] {0};
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

Vector& Vector::operator =(Vector&& other)
{
	if (&other != this)
	{
		delete[] arr;
		size = other.size;
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
		delete[] other.arr;
		other.size = 0;
	}
	return *this;
}

int Vector::Getsize()
{
	return size;
}

void Vector::SetSize(int size)
{
	this->size = size;
	arr = new int[size];
}

void Vector::Random()
{
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void Vector::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int Vector::Push_back(int l)
{
	int i = 0;
	arr1 = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr[i];
	}	
	this->size += 1;
	arr = new int[size] {0};
	for (int j = 0; i < size-1; i++)
	{
		arr[i] = arr1[i];
	}
	arr[i] = l;
	return *arr;
}

void Vector::SortObmen()
{
	int min = arr[0];

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				min = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = min;
			}
		}
	}
}


void Vector::Sort()
{
	Vector arr2;
	bool k = 0;
	if (arr[0] != arr[1])
	{
		arr2.Push_back(arr[0]);
	}
	if (arr[size - 1] != arr[size - 2])
	{
		arr2.Push_back(arr[size - 1]);
	}

	for (int i = 1; i < Getsize() - 1; i++)
	{

		if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
		{
			arr2.Push_back(arr[i]);
		}
	}
	arr2.Print();
}

Vector& Vector::operator=(const Vector& other)
{
	if (this->arr!=nullptr)
	{
		delete[] this->arr;
	}
	if (this->arr1 != nullptr)
	{
		delete[] this->arr1;
	}
	size = other.size;
	arr = new int[size] {0};
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;

}
int Vector::operator [](const int i)
{
	if (i<size)
	{
	return arr[i];
	}
	else
	{
		cout << "Out of size, returnig 0 elemnt" << endl;
		return arr[0];
	}

}


Vector::~Vector()
{
	delete[] arr;
	delete[] arr1;
}
