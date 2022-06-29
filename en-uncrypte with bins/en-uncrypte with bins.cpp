#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "C:\Users\user\source\Headers\binary_numbers.h"

void encrypte()
{
	bin a;
	std::ifstream in{ "uncmes.txt" };
	std::ofstream out{ "encmes.txt" };
	std::ofstream ot{ "key.txt" };
	char ch;
	while (in >> std::noskipws >> ch)
	{
		a = itbin(ch);
		for (int j = a.size() - 1; j >= 0; j--)
		{
			out << a[j];
		}
		ot << a.size() << " ";
	}
	in.close();
	out.close();
	ot.close();
}
void uncrypte()
{
	std::ifstream in{ "encmes.txt" };
	std::ifstream inkey{ "key.txt" };
	std::ofstream out{ "uncmes.txt" };
	int p = 0;
	int k;
	std::string temp;
	in >> temp;
	in.close();
	while (inkey >> k)
	{
		bin a(k);
		for (int i = 1; i <= k; i++, p++)
		{
			a[k - i] = temp[p] - '0';
		}
		out << static_cast<char>(binti(a));
	}
	inkey.close();
	out.close();
}
int main()
{
	int k;
	std::cin >> k;
	if (k == 0)
		encrypte();
	else
		uncrypte();
}