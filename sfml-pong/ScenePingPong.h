#pragma once
#include "Scene.h"

class Bat;
class Ball;
class PingPongUI;

class ScenePingPong : public Scene
{
protected:
	Bat* bat1 = nullptr;
	Bat* bat2 = nullptr;
	Ball* ball = nullptr;
	PingPongUI* pingUI = nullptr;

	bool ballActive = false;

public:
	ScenePingPong();
	~ScenePingPong() override = default;

	void Init() override;
	void Enter() override;
	void Update(float dt) override;

	void SetGameOver();
};

