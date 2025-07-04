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
	bat1->SetOrigin(Origins::MR);
	bat1->AddMoveKeys(sf::Keyboard::W);
	bat1->AddMoveKeys(sf::Keyboard::S);

	bat2 = (Bat*)AddGameObject(new Bat());
	bat2->SetInitPosition({ bound.left + bound.width - 20.f, bound.height / 2.f });
	bat2->SetPingPong(true);
	bat2->SetOrigin(Origins::ML);
	bat2->AddMoveKeys(sf::Keyboard::Up);
	bat2->AddMoveKeys(sf::Keyboard::Down);

	ball = (Ball*)AddGameObject(new Ball());
	ball->SetPingPong(true);

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