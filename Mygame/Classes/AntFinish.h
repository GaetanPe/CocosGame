#pragma once


class AntFinish : public cocos2d::Sprite
{
	private :
	float finishX;
	float finishY;
	float finishThresholdX = 200.f;
	float finishThresholdY = 200.f;

	string pathToAntFinishTexture = "../Resources/images/";

	vector<Antity*> antFinishVector;

	public :

	AntFinish();
	AntFinish(float xx, float yy);
	~AntFinish();
	void initAntFinish(float xx = 0, float yy = 0);

	void despawn(Antity* ant);
	bool checkFinishWithThreshold(Antity* ant);
	void updateFinish(float dt, AntScene* scene);
};








