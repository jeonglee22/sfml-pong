#pragma once
#include "GameObject.h"
#include "TextGo.h"
class PingPongUI : public GameObject
{
protected:
	TextGo winText;
	TextGo gameText;

	std::string fontId;

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

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

