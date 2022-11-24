#pragma once


class AntSpawner : public cocos2d::Sprite
{
	private :
		float spawnX;
		float spawnY;

		vector<Antity*> antEntranceVector;
		float antSpawnTime = 2.f; // Par d�faut � 2 (secondes je suppose ?)

	public :

		AntSpawner();
		AntSpawner(float xx, float yy);
		~AntSpawner();

		void spawn();
		void update(float dt) override;
};