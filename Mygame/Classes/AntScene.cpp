#include "framework.h"

USING_NS_CC;


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in AntScene.cpp\n");
}

void AntScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance() -> end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

/*-------------------------------------------------------------------*/
/*                          Physics methods                          */
/*-------------------------------------------------------------------*/


void AntScene::initPhysics()
{
    cocos2d::EventListenerPhysicsContact* contactListener = EventListenerPhysicsContact::create();
    contactListener -> onContactBegin = CC_CALLBACK_1(AntScene::onCollision, this);
    getEventDispatcher() -> addEventListenerWithSceneGraphPriority(contactListener, this);
}

void AntScene::setPhysicsBody(cocos2d::Sprite* sprite)
{
    cocos2d::PhysicsBody* body = PhysicsBody::createCircle(sprite -> getContentSize().width / 2);
    body -> setContactTestBitmask(true);
    body -> setDynamic(true);
    sprite -> setPhysicsBody(body);
}

bool AntScene::onCollision(PhysicsContact& contact)
{
    return true;
}



/*-------------------------------------------------------------------*/
/*                            Init scene                             */
/*-------------------------------------------------------------------*/


Scene* AntScene::createAntScene()
{
    Scene* antScene = Scene::createWithPhysics();
    antScene -> getPhysicsWorld() -> setGravity(Vect(.0f, -981.f));

    if(AntScene::debugHitboxes)
        antScene -> getPhysicsWorld() -> setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto antLayer = AntScene::create();
    antScene -> addChild(antLayer);

    return antScene;
}



bool AntScene::init()
{

    functionnalAntCode();

    return true;
}

void AntScene::functionnalAntCode()
{

    // Creating ants
    antVector.push_back(Antity::create() -> initAnt());
    //antVector.push_back(Antity::create() -> initAnt());
    //
    //for (int i = 0; i < antVector.size(); i++)
        addChild(antVector[0]);


    initPhysics();
}





void AntScene::update(float dt)
{
    
}