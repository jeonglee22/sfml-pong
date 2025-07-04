#pragma once
#include "Scene.h"

class Bat;
class Ball;

class ScenePingPong : public Scene
{
protected:
	Bat* bat1 = nullptr;
	Bat* bat2 = nullptr;
	Ball* ball = nullptr;

public:
	ScenePingPong();
	~ScenePingPong() override = default;

	void Init() override;
	void Enter() override;
	void Update(float dt) override;
};

