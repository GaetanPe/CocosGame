#pragma once

class Antity
{
	public :

		float x;
		float y;


		cocos2d::PhysicsBody* antPhysicsBody;
		cocos2d::Sprite* antSprite;

		Antity();
		~Antity();

		void initAnt();
};