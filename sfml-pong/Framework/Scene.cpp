#include "stdafx.h"
#include "Scene.h"

Scene::Scene(SceneIds id)
	: Id(id)
{
}

void Scene::Init()
{
	for (auto obj : gameObjects)
	{
		obj->Init();
	}
	for (GameObject* obj : objectsToAdd)
	{
		obj->Init();
	}
}

void Scene::Release()
{
	for (auto obj : gameObjects)
	{
		obj->Release();
		delete obj;
	}
	gameObjects.clear();
}

void Scene::Enter()
{
	TEXTURE_MGR.Load(texIds);
	FONT_MGR.Load(fontIds);
	SOUNDBUFFER_MGR.Load(soundIds);

	for (auto obj : gameObjects)
	{
		obj->Reset();
	}
	for (GameObject* obj : objectsToAdd)
	{
		obj->Reset();
	}
}

void Scene::Exit()
{
	TEXTURE_MGR.Unload(texIds);
	FONT_MGR.Unload(fontIds);
	SOUNDBUFFER_MGR.Unload(soundIds);
}

void Scene::Update(float dt)
{
	for (auto obj : gameObjects)
	{
		if(obj->GetActive())
		{
			obj->Update(dt);
		}
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	std::list<GameObject*> sortObjects(gameObjects);

	sortObjects.sort(DrawOrderComparer());

	for (auto obj : sortObjects)
	{
		if (obj->GetActive())
		{
			obj->Draw(window);
		}
	}

	for (GameObject* obj : objectsToAdd)
	{
		if (std::find(gameObjects.begin(), gameObjects.end(), obj) == gameObjects.end())
		{
			gameObjects.push_back(obj);
		}
	}
	objectsToAdd.clear();

	for (GameObject* obj : objectsToRemove)
	{
		gameObjects.remove(obj);
	}
	objectsToRemove.clear();
}

GameObject* Scene::AddGameObject(GameObject* go)
{
	objectsToAdd.push_back(go);
	return go;
}

void Scene::RemoveGameObject(GameObject* go)
{
	go->SetActive(false);
	objectsToRemove.push_back(go);
}

GameObject* Scene::FindGameObject(const std::string& name)
{
	for (auto obj : gameObjects)
	{
		if (obj->GetName() == name)
		{
			return obj;
		}
	}
	return nullptr;
}
