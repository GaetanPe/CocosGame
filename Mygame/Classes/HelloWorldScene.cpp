#include "framework.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("images/exitButtons.png", "images/exitButtons.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'images/exitButtons.png' and 'images/exitButtons.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width;
        float y = origin.y + closeItem->getContentSize().height + 200;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menuClose = Menu::create(closeItem, NULL);
    menuClose->setPosition(Vec2::ZERO);
    this->addChild(menuClose, 1);

    /////////////////////////////
    // 3. add your codes below...
    auto startGame = MenuItemImage::create("images/buttonPlay.png","images/buttonPlay.png", CC_CALLBACK_1(HelloWorld::menuGameAccess, this));
    if (startGame == nullptr ||
        startGame->getContentSize().width <= 0 ||
        startGame->getContentSize().height <= 0)
    {
        problemLoading("'images/buttonPlay.png' and 'images/buttonPlay.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - startGame->getContentSize().width;
        float y = origin.y + startGame->getContentSize().height + 400;
        startGame->setPosition(Vec2(x, y));
    }

    auto menuGame = Menu::create(startGame, NULL);
    menuGame->setPosition(Vec2::ZERO);
    this->addChild(menuGame, 1);
    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Antsming", "fonts/Marker Felt.ttf", 34);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

}
void HelloWorld::menuGameAccess(Ref* pSender)
{
    //Change the cocos2d-x scene 
    Director::getInstance()->replaceScene(AntScene::createAntScene());

}