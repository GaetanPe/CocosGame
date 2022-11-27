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
		float antDefaultSpeed = 100.f;
		OOBLimits currentXoob = OOBLimits::NONE;
		OOBLimits currentYoob = OOBLimits::NONE;

		cocos2d::PhysicsBody* antPhysicsBody;

		string pathToAntTexture = "../Resources/images/";

		// Animation
		// cocos2d::Sprite* antSprite;
		cocos2d::Vector<cocos2d::SpriteFrame*> antAnimFrames;
		cocos2d::Animation* antAnimation;
		cocos2d::Animate* antAnimate;
		
	public :

		Antity();
		Antity(float xx, float yy);
		~Antity();
		Antity* initAnt(float xx = 70, float yy = 300);
		void initAntSub(float xx = 70, float yy = 300);

		// Animation
		void runAntAnimation();

		void outOfBoundsCheckX();
		void outOfBoundsCheckY();

		void update(float dt) override;

		// "::create()" function
		CREATE_FUNC(Antity);
};