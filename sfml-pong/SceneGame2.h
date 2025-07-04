#pragma once
#include "Scene.h"
class Bat;
class Ball;
class PongUI;

class SceneGame2 : public Scene
{
protected:
    Bat* bat;
    Ball* ball;
    PongUI* pongUI;

    bool ballActive = false;

public:
    SceneGame2();
    ~SceneGame2() override = default;

    void Init() override;
    void Enter() override;

    void Update(float dt) override;

    void SetGameOver();
};

