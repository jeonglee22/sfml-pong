#include "stdafx.h"
#include "Ball.h"
#include "Bat.h"
#include "PingPongUI.h"
#include "SceneGame.h"
#include "ScenePingPong.h"

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

	blurPos.clear();
	blurShape.clear();
	SetMotionBlur(3);
	

	direction = { 0.f, 0.f };
	speed = 0.f;

	float radius = shape.getRadius();
	minX = !isPingPong ? bound.left + radius : bound.left - 50.f;
	maxX = !isPingPong ? bound.left + bound.width - radius : bound.left + bound.width + 50.f;
	minY = bound.top + radius * 2.f;
	maxY = !isPingPong ? bound.top + bound.height + 100.f : maxY = bound.top + bound.height;

	blurDeltaTime = 0.f;
}

void Ball::Update(float dt)
{
	sf::Vector2f pos = GetPosition() + direction * speed * dt;
	
	if(!isPingPong)
	{
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
	}
	else
	{
		if (pos.x < minX)
		{
			if (!pingUI->GetTextActive())
			{
				pingUI->SetGameText("Press Enter to Restart");
				pingUI->SetTextActive(true);
				pingUI->SetScore2(pingUI->GetScore2() + 1);
				if (pingUI->GetScore2() >= 5)
				{
					pingUI->SetWinText("Player  2  Win");
					pingUI->SetWinTextActive(true);
				}
			}
			/*ScenePingPong* scene = (ScenePingPong*)SCENE_MGR.GetCurrentScene();
			scene->SetGameOver();*/
		}
		else if (pos.x > maxX)
		{
			if(!pingUI->GetTextActive())
			{
				pingUI->SetGameText("Press Enter to Restart");
				pingUI->SetTextActive(true);
				pingUI->SetScore1(pingUI->GetScore1() + 1);
				if (pingUI->GetScore1() >= 5)
				{
					pingUI->SetWinText("Player  1  Win");
					pingUI->SetWinTextActive(true);
				}
			}
			/*ScenePingPong* scene = (ScenePingPong*)SCENE_MGR.GetCurrentScene();
			scene->SetGameOver();*/
		}
	}

	if (pos.y < minY)
	{
		pos.y = minY;
		direction.y *= -1.f;
	}
	else if (pos.y > maxY)
	{
		if (!isPingPong)
		{
			SceneGame* scene = (SceneGame*)SCENE_MGR.GetCurrentScene();
			scene->SetGameOver();
		}
		else
		{
			pos.y = maxY;
			direction.y *= -1.f;
		}
	}

	if (bat1 != nullptr)
	{
		const sf::FloatRect& batBound = bat1->GetGlobalBound();
		if (shape.getGlobalBounds().intersects(batBound))
		{
			pos.x = batBound.left + batBound.width + shape.getRadius();
			direction.x *= -1.f;
		}
	}
	if (bat2 != nullptr)
	{
		const sf::FloatRect& batBound = bat2->GetGlobalBound();
		if (shape.getGlobalBounds().intersects(batBound))
		{
			pos.x = batBound.left - shape.getRadius();
			direction.x *= -1.f;
		}
	}

	SetPosition(pos);

	blurDeltaTime += FRAMEWORK.GetDeltaTime();
	if(blurDeltaTime > totalBlurDeltaTime)
	{
		if (blurPos.size() == blurCount)
		{
			blurPos.pop_front();
		}
		blurPos.push_back(pos);

		int i = 0;
		for (auto& blur : blurPos)
		{
			blurShape[i++].setPosition(blur);
		}
		blurDeltaTime = 0.f;
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	for (auto blur : blurShape)
	{
		window.draw(blur);
	}
	window.draw(shape);
}

void Ball::Fire(const sf::Vector2f& dir, float sp)
{
	direction = dir;
	speed = sp;
}

void Ball::Start(float sp)
{
	sf::Vector2f dir;
	int right = Utils::RandomRange(0,2);
	dir.x = Utils::RandomRange(0.5f, 1.f);
	dir.y = Utils::RandomRange(-0.5f, 0.5f);
	if (!right)
		dir.x *= -1.f;
	Utils::Normalize(dir);
	direction = dir;
	speed = sp;
}

void Ball::SetMotionBlur(int count)
{
	blurCount = count;
	for (int i = 1; i <= count; i++)
	{
		sf::CircleShape newShape = shape;
		newShape.setFillColor(sf::Color(
			shape.getFillColor().r * i / count,
			shape.getFillColor().g * i / count,
			shape.getFillColor().b * i / count,
			shape.getFillColor().a));
		blurShape.push_back(newShape);
	}
}
