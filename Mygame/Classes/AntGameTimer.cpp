#include "framework.h"


AntGameTimer::AntGameTimer()
{
    initAntGameTimer();
}

AntGameTimer::~AntGameTimer()
{

}


void AntGameTimer::initAntGameTimer()
{
    // Creates the label
    timerLabel = cocos2d::Label::createWithTTF(to_string((int) m_duration), timerFontPath, 24);
    timerLabel -> setTextColor(cocos2d::Color4B::WHITE);

    // Position the label on the center of the screen
    auto director = cocos2d::Director::getInstance();
    auto dirVisibleOrigin = director -> getVisibleOrigin();
    auto dirVisibleSize = director -> getVisibleSize();
    timerLabel -> setPosition(cocos2d::Vec2(dirVisibleSize.width / 2, dirVisibleSize.height - (timerLabel -> getContentSize().height)));
}


void AntGameTimer::updateTimer(float dt)
{
    m_duration -= dt;

    timerLabel -> setString(to_string((int) m_duration));
}