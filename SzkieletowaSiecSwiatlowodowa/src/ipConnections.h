#pragma once
#include <vector>

//prosi siê o klasê
struct IPconnections
{
	std::vector<int> IP;
	std::vector<IPconnections> connections;
};

