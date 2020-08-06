#include "ipConverter.h"

std::vector<int> stringToIntIP(std::string & ipString)
{
	std::vector<int> retIParray;

	int startPos = 0;
	int endPos = ipString.find('.');
	int len = endPos - startPos;
	std::string tmpIPsubstr = ipString.substr(startPos, len);
	int tempIPint = std::stoi(tmpIPsubstr);
	retIParray.push_back(tempIPint);

	while (endPos != std::string::npos)
	{
		startPos = endPos + 1;
		endPos = ipString.find('.', startPos);
		len = endPos - startPos;
		tmpIPsubstr = ipString.substr(startPos, len);
		tempIPint = std::stoi(tmpIPsubstr);
		retIParray.push_back(tempIPint);
	}
	return retIParray;
}

std::string intToStringIP(std::vector<int>& IP)
{
	std::string ret = {};

	for (auto it = IP.begin(); it != IP.end(); ++it)
	{
		ret += std::to_string(*it);
		if (it != IP.end() - 1)
			ret += ".";
	}
	return ret;
}