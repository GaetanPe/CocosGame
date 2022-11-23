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
	int count = 0;
	// if(antEntranceVetor.size())
}