#include "framework.h"

Antity::Antity()
{
    antX = 0;
    antY = 0;
    antSpeedX = antDefaultSpeed;
    antSpeedY = antDefaultSpeed;

    antPhysicsBody = nullptr;
}

Antity::Antity(float xx, float yy)
{
    antX = xx;
    antY = yy;
    antSpeedX = antDefaultSpeed;
    antSpeedY = antDefaultSpeed;

    antPhysicsBody = nullptr;
}

Antity::~Antity()
{
}

Antity* Antity::initAnt(float xx, float yy)
{
    // Create sprite and make it use the physics properties
    setTexture(pathToAntTexture + "ant2.png");
    
    initAntSub(xx, yy);

    return this;
}

void Antity::initAntSub(float xx, float yy)
{
    antX = xx;
    antY = yy;

    setPosition(cocos2d::Vec2(antX, antY));
    setAnchorPoint(cocos2d::Vec2(.5f, 0)); // Bottom Mid
    setScaleX(-1.f); // If going to the right by default

    setVisible(true);


    // Creating physics body
    int antSpriteWidth = getContentSize().width;
    int antSpriteHeight = getContentSize().height;
    antPhysicsBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(antSpriteWidth, antSpriteHeight), cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f));
    antPhysicsBody -> setGravityEnable(true);

    antPhysicsBody -> setDynamic(true);

    // Creates movement
    antPhysicsBody -> setVelocity(cocos2d::Vec2(antSpeedX, antSpeedY));


    // Adapt physics transformations
    addComponent(antPhysicsBody);

    // Update
    scheduleUpdate();
}

void Antity::outOfBoundsCheckX()
{
    auto screenSize = cocos2d::Director::getInstance() -> getVisibleSize();
    antX = getPosition().x;

    // OOB Conditions
    if(antX < getContentSize().width / 2)
        currentXoob = OOBLimits::OOB_LEFT;
    else if(antX > screenSize.width - getContentSize().width / 2)
        currentXoob = OOBLimits::OOB_RIGHT;
    else
        currentXoob = OOBLimits::NONE;

    // Actions depending on conditions
    switch(currentXoob)
    {
        case OOBLimits::OOB_RIGHT :
            setPosition(cocos2d::Vec2(screenSize.width - getContentSize().width / 2, 0));
            antPhysicsBody -> setVelocity(cocos2d::Vec2(-antSpeedX, antPhysicsBody->getVelocity().y));
            setScaleX(1.f);
            break;

        case OOBLimits::OOB_LEFT :
            setPosition(cocos2d::Vec2(getContentSize().width / 2, 0));
            antPhysicsBody -> setVelocity(cocos2d::Vec2(antSpeedX, antPhysicsBody -> getVelocity().y));
            setScaleX(-1.f);
            break;

        default:
            break;
    }
}
void Antity::outOfBoundsCheckY()
{
    auto screenSize = cocos2d::Director::getInstance() -> getVisibleSize();
    antY = getPosition().y;

    // OOB Conditions
    if(antY < 0)
        currentYoob = OOBLimits::OOB_DOWN;
    else if(antY > screenSize.height - getContentSize().height)
        currentYoob = OOBLimits::OOB_UP;
    else
        currentYoob = OOBLimits::NONE;

    // Actions depending on conditions
    switch(currentYoob)
    {
        case OOBLimits::OOB_UP :
            setPosition(cocos2d::Vec2(antX, screenSize.height - getContentSize().height));
            antPhysicsBody -> setVelocity(cocos2d::Vec2(antPhysicsBody -> getVelocity().x, 0.0f));
            break;

        case OOBLimits::OOB_DOWN :
            setPosition(cocos2d::Vec2(antX, 0));
            antPhysicsBody -> setVelocity(cocos2d::Vec2(antPhysicsBody->getVelocity().x, 0.0f));
            break;

        default:
            break;
    }
}

void Antity::update(float dt)
{
    // Walls check
    // wallCollisionCheck();

    // Out of bounds check
    outOfBoundsCheckX();
    outOfBoundsCheckY();
}