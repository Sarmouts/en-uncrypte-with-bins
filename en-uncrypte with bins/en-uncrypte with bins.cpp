#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "C:\Users\user\source\Headers\binary_numbers.h"

void encrypte(std::string str, int* key)
{
	bin a;
	std::ofstream out{ "encmes.txt" };
	std::ofstream ot{ "key.txt" };
	for (size_t i = 0; i < str.length(); i++)
	{
		a = itbin(str[i]);
		key[i] = a.size();
		for (int j = a.size() - 1; j >= 0; j--)
		{
			out << a[j];
		}
		ot << key[i] << " ";
	}
	out.close();
	ot.close();
}
void ReadKey(std::vector<int>* key)
{
	int a;
	std::ifstream in{ "key.txt" };
	while (in >> a)
	{
		(*key).push_back(a);
	}
	in.close();
}
void uncrypte(std::vector<int> key)
{
	std::ifstream in{ "encmes.txt" };
	std::ofstream out{ "uncmes.txt" };
	int j = 0;
	int p = 0;
	std::string temp;
	in >> temp;
	in.close();
	for (int j = 0; j < key.size(); j++)
	{
		bin a(key[j]);
		for (int i = 1; i <= key[j]; i++, p++)
		{
			a[key[j] - i] = temp[p] - '0';
		}
		out << static_cast<char>(binti(a));
	}
	out.close();
}
int main()
{
	int k;
	std::cin >> k;
	if (k == 0)
	{
		std::ifstream in{ "uncmes.txt" };
		std::string mes;
		std::getline(in, mes);
		in.close();
		int* key = new int[mes.length()];
		encrypte(mes, key);
	}
	else
	{
		std::vector<int> key;
		ReadKey(&key);
		uncrypte(key);
	}
}