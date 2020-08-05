#include <set>
#include <iostream>
#include <vector>
#include <string>

typedef unsigned int uint;

uint subtrValues(uint value);
uint DigToInt_Max(std::multiset<uint> &vault);
uint DigToInt_Min(std::multiset<uint> &vault);
std::multiset<uint> IntToDig(uint value);
bool valueTest(uint value);

int main()
{
	uint tests = 0, value = 0, ret = 0;
	std::vector<int> solution{};
	std::cin >> tests;

	for (uint i = 0; i < tests; ++i)
	{
		ret = 0;
		std::cin >> value;

		if (valueTest(value))
		{
			while (value != 6174)
			{
				value = subtrValues(value);
				++ret;
			}
			std::cout << ret << "\n";
		}
		else
			std::cout << -1 << '\n';
	}
	return 0;
}

uint subtrValues(uint value)
{
	std::multiset<uint> digitsVault = IntToDig(value);
	uint v2 = DigToInt_Min(digitsVault);
	uint v1 = DigToInt_Max(digitsVault);
	return v1 - v2;
}

bool valueTest(uint value)
{
	uint digits = 4;
	std::set<uint> set;
	uint digit = 0;

	if (value > 9999 || value < 1000)
		return false;

	for (int i = digits - 1; i >= 0; --i)
	{
		digit = trunc(value / pow(10, i));
		value -= digit * pow(10, i);
		set.insert(digit);
	}
	return (set.size() > 1);
}

uint DigToInt_Max(std::multiset<uint> &vault)
{
	uint ret = 0;
	std::multiset<uint>::iterator it;

	uint power = 0;
	for (it = vault.begin(); it != vault.end(); ++it)
	{
		ret += (*it) * pow(10, power);
		++power;
	}
	return ret;
}

uint DigToInt_Min(std::multiset<uint> &vault)
{
	uint ret = 0, tmp = 0;
	std::multiset<uint>::reverse_iterator  rit;

	uint power = 0;
	for (rit = vault.rbegin(); rit != vault.rend(); ++rit)
	{
		tmp = (*rit) * pow(10, power);
		ret += tmp;
		++power;
	}
	return ret;
}

std::multiset<uint> IntToDig(uint value)
{
	uint digits = 4;
	std::multiset<uint> ret{};
	uint digit = 0;
	for (int i = digits - 1; i >= 0; --i)
	{
		digit = trunc(value / pow(10, i));
		value -= digit * pow(10, i);
		ret.insert(digit);
	}
	return ret;
}