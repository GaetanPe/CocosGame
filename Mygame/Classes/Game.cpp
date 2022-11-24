#include "framework.h"

USING_NS_CC;

cocos2d::Scene* Game::createScene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = Game::create();
	scene->addChild(layer);
	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

//Initialize
bool Game::init()
{
	if (!Layer::init())
	{
		return false;
	}
	this->scheduleUpdate();
	return true;
}

//update
void Game::update(float dt)
{
	auto director = Director::getInstance();
	auto dirVisibleOrigin = director -> getVisibleOrigin();
	auto dirVisibleSize = director -> getVisibleSize();
	
	m_count += dt;
	float gameTimer = getTimer();
	gameTimer -=  m_count;
	auto timer = Label::createWithTTF(to_string(gameTimer), "fonts/Marker Felt.ttf", 24);

	if (timer == nullptr)
		problemLoading("'fonts/Marker Felt.ttf'");
	else
	{
		// position the label on the center of the screen
		timer -> setPosition(Vec2(dirVisibleOrigin.x + dirVisibleSize.width / 2, dirVisibleOrigin.y + dirVisibleSize.height - (timer -> getContentSize().height)));

		// add the label as a child to this layer
		this -> addChild(timer, 1);
	}

	if (gameTimer < 1) 
	{
		gameOver();
		auto scene = HelloWorld::createScene();
		director -> replaceScene(scene);
	}
	
}

//utilities
bool Game::gameOver()
{
	return true;
}