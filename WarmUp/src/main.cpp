#include <iostream>

typedef unsigned int uint;

int main()
{
	uint testsAmount = 0;
	std::cin >> testsAmount;

	uint squareMeters = 0, maxLoad = 0, bagMass = 0;
	uint totalMass = 0;
	
	for (int i = 0; i < testsAmount; ++i)
	{
		std::cin >> squareMeters >> maxLoad >> bagMass;
		totalMass = squareMeters * bagMass;

		if (totalMass > maxLoad)
			std::cout << "no\n";
		else
			std::cout << "yes\n";
	}

	return 0;
}