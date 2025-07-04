#include "stdafx.h"
#include "Ball.h"
#include "Bat.h"
#include "PongUI.h"
#include "SceneGame.h"
#include "SceneGame2.h"

Ball::Ball(const std::string& name)
	:GameObject(name)
{
}

void Ball::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	shape.setPosition(pos);
}

void Ball::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	shape.setRotation(rot);
}

void Ball::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	shape.setScale(s);
}

void Ball::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	shape.setOrigin(o);
}

void Ball::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	Utils::SetOrigin(shape, preset);
}

void Ball::Init()
{
	shape.setFillColor(sf::Color::Red);
	shape.setRadius(10.f);

	SetOrigin(Origins::BC);
}

void Ball::Release()
{
}

void Ball::Reset()
{
	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();
	if(!isPingPong)
	{
		SetPosition({ bound.width / 2.f, bound.height - 30.f });
	}
	else
	{
		SetPosition({ bound.width / 2.f, bound.height / 2.f });
	}

	direction = { 0.f, 0.f };
	speed = 0.f;

	float radius = shape.getRadius();
	minX = bound.left + radius;
	maxX = bound.left + bound.width - radius;
	minY = bound.top + radius * 2.f;
	if (!isPingPong)
	{
		maxY = bound.top + bound.height + 100.f;
	}
	else
	{
		maxY = bound.top + bound.height;
	}
}

void Ball::Update(float dt)
{
	sf::Vector2f pos = GetPosition() + direction * speed * dt;
	
	if (pos.x < minX)
	{
		pos.x = minX;
		direction.x *= -1.f;
	}
	else if (pos.x > maxX)
	{
		pos.x = maxX;
		direction.x *= -1.f;
	}

	if (pos.y < minY)
	{
		pos.y = minY;
		direction.y *= -1.f;
	}
	else if (pos.y > maxY)
	{
		if (SCENE_MGR.GetCurrentSceneId() == SceneIds::Game)
		{
			SceneGame* scene = (SceneGame*)SCENE_MGR.GetCurrentScene();
			scene->SetGameOver();
		}
		else if (SCENE_MGR.GetCurrentSceneId() == SceneIds::Game2)
		{
			pongUI->SetTextActive(true);
			pongUI->SetGameText("Press Enter to Restart!");
		}
	}

	if (bat != nullptr)
	{
		const sf::FloatRect& batBound = bat->GetGlobalBound();
		if (shape.getGlobalBounds().intersects(batBound))
		{
			pos.y = batBound.top;
			direction.y *= -1.f;
			pongUI->SetScore(pongUI->GetScore() + 10);
		}
	}

	SetPosition(pos);
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Ball::Fire(const sf::Vector2f& dir, float sp)
{
	direction = dir;
	speed = sp;
}
