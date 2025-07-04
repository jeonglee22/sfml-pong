#pragma once
#include "GameObject.h"
class Bat : public GameObject
{
protected:
    sf::RectangleShape shape;
    sf::Vector2f shapeSize;

    sf::Vector2f initPos;
    std::vector<sf::Keyboard::Key> moveKeys;

    float speed = 500.f;
    sf::Vector2f direction;

    float minX = 0.f;
    float maxX = 0.f;
    float minY = 0.f;
    float maxY = 0.f;

    bool isPingPong = false;
    bool isMove = false;

public:
    Bat(const std::string& name = "");
    ~Bat() override = default;

    void SetInitPosition(const sf::Vector2f& pos) { initPos = pos; }

    void SetPosition(const sf::Vector2f& pos) override;
    void SetRotation(float rot) override;
    void SetScale(const sf::Vector2f& s) override;
    void SetOrigin(const sf::Vector2f& o) override;
    void SetOrigin(Origins preset) override;

    void SetPingPong(bool b) { isPingPong = b; }
    void AddMoveKeys(sf::Keyboard::Key key) { moveKeys.push_back(key); }

    // GameObject을(를) 통해 상속됨
    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;

    sf::FloatRect GetGlobalBound() const { return shape.getGlobalBounds(); }
};

