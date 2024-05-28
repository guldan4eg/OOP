#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>;
#include "Complex.h" 
using namespace std;
 
Complex operator +(const Complex& term1, const Complex& term2)
{
	Complex result;
	result.m_re = term1.m_re + term2.m_re;
	result.m_im = term2.m_im + term2.m_im;
	return result;
}
Complex operator -(const Complex& term1, const Complex& term2)
{
	Complex result;
	result.m_re = term1.m_re - term2.m_re;
	result.m_im = term2.m_im - term2.m_im;
	return result;
}
Complex operator *(const Complex& term1, const Complex& term2)
{
	Complex result;
	result.m_re = term1.m_re * term2.m_re - term1.m_im * term2.m_im;
	result.m_im = term1.m_re * term2.m_im + term2.m_re * term1.m_im;
	return result;
}

Complex operator /(const Complex& term1, const Complex& term2)
{
	Complex result;
	double b = term2.m_re * term2.m_re + term2.m_im * term2.m_im;
	result.m_re = (term1.m_re * term2.m_re + term1.m_im * term2.m_im) / b;
	result.m_im = (term2.m_re * term1.m_im - term1.m_re * term2.m_im) / b;
	return result;
}

Complex operator ^(const Complex& term, const int l)
{
	Complex result;
	double b = pow(term.m_mod, l);
	result.m_re = b*cos(l*term.m_ang);
	result.m_im = b * sin(l * term.m_ang);
	return result;
}
Complex& Complex::operator=(const Complex & term)
{
	m_ang = term.m_ang;
	m_mod = term.m_mod;
	m_re = term.m_re;
	m_im = term.m_im;
	return *this;
}
Complex& Complex::operator = (Complex&& term)
{
	m_ang = term.m_ang;
	m_mod = term.m_mod;
	m_re = term.m_re;
	m_im = term.m_im;
	term.m_ang=0;
	term.m_mod=0;
	term.m_re=0;
	term.m_im=0;
	return *this;
}

Complex& Complex::operator = (double r)
{
	m_re = r;   m_im = 0;
	return *this;
}

Complex operator >(const Complex& term, const int l)
{
	Complex result;
	double b = sqrt(term.m_mod);
	result.m_re = b * cos(term.m_ang/l);
	result.m_im = b * sin(term.m_ang / l);
	return result;
}
istream& operator >>(istream& str, Complex& enter)
{
	double mod = 0, ang = 0;
	str >> mod >> ang;
	enter = Complex(mod, ang);
	return str;
}
ostream& operator <<(ostream& out, Complex& term)
{
	if (term.m_im < 0) return out << term.m_re << term.m_im << "i";
	else   return out << term.m_re << "+" << term.m_im << "i";
}


void Complex::print()
{
	cout<< m_re << "+" << m_im << "i ";
}

Complex::Complex(const Complex& other)
{
	this->m_ang = other.m_ang;
	this->m_im = other.m_im;
	this->m_mod = other.m_mod;
	this->m_re = other.m_re;
}

Complex::Complex(Complex&& other)
{
	this->m_ang = other.m_ang;
	this->m_im = other.m_im;
	this->m_mod = other.m_mod;
	this->m_re = other.m_re;
	other.m_ang = 0;
	other.m_im = 0;
	other.m_mod = 0;
	other.m_re = 0;
}