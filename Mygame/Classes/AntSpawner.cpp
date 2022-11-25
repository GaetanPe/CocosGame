#include "framework.h"


AntSpawner::AntSpawner()
{
	spawnX = 0;
	spawnY = 0;
}

AntSpawner::AntSpawner(float xx, float yy)
{
	spawnX = xx;
	spawnY = yy;
}

AntSpawner::~AntSpawner()
{
}

void AntSpawner::spawn()
{
	Antity* pAnt = Antity::create();
	pAnt -> initAnt();
    antEntranceVector.push_back(pAnt);

    addChild(pAnt);
}


void AntSpawner::update(float dt)
{
	int antCount = 0;
	float currentTime = 0; // = Game::getTime(); // A changer avec l'introduction du temps de Game
	float lastAntSpawnTime = currentTime; // A changer avec l'introduction du temps de Game
	
	// While there's still ants in the spawner...
	while(antCount < antEntranceVector.size())
	{
		// Timer for the next ant to spawn
		while((currentTime - lastAntSpawnTime) < antSpawnTime)
		{
			// currentTime = Game::getTimer(); // Timer pas encore global, à régler
		}

		// Once timer for the next ant to spawn is done...
		lastAntSpawnTime = currentTime;
		antCount++;
	}
}