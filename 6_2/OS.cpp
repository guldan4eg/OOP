#include <iostream>
#include <fstream>
#include "OS.h"
#include <vector>

using namespace std;

istream& operator>>(istream& in, OS& me)
{
	me.fill(in);
	return in;
}

ostream& operator<<(ostream& out, const OS& me)
{
	me.print(out);
	return out;
}
//конструкторы
Text::Text(char txt[20], unsigned int color[3]) :OS()
{
	for (int i = 0; i < 20; i++)
	{
		this->txt[i] = txt[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (color[i] > 256 || color[i] < 0)
		{
			cout << "One of collor settings in Text invalid, now its 0";
			this->color[i] = 0;
		}
		else this->color[i] = color[i];
	}
}

HyperLink::HyperLink(char url[20])
{
	for (int i = 0; i < 20; i++)
	{
		this->url[i] = url[i];
	}
}
TextBox::TextBox(bool readonly) { this->readonly = readonly; }

Button::Button(char ToolTipText[20])
{
	for (int i = 0; i < 20; i++)
	{
		this->ToolTipText[i] = ToolTipText[i];
	}
}

Ellips::Ellips(unsigned int Fillcolor[3], unsigned int Bordercolor[3])
{
	for (int i = 0; i < 3; i++)
	{
		if (Fillcolor[i] > 256 || Fillcolor[i] < 0)
		{
			cout << "One of Fillcollor settings in Ellips invalid, now its 0";
			this->Fillcolor[i] = 0;
		}
		else this->Fillcolor[i] = Fillcolor[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (Bordercolor[i] > 256 || Bordercolor[i] < 0)
		{
			cout << "One of Bordercollor settings in Ellips invalid, now its 0";
			this->Bordercolor[i] = 0;
		}
		else this->Bordercolor[i] = Bordercolor[i];
	}
}

//копирование
//конструкторы
HyperLink::HyperLink(const HyperLink& a)
{
	for (int i = 0; i < 20; i++)
	{
		this->url[i] = a.url[i];
	}
}
//операторы
OS& OS::operator=(const OS& other)
{
	this->Visible = other.Visible;
	this->x = other.x;
	this->y = other.y;
	this->height = other.height;
	this->width = other.width;
	return *this;
}

Ellips& Ellips::operator=(const Ellips& other)
{
	for (int i = 0; i < 3; i++)
	{
		this->Bordercolor[i] = other.Bordercolor[i];
		this->Fillcolor[i] = other.Fillcolor[i];
	}
	return *this;
}
Text& Text::operator=(const Text& other)
{
	for (int i = 0; i < 20; i++)
	{
		this->txt[i] = other.txt[i];
	}
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = other.color[i];
	}
	return *this;
}
Button& Button::operator=(const Button& other)
{
	for (int i = 0; i < 20; i++)
	{
		this->ToolTipText[i] = other.ToolTipText[i];
	}
	return *this;
}
TextBox& TextBox::operator=(const TextBox& other)
{
	this->readonly = other.readonly;
	return *this;
}

HyperLink& HyperLink::operator=(const HyperLink& other)
{
	for (int i = 0; i < 20; i++)
	{
		url[i] = other.url[i];
	}
	return *this;
}

//перемещение
//конструкторы
HyperLink::HyperLink(HyperLink&& other)
{
	for (int i = 0; i < 20; i++)
	{
		url[i] = other.url[i];
		other.url[i] = 0;
	}
}
//операторы
OS& OS::operator=(OS&& other)
{
	this->Visible = other.Visible;
	this->x = other.x;
	this->y = other.y;
	this->height = other.height;
	this->width = other.width;
	other.Visible = 0;
	other.x = 0;
	other.y = 0;
	other.height = 0;
	other.width = 0;
	return *this;
}
HyperLink& HyperLink::operator=(HyperLink&& other)
{
	for (int i = 0; i < 20; i++)
	{
		url[i] = other.url[i];
		other.url[i] = 0;
	}
	return *this;
}
TextBox& TextBox::operator=(TextBox&& other)
{
	this->readonly = other.readonly;
	other.readonly = 0;
	return *this;
}
Text& Text::operator=(Text&& other)
{
	for (int i = 0; i < 20; i++)
	{
		this->txt[i] = other.txt[i];
		other.txt[i] = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		this->color[i] = other.color[i];
		other.color[i] = 0;
	}
	return *this;
}

Button& Button::operator=(Button&& other)
{
	for (int i = 0; i < 20; i++)
	{
		this->ToolTipText[i] = other.ToolTipText[i];
		other.ToolTipText[i] = 0;
	}
	return *this;
}

Ellips& Ellips::operator=(Ellips&& other)
{
	for (int i = 0; i < 3; i++)
	{
		this->Bordercolor[i] = other.Bordercolor[i];
		this->Fillcolor[i] = other.Fillcolor[i];
		other.Bordercolor[i] = 0;
		other.Fillcolor[i] = 0;
	}
	return *this;
}