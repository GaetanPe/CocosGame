#pragma once

#include "cocos2d.h"

class Antity;
class AntSpawner;

class AntScene : public cocos2d::Layer
{
    private :

        // Debug - Hitboxes
        static const bool debugHitboxes = false;

        // Spawner
        AntSpawner* antSpawner;
        vector<Antity*> antVector;

        // Timer
        AntGameTimer* antSceneTimer;




    public :

        // a selector callback
        void menuCloseCallback(cocos2d::Ref* pSender);


        /*-------------------- Timer --------------------*/

        AntGameTimer* getSceneTimer() { return antSceneTimer; }

        /*-------------------- Init scene --------------------*/

        static cocos2d::Scene* createAntScene();
        virtual bool init();
        void functionnalAntCode();

        /*-------------------- Physics methods --------------------*/

        void initPhysics();
        void setPhysicsBody(cocos2d::Sprite* sprite);
        bool onCollision(cocos2d::PhysicsContact& contact);

        /*-------------------- Game over --------------------*/

        bool gameOver();

        /*-------------------- Update --------------------*/

        void update(float dt) override;



        // implement the "static create()" method manually
        CREATE_FUNC(AntScene);
};

AntScene* getAntScene();