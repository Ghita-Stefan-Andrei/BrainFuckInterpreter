#pragma once
#include<iostream>
#define MAX_8BIT 255
#define MIN_8BIT 0
#define MemorySize 1000
class cell
{
private:
	int value;
public:
	cell(int c);
	cell();
	void inc();
	void dec();
	bool isz();
	void print();
	void operator = (const cell* arg);
};