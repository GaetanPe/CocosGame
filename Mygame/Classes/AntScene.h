#pragma once

#include "cocos2d.h"

class Antity;
class AntSpawner;

class AntScene : public cocos2d::Layer
{
    private :

        // Debug - Hitboxes
        static const bool debugHitboxes = false;

        AntSpawner* antSpawner;
        vector<Antity*> antVector;

    public :

        // a selector callback
        void menuCloseCallback(cocos2d::Ref* pSender);

        void initPhysics();
        void setPhysicsBody(cocos2d::Sprite* sprite);
        bool onCollision(cocos2d::PhysicsContact& contact);


        static cocos2d::Scene* createAntScene();

        virtual bool init();

        void functionnalAntCode();

        void update(float dt) override;



        // implement the "static create()" method manually
        CREATE_FUNC(AntScene);
};
