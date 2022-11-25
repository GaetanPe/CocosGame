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
    if (!Layer::init())
        return false;


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
/*                            Game over                              */
/*-------------------------------------------------------------------*/

bool AntScene::gameOver()
{
    return true;
}


/*-------------------------------------------------------------------*/
/*                              Update                               */
/*-------------------------------------------------------------------*/

void AntScene::update(float dt)
{
    auto director = Director::getInstance();
    auto dirVisibleOrigin = director -> getVisibleOrigin();
    auto dirVisibleSize = director -> getVisibleSize();

    m_count += dt;
    float gameTimer = getTimer();
    gameTimer -= m_count;
    auto timer = Label::createWithTTF(to_string(gameTimer), "fonts/Marker Felt.ttf", 24);

    if (timer == nullptr)
        problemLoading("'fonts/Marker Felt.ttf'");
    else
    {
        // Position the label on the center of the screen
        timer -> setPosition(Vec2(dirVisibleOrigin.x + dirVisibleSize.width / 2, dirVisibleOrigin.y + dirVisibleSize.height - (timer -> getContentSize().height)));

        // Add the label as a child to this layer
        this -> addChild(timer, 1);
    }

    if (gameTimer < 1)
    {
        gameOver();
        auto scene = HelloWorld::createScene();
        director -> replaceScene(scene);
    }
}