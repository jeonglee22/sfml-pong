#pragma once
#include "Scene.h"
class Bat;
class Ball;

class SceneGame : public Scene
{
protected:
    Bat* bat;
    Ball* ball;

    bool ballActive = false;

public:
    SceneGame();
    ~SceneGame() override = default;

    void Init() override;
    void Enter() override;

    void Update(float dt) override;

    void SetGameOver();
};

