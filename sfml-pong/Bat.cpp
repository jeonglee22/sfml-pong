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
	shape.setSize({100.f,5.f});
	shape.setFillColor(sf::Color::White);

	SetOrigin(Origins::TC);
}

void Bat::Release()
{
}

void Bat::Reset()
{
	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();
	shape.setPosition({bound.width / 2.f, bound.height - 20.f});
}

void Bat::Update(float dt)
{
}

void Bat::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
