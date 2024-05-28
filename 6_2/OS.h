#pragma once
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class OS
{
protected:
	bool Visible = 1;
	unsigned int x = 0;
	unsigned int y = 0;
	int height = 0;
	int width = 0;

public:
	virtual void fill(istream& in)
	{
		cout << "X Y Height Width: ";
		in >> x >> y >> height >> width;
	}
	virtual void print(ostream& out) const \
	{
		cout << "X Y Height Width: ";
		out << x << y << height << width;
	}
	OS& operator=(const OS& other);
	OS& operator=(OS&& other);
	friend istream& operator>>(istream& in, OS& me);
	friend ostream& operator<<(ostream& out, const OS& me);
	virtual ~OS() {}
};

class Text : public OS
{
protected:
	char txt[20];
	unsigned int color[3];
public:
	Text() : OS(),
		txt("0"), color() {}
	Text(char a[20], unsigned int color[3]);
	Text& operator=(const Text& other);
	Text& operator=(Text&& other);
	virtual void fill(istream& in) override
	{
		OS::fill(in);
		cout << "\nEnter text: ";
		for (int i = 0; i < 20; i++)
		{
			in >> txt[i];
		}
	}
	virtual void print(ostream& out) const override
	{
		OS::print(out);
		out << "Text is: ";
		for (int i = 0; i < 20; i++)
		{
			out << txt[i];
		}
		out << endl;
	}
	virtual ~Text() override {}
};

class HyperLink :public Text
{
protected:
	char url[20];
public:
	HyperLink()
		:Text(),
		url("0") {}
	HyperLink(char url[20]);
	HyperLink(const HyperLink& a);
	HyperLink(HyperLink&& other);
	HyperLink& operator=(const HyperLink& other);
	HyperLink& operator=(HyperLink&& other);
	void print(ostream& out) const
	{
		Text::print(out);
		out << "\nUrl is: \n";

		for (int i = 0; i < 20; i++)
		{
			out << url[i];
		}
		out << "\n\n";
	}
	void fill(istream& in)
	{
		Text::fill(in);
		cout << "\nEnter url adress: " << endl;
		for (int i = 0; i < 20; i++)
		{
			in >> url[i];
		}
	}
	~HyperLink() = default;
};

class TextBox :public Text
{
protected:
	bool readonly;
public:
	TextBox()
		:readonly(0) {}
	TextBox(bool readonly);
	TextBox& operator=(const TextBox& other);
	TextBox& operator=(TextBox&& other);
	~TextBox() = default;
	void fill(istream& in)
	{
		Text::fill(in);
		cout << "\nIs it only for read?" << endl;
		in >> readonly;
	}
	void print(ostream& out) const
	{
		Text::print(out);
		if (readonly)
			out << "\nOnly for read\n ";
		else out << "\nFor write\n ";
		out << endl;
	}
};
class Button : public Text
{
protected:
	char ToolTipText[20];
public:
	Button()
		:ToolTipText("type here\n") {}
	Button(char ToolTipText[20]);
	Button& operator=(const Button& other);
	Button& operator=(Button&& other);
	void fill(istream& in)
	{
		Text::fill(in);
		cout << "\nEnter Tip for button: " << endl;
		for (int i = 0; i < 20; i++)
		{
			in >> ToolTipText[i];
		}
	}
	void print(ostream& out) const
	{
		Text::print(out);
		out << "\nToolTipText is: \n";

		for (int i = 0; i < 20; i++)
		{
			out << ToolTipText[i];
		}
		out << "\n\n";
	}
	~Button() = default;
};

class Ellips :public OS
{
protected:
	unsigned int Fillcolor[3];
	unsigned int Bordercolor[3];
public:
	Ellips()
		:Fillcolor(),
		Bordercolor() {}
	Ellips(unsigned int Fillcolor[3], unsigned int Bordercolor[3]);
	Ellips& operator=(const Ellips& other);
	Ellips& operator=(Ellips&& other);
	void fill(istream& in)
	{
		cout << "For Ellips: ";
		OS::fill(in);
		cout << "\nEnter Ellips fillcolor for button: " << endl;
		for (int i = 0; i < 3; i++)
		{
			in >> Fillcolor[i];
			if (Fillcolor[i] > 256 || Fillcolor[i] < 0)
			{
				cout << "\nOne of Bordercollor settings in Ellips invalid, now its 0\n";
				this->Bordercolor[i] = 0;
			}
		}
		cout << "\nEnter Ellips bordercolor for button: " << endl;
		for (int i = 0; i < 3; i++)
		{
			in >> Bordercolor[i];
		}
	}
	void print(ostream& out) const
	{
		cout << "Ellpis: ";
		OS::print(out);
		out << "\nFillcolor: ";
		for (int i = 0; i < 3; i++)
		{
			out << Fillcolor[i] << " ";
		}
		out << "\nBorder collor is: ";
		for (int i = 0; i < 3; i++)
		{
			out << Bordercolor[i] << " ";
		}
		out << "\n\n";
	}
	~Ellips() = default;
};
void ClearArr(vector<OS*>& arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		delete arr[i];
	arr.clear();
}
void ClearArr(vector<Text*>& arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		delete arr[i];
	arr.clear();
}
void Vvod(vector<OS*>& arr, unsigned int n)
{
	ClearArr(arr);//если передан не пустой массив - очистить
	while (arr.size() < n)
	{
		int type = 0;
		cout << "Input type of object:\n";
		cout << "Text - 1; Ellips - 2 \n";
		cin >> type;
		switch (type)
		{
		case 1:
		{
			Text* st = new Text();
			st->fill(cin);
			arr.push_back(st);
			break;
		}
		case 2:
		{	Ellips* p = new Ellips();
		cin >> *p;
		arr.push_back(p);
		break;
		}
		default:
			cout << "Error";
		}
	}
}

void Vvod(vector<Text*>& arr, unsigned int n)
{
	ClearArr(arr);//если передан не пустой массив - очистить
	while (arr.size() < n)
	{
		int type = 0;
		cout << "Input type of object:\n";
		cout << "Url - 1; TextBox - 2; Button - 3 \n";
		cin >> type;
		switch (type)
		{
		case 1:
		{
			HyperLink* st = new HyperLink();
			st->fill(cin);
			arr.push_back(st);
			break;
		}
		case 2:
		{	TextBox* p = new TextBox();
		cin >> *p;
		arr.push_back(p);
		break;
		}
		case 3:
		{
			Button* b = new Button();
			cin >> *b;
			arr.push_back(b);
			break;
		}
		default:
			cout << "Error";
		}
	}
}
// вывод массива сотрудников
void Vyvod(const vector<OS*>& arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		cout << *arr[i];
}
void Vyvod(const vector<Text*>& arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		cout << *arr[i];
}
// освободить память

