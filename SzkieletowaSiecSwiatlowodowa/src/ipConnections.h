#pragma once
#include <vector>

//prosi si� o klas�
struct IPconnections
{
	std::vector<int> IP;
	std::vector<IPconnections> connections;
};

