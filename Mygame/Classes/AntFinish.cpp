#include "framework.h"


AntFinish::AntFinish()
{
	initAntFinish();
}

AntFinish::AntFinish(float xx, float yy)
{
	initAntFinish(xx, yy);
}

AntFinish::~AntFinish()
{
}

void AntFinish::initAntFinish(float xx, float yy)
{
	finishX = xx;
	finishY = yy;

	// Sprite
	setPosition(finishX, finishY);
	setTexture(pathToAntFinishTexture + "out.png");

	// Update
	scheduleUpdate();
}


void AntFinish::despawn(Antity* ant)
{
	antFinishVector.push_back(ant);

	getAntScene() -> removeChild(ant);

	CC_SAFE_DELETE(ant);
}

bool AntFinish::checkFinishWithThreshold(Antity* ant)
{
	return ant -> getPosition().x >= this -> getPosition().x - finishThresholdX &&
		   ant -> getPosition().x <= this -> getPosition().x + finishThresholdX &&
		   ant -> getPosition().y >= this -> getPosition().y - finishThresholdY &&
		   ant -> getPosition().y <= this -> getPosition().y + finishThresholdY;
}

void AntFinish::updateFinish(float dt, AntScene* scene)
{
	vector<Antity*> pVector = scene -> getAntVector();

	// If the ant is at the same coordinates of the finish...
	for(Antity* ant : pVector)
	{
		if(checkFinishWithThreshold(ant))
			despawn(ant);
	}
}