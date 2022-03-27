#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include"cell.h"
#define MAX_8BIT 255
#define MIN_8BIT 0
#define MemorySize 1000
template<typename T, typename TT>
TT convert(T a)
{
	std::stringstream ss;
	TT b;
	ss << a;
	ss >> b;
	return b;
}
int main()
{
	std::ifstream codeFile("BrainFuckCode.txt");
	std::vector<cell> memory(MemorySize);
	std::vector<std::string> code;
	std::vector<int> forI;
	int nrOfUsedCells = 1;
	double Pointer = 0;
	char c;
	while (codeFile >> c)
	{
		std::string character = convert<char, std::string>(c);
		if (character == "+" || character == "-" || character == ">" || character == "<" || character == "[" || character == "]" || character == "." || character == ",")
		{
			code.push_back(character);
		}
	}
	for (int com = 0; com < code.size(); com++)
	{
		if (code[com] == "+")
		{
			memory[Pointer].inc();
		}
		else if (code[com] == "-")
		{
			memory[Pointer].dec();
		}
		else if (code[com] == ">")
		{
			Pointer++;
			nrOfUsedCells++;
		}
		else if (code[com] == "<")
		{
			Pointer--;
		}
		else if (code[com] == ".")
		{
			memory[Pointer].print();
		}
		else if (code[com] == ",")
		{
			int t;
			std::cin >> t;
			cell temp(t);
			memory[Pointer] = temp;
		}
		else if (code[com] == "[")
		{
			forI.push_back(com);
		}
		else if (code[com] == "]")
		{
			if (!memory[Pointer].isz())
			{
				com = forI.back();
			}
			else
			{
				forI.pop_back();
			}
		}
	}
	return 0;
}