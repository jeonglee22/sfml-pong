#include "stdafx.h"
#include "SceneGame2.h"
#include "Bat.h"
#include "Ball.h"
#include "PongUI.h"

SceneGame2::SceneGame2()
	:Scene(SceneIds::Game2)
{
}

void SceneGame2::Init()
{
	fontIds.push_back("fonts/DS-DIGIT.TTF");

	bat = (Bat*)AddGameObject(new Bat("Bat"));
	ball = (Ball*)AddGameObject(new Ball("Ball"));
	ball->SetBat(bat);

	pongUI = (PongUI*)AddGameObject(new PongUI("PongUI"));
	ball->SetScore(pongUI);
	Scene::Init();
}

void SceneGame2::Enter()
{
	ballActive = false;

	Scene::Enter();
}

void SceneGame2::Update(float dt)
{
	Scene::Update(dt);

	if (!ballActive)
	{
		ball->SetPosition(bat->GetPosition());

		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			ballActive = true;

			sf::Vector2f dir = { 1.f, -1.f };
			Utils::Normalize(dir);
			ball->Fire(dir, 500.f);
		}
	}
}

void SceneGame2::SetGameOver()
{
	SCENE_MGR.ChangeScene(SceneIds::Game);
}
