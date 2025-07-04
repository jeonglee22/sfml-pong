#pragma once
#include "GameObject.h"
#include "TextGo.h"
class PongUI : public GameObject
{
protected:
	TextGo scoreText;
	TextGo gameText;

	std::string fontId;

	int score = 0;

public:
	PongUI(const std::string& name);
	~PongUI() override = default;

	void SetScore(int s);
	int GetScore() const { return score; }

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

