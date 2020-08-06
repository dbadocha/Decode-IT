#include <iostream>
#include <vector>

void getDigitsStream(std::vector<int> &digitStream);
std::vector<int> decodeToInt(std::vector<int> &digitStream);
std::vector<char> decodeToASCII(std::vector<int> &&intStream);
std::vector<char> decodeToASCII(std::vector<int> &intStream);

int main()
{
	std::vector<int> digitStream{};
	std::vector<char> solution{};
	int noOfTests = 0;

	std::cin >> noOfTests;

	for (int i = 0; i < noOfTests; ++i)
	{
		digitStream.clear();
		solution.clear();

		getDigitsStream(digitStream);
		solution = decodeToASCII(decodeToInt(digitStream));
		for (char c : solution)
			std::cout << c;
		std::cout << '\n';
	}
	return 0;
}

void getDigitsStream(std::vector<int>& digitStream)
{
	int digit = 0, streamSize = 0;
	std::cin >> streamSize;
	streamSize *= 4;

	for (int i = 0; i < streamSize; ++i)
	{
		std::cin >> digit;
		digitStream.push_back(digit);
	}
	return;
}

std::vector<int> decodeToInt(std::vector<int>& digitStream)
{
	std::vector<int> ret{};
	int tmpValue = 0;

	if (digitStream.size() % 4 != 0)
		return ret;

	for (int i = 0; i < digitStream.size(); i += 4)
	{
		tmpValue = digitStream[i] * 10 + digitStream[i + 2];
		tmpValue += digitStream[i + 1] * 10 + digitStream[i + 3];
		ret.push_back(tmpValue);
	}

	return ret;
}

std::vector<char> decodeToASCII(std::vector<int>&& intStream)
{
	std::vector<int> tmpArray = intStream;
	return decodeToASCII(tmpArray);
}

std::vector<char> decodeToASCII(std::vector<int>& intStream)
{
	std::vector<char> ret{};

	for (int i : intStream)
	{
		ret.push_back(static_cast<char>(i));
	}
	return ret;
}
