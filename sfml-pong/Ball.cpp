#include "stdafx.h"
#include "Ball.h"

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

	SetOrigin(Origins::MC);
}

void Ball::Release()
{
}

void Ball::Reset()
{
	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();
	SetPosition({ bound.width / 2.f, bound.height - 30.f});
}

void Ball::Update(float dt)
{
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
