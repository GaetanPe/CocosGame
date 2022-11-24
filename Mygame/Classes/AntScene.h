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

        float m_count = 0.f;
        float m_duration = 300.f;




    public :

        // a selector callback
        void menuCloseCallback(cocos2d::Ref* pSender);


        /*-------------------- Timer --------------------*/

        float getTimer() { return m_duration; }
        void setTimer(float timer) { timer = m_duration; }

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