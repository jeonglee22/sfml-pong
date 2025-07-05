#pragma once
#include "GameObject.h"
#include "TextGo.h"
class PingPongUI : public GameObject
{
protected:
	TextGo winText;
	TextGo gameText;

	TextGo score1Text;
	TextGo score2Text;

	std::vector<sf::RectangleShape> middleBar;
	int barCount = 20;

	std::string fontId;

	int score1 = 0;
	int score2 = 0;

	bool gameTextActive = false;
	bool winTextActive = false;

public:
	PingPongUI(const std::string& name);
	~PingPongUI() override = default;

	void SetGameText(const std::string& text);
	void SetWinText(const std::string& text);

	void SetTextActive(bool a) { gameTextActive = a; }
	bool GetTextActive() const { return gameTextActive; }
	void SetWinTextActive(bool a) { winTextActive = a; }
	bool GetWinTextActive() const { return winTextActive; }

	void SetScore1(int score);
	int GetScore1() const { return score1; }
	void SetScore2(int score);
	int GetScore2() const { return score2; }

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

