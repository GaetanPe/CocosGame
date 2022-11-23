#include "cocos2d.h"
#include "HelloWorldScene.h"
#include"framework.h"

USING_NS_CC;

cocos2d::Scene* Game::createScene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = Game::create();
	scene->addChild(layer);
	return scene;
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
	m_count += dt;
	float gameTimer = getTimer();
	gameTimer -=  m_count;
	auto timer = Label::createWithTTF(to_string(gameTimer), "fonts/Marker Felt.ttf", 24);
	this->addChild(timer, 1);
	if (gameTimer < 1) 
	{
		gameOver();
		auto scene = HelloWorld::createScene();
		director->replaceScene(scene);
	}
	
}

//getters
float Game::getTimer()
{
	return m_duration;
}

//setters
void Game::setTimer(float timer)
{
	timer = m_duration;
}

//utilities
bool Game::gameOver()
{
	return true;
}