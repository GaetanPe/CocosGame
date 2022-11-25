#pragma once


class AntGameTimer
{

    private :

        cocos2d::Label* timerLabel;

        string timerFontPath = "fonts/Marker Felt.ttf";
        
    public :

        float m_duration;

        AntGameTimer();
        AntGameTimer(float initialTimer);
        ~AntGameTimer();


        float getTimer() { return m_duration; }
        void setTimer(float timer) { timer = m_duration; }

        cocos2d::Label* getAntTimerLabel() { return timerLabel; }

        void initAntGameTimer(float initialTimer = 0.f);

        void updateTimer(float dt, bool positive);
};