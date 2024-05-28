#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <Complex>
#include "Complex.h"

using namespace std;

int main()
{
    Complex a(5, M_PI / 6), b(5, M_PI/6), c(a);
    a.print();
    c = a * b;
    c.print();
    cin >> c;
    c.print();

}
