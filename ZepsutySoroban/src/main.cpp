#include <iostream>
#include <cmath>

typedef unsigned int uint;

int main()
{
	uint columns = 0, beads = 0;
	std::cin >> columns >> beads;

	uint ret = 1, tmp = 0;
	uint magicValue = columns + beads;
	
	for (int i = columns; i > 0; --i)
	{
		tmp = trunc(magicValue / i);
		magicValue -= tmp;
		ret *= tmp;
	}

	ret *=  pow(2, columns);
	std::cout << ret;

	return 0;
}