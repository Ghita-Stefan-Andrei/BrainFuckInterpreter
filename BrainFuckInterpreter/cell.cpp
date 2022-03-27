#include "cell.h"
cell::cell(int c)
{
	this->value = c;
	if (c > MAX_8BIT)
	{
		this->value = MIN_8BIT;
	}
	else if (c < MIN_8BIT)
	{
		this->value = MIN_8BIT;
	}
}
cell::cell()
{
	this->value = 0;
}
void cell::inc()
{
	this->value++;
	if (this->value > MAX_8BIT)
	{
		this->value = MIN_8BIT;
	}
}
void cell::dec()
{
	this->value--;
	if (this->value < MIN_8BIT)
	{
		this->value = MAX_8BIT;
	}
}
bool cell::isz()
{
	return this->value == 0;
}
void cell::print()
{
	std::cout << (char)this->value;
}
void cell::operator = (const cell* arg)
{
	this->value = arg->value;
}