#include "framework.h"


AntSpawner::AntSpawner()
{
	initAntSpawner();
}

AntSpawner::AntSpawner(float xx, float yy)
{
	initAntSpawner(xx, yy);
}

AntSpawner::~AntSpawner()
{
}

void AntSpawner::initAntSpawner(float xx, float yy)
{
	spawnX = xx;
	spawnY = xx;

	lastAntSpawnTime = 0.f;

	// Sprite
	setPosition(spawnX, spawnY);
	setTexture(pathToAntSpawnerTexture + "block.png");

	// Update
	scheduleUpdate();
}



void AntSpawner::spawn()
{
	Antity* pAnt = Antity::create() -> initAnt(spawnX, spawnY);
	antSpawnVector.push_back(pAnt);

    getAntScene() -> addChild(pAnt);
}


void AntSpawner::updateSpawner(float dt)
{
	AntGameTimer* gameSceneTimer = getAntScene() -> getSceneTimer();
	float currentTime = gameSceneTimer -> getTimer();

	// Once timer for the next ant to spawn is done...
	if((currentTime - lastAntSpawnTime) > antSpawnTime)
	{
		spawn();
		lastAntSpawnTime = currentTime;
	}
}