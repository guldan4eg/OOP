#pragma once

class Complex
{
	double m_mod;  
	double m_ang;
	double m_re;
	double m_im;
public:
	//конструкторы
	//без параметра
	Complex()
		:m_mod(0),
		m_ang(0),
		m_re(0),
		m_im(0) {};
	//с параметром
	Complex(double mod, double ang) :
		m_mod(mod), m_im(sin(ang)* mod),
		m_ang(ang), m_re(cos(ang)* mod)
	{};
	//копирование

	//деструктор
	~Complex()
	{};
	//перегрузка операторов
	friend Complex operator +(const Complex& term1, const Complex& term2);
	friend Complex operator -(const Complex& term1, const Complex& term2);
	friend Complex operator *(const Complex& term1, const Complex& term2);
	friend Complex operator /(const Complex& term1, const Complex& term2);
	Complex& operator=(const Complex &term);
	friend Complex operator ^(const Complex& term,const int l);
	friend Complex operator >(const Complex& term, const int l);
	Complex& operator = (double r);
	//friend istream& operator >>(istream& str, const Complex& enter);
	//методы 
	//вывод
	void print();
};



