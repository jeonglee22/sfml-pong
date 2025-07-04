#include "stdafx.h"
#include "Bat.h"

Bat::Bat(const std::string& name)
	:GameObject(name)
{
}

void Bat::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	shape.setPosition(pos);
}

void Bat::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	shape.setRotation(rot);
}

void Bat::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	shape.setScale(s);
}

void Bat::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	shape.setOrigin(o);
}

void Bat::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	Utils::SetOrigin(shape, preset);
}

void Bat::Init()
{
	if(!isPingPong)
	{
		shapeSize = { 100.f,5.f };
	}
	else
	{
		shapeSize = { 5.f,100.f };
	}
	shape.setSize(shapeSize);
	shape.setFillColor(sf::Color::White);

	SetOrigin(originPreset);
}

void Bat::Release()
{
}

void Bat::Reset()
{
	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();
	SetPosition(initPos);

	sf::Vector2f size = shape.getSize();
	minX = bound.left + size.x / 2.f;
	maxX = bound.left + bound.width - size.x / 2.f;
	minY = bound.top + size.y / 2.f;
	maxY = bound.top + bound.height - size.y / 2.f;
}

void Bat::Update(float dt)
{
	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();

	direction.y = InputMgr::GetAxis(Axis::Vertical);

	if ((name == "Bat1" && InputMgr::GetKey(sf::Keyboard::W) && direction.y < 0.f) ||
		(name == "Bat1" && InputMgr::GetKey(sf::Keyboard::S) && direction.y > 0.f) ||
		(name == "Bat2" && InputMgr::GetKey(sf::Keyboard::Up) && direction.y < 0.f) ||
		(name == "Bat2" && InputMgr::GetKey(sf::Keyboard::Down) && direction.y > 0.f))
	{
		sf::Vector2f pos = GetPosition() + direction * speed * dt;
		SetPosition({ pos.x, Utils::Clamp(pos.y, minY, maxY) });
	}
	//SetPosition({ Utils::Clamp(pos.x, minX, maxX), pos.y});
}

void Bat::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
