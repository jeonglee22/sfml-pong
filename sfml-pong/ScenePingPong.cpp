#include "stdafx.h"
#include "ScenePingPong.h"
#include "Bat.h"
#include "Ball.h"
#include "PingPongUI.h"

ScenePingPong::ScenePingPong()
	:Scene(SceneIds::PingPong)
{
}

void ScenePingPong::Init()
{
	fontIds.push_back("fonts/DS-DIGIT.TTF");

	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();

	bat1 = (Bat*)AddGameObject(new Bat("Bat1"));
	bat1->SetInitPosition({ bound.left + 20.f, bound.height / 2.f });
	bat1->SetPingPong(true);
	bat1->SetOrigin(Origins::MR);
	bat1->AddMoveKeys(sf::Keyboard::W);
	bat1->AddMoveKeys(sf::Keyboard::S);

	bat2 = (Bat*)AddGameObject(new Bat("Bat2"));
	bat2->SetInitPosition({ bound.left + bound.width - 20.f, bound.height / 2.f });
	bat2->SetPingPong(true);
	bat2->SetOrigin(Origins::ML);
	bat2->AddMoveKeys(sf::Keyboard::Up);
	bat2->AddMoveKeys(sf::Keyboard::Down);

	ball = (Ball*)AddGameObject(new Ball("Ball"));
	ball->SetPingPong(true);

	pingUI = (PingPongUI*)AddGameObject(new PingPongUI("PingPongUI"));
	ball->SetPingPong(pingUI);

	Scene::Init();
}

void ScenePingPong::Enter()
{
	ballActive = false;

	Scene::Enter();
}

void ScenePingPong::Update(float dt)
{
	Scene::Update(dt);

	if (!ballActive)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			ballActive = true;
			ball->Start(500.f);
		}
	}
}