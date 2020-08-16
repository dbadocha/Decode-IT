#include "SocialNetwork.h"
#include "Bitset.h"
#include <limits>


int main()
{
	//SocialNetwork socialNetwork;

	SocialNetworkCreator create;
	ActorsMap map = create.createFromStdin();
	TakeoverStrategy_MapsProduct str(map);
	TakeoverList list = {};
	str.findDiscrepancy(list, map.begin()->second);

	return 0;
}