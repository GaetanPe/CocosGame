#pragma once


class AntGameTimer
{

    private :

        cocos2d::Label* timerLabel;

        string timerFontPath = "fonts/Marker Felt.ttf";
        
    public :

        float m_duration = 300.f + 1.f; // + 1.f pour afficher un timer logique

        AntGameTimer();
        ~AntGameTimer();


        float getTimer() { return m_duration; }
        void setTimer(float timer) { timer = m_duration; }

        cocos2d::Label* getAntTimerLabel() { return timerLabel; }

        void initAntGameTimer();

        void updateTimer(float dt);
};