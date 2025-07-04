#pragma once
#include "GameObject.h"
class Ball : public GameObject
{
protected:
    sf::CircleShape shape;

public:
    Ball(const std::string& name = "");
    ~Ball() override = default;
    
    void SetPosition(const sf::Vector2f& pos) override;
    void SetRotation(float rot) override;
    void SetScale(const sf::Vector2f& s) override;
    void SetOrigin(const sf::Vector2f& o) override;
    void SetOrigin(Origins preset) override;

    // GameObject을(를) 통해 상속됨
    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
};

