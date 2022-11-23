#pragma once


enum OOBLimits
{
	NONE,
	OOB_LEFT,
	OOB_RIGHT,
	OOB_UP,
	OOB_DOWN
};

class Antity : public cocos2d::Sprite
{
	private :
		float antX;
		float antY;
		float antSpeedX;
		float antSpeedY;
		float antDefaultSpeed = 300.f;
		OOBLimits currentXoob = OOBLimits::NONE;
		OOBLimits currentYoob = OOBLimits::NONE;

		cocos2d::PhysicsBody* antPhysicsBody;

		string pathToAntTexture = "../Resources/images/";

		
	public :
		Antity();
		Antity(float xx, float yy);
		~Antity();
		Antity* initAnt();
		void initAntSub(float xx = 0, float yy = 1000);

		// "::create()" function
		CREATE_FUNC(Antity);

		void outOfBoundsCheckX();
		void outOfBoundsCheckY();

		void update(float dt) override;
};