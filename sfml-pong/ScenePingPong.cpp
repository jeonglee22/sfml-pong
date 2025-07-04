#include "stdafx.h"
#include "ScenePingPong.h"
#include "Bat.h"
#include "Ball.h"

ScenePingPong::ScenePingPong()
	:Scene(SceneIds::PingPong)
{
}

void ScenePingPong::Init()
{
	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();

	bat1 = (Bat*)AddGameObject(new Bat());
	bat1->SetInitPosition({ bound.left + 20.f, bound.height / 2.f });
	bat1->SetPingPong(true);
	bat2 = (Bat*)AddGameObject(new Bat());
	bat2->SetInitPosition({ bound.left + bound.width - 20.f, bound.height / 2.f });
	bat2->SetPingPong(true);
	ball = (Ball*)AddGameObject(new Ball());

	Scene::Init();
}

void ScenePingPong::Enter()
{
	Scene::Enter();
}

void ScenePingPong::Update(float dt)
{
	Scene::Update(dt);
}