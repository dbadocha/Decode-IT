#include "Bitset.h"

Bitset::Bitset(size_t size)
	:
	_size(size),
	_bitsetCellSize(sizeof(bitsetBase) * 8)
{
	int arraySize = ceil(static_cast<float>(size) / _bitsetCellSize);
	_list.resize(arraySize, 0);
}

size_t Bitset::size()
{
	return _size;
}

int Bitset::setBit(unsigned int bitPos)
{
	auto pos = posInContainer(bitPos);
	if (pos < 0)
		return -1;
	auto mask = bitPos - (_bitsetCellSize * pos);
	mask = pow(2, mask);
	_list[pos] |= mask;
	return 0;
}

int Bitset::resetBit(unsigned int bitPos)
{
	auto pos = posInContainer(bitPos);
	auto mask = bitPos - (_bitsetCellSize * pos);
	mask = !(1 << mask);
	_list[pos] &= mask;
	return 0;
}

bool Bitset::isMax()
{
	for (auto it : this->_list)
	{
		if (!it)
			return false;
	}
	return true;
}

Bitset Bitset::operator^(const Bitset &rhs) const
{
	Bitset ret(this->_list.size());
	auto lhsIt = this->_list.begin();
	auto rhsIt = rhs._list.begin();

	for (auto it : ret._list)
	{
		it = *lhsIt ^ *rhsIt;
		++lhsIt;
		++rhsIt;
	}
	return ret;
}

Bitset Bitset::operator|(const Bitset & rhs) const
{
	Bitset ret(this->_list.size());
	auto lhsIt = this->_list.begin();
	auto rhsIt = rhs._list.begin();

	for (auto it : ret._list)
	{
		it = *lhsIt | *rhsIt;
		++lhsIt;
		++rhsIt;
	}
	return ret;
}

int Bitset::posInContainer(unsigned int bitPos)
{
	if (bitPos < _size)
	{
		int posInContainer = bitPos / _bitsetCellSize;
		return posInContainer;
	}
	else
		return -1;
}
