#pragma once


class AntSpawner : public cocos2d::Sprite
{
	private :
		float spawnX;
		float spawnY;

		string pathToAntSpawnerTexture = "../Resources/images/";

		vector<Antity*> antSpawnVector;
		float antSpawnTime = 2.f; // Par défaut à 2 (secondes je suppose ?)

		float lastAntSpawnTime;

		int maxAntSpawns = 3;

	public :

		AntSpawner();
		AntSpawner(float xx, float yy);
		~AntSpawner();
		void initAntSpawner(float xx = 0, float yy = 0);

		void spawn();
		// void update(float dt) override;
		void updateSpawner(float dt);
};