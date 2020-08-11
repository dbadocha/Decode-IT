#include "SocialNetwork.h"


int main()
{
	SocialNetworkCreator creator;
	SocialNetwork socialNetwork = std::move(SocialNetwork(creator.createFromStdin()));
	return 0;
}