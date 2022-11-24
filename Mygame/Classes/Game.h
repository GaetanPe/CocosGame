#pragma once
class Game: public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	
	//Initialize
	bool init() override;
	CREATE_FUNC(Game);
	//update
	void update(float) override;
	
	//getters
	float getTimer() { return m_duration; }

	//setters 
	void setTimer(float timer) { timer = m_duration; }

	//utilities
	bool gameOver();

	
	
private:
	
	float m_count = 0.f;
	float m_duration = 300.f;
};

