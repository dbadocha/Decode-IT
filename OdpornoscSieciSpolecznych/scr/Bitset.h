#pragma once
#include "SocialNetwork.h"
#include <bitset>

typedef unsigned long long bitsetBase;
class Bitset
{
public:
	Bitset(size_t size);
	size_t size();
	int setBit(unsigned int bitPos);
	int resetBit(unsigned int bitPos);
	bool isMax();
	Bitset operator^ (const Bitset &rhs) const;
	Bitset operator| (const Bitset &rhs) const;

private:
	int posInContainer(unsigned int bitPos);
	std::vector<bitsetBase> _list = {};
	size_t _size = 0;
	size_t _bitsetCellSize = 0;
};