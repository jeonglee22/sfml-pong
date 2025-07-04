#include "stdafx.h"
#include "SceneGame.h"
#include "Bat.h"
#include "Ball.h"

SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

void SceneGame::Init()
{
	bat = (Bat*) AddGameObject(new Bat("Bat"));
	ball = (Ball*) AddGameObject(new Ball("Ball"));

	Scene::Init();
}

void SceneGame::Enter()
{
	Scene::Enter();
}
