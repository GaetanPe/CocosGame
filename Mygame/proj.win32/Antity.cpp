#include "framework.h"

Antity::Antity()
{
    initAnt();
}

Antity::~Antity()
{
    
}

void Antity::initAnt()
{
    // Create sprite and make it use the physics properties
    antSprite = cocos2d::Sprite::create("../Resources/images/ant.png");
    antSprite -> setPosition(cocos2d::Vec2(2 * antSprite -> getContentSize().width, 2 * antSprite -> getContentSize().height));
    antSprite -> setAnchorPoint(cocos2d::Vec2(0, 1)); // Top left
    antSprite -> setVisible(true);
    int antSpriteWidth = antSprite -> getContentSize().width;
    int antSpriteHeight = antSprite -> getContentSize().height;

    // Creating physics body
    antPhysicsBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(antSpriteWidth, antSpriteHeight), cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f));
    antPhysicsBody -> setDynamic(false);

    // Adapt physics transformations
    antSprite -> addComponent(antPhysicsBody);
}