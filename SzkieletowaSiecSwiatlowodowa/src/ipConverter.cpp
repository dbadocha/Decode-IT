#include "ipConverter.h"

std::vector<int> stringToIntIP(const std::string & ipString)
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

std::string intToStringIP(const std::vector<int> & ip)
{
	std::string ret = {};

	for (auto it = ip.begin(); it != ip.end(); ++it)
	{
		ret += std::to_string(*it);
		if (it != ip.end() - 1)
			ret += ".";
	}
	return ret;
}