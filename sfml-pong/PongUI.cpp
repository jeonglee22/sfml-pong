#include "stdafx.h"
#include "PongUI.h"

PongUI::PongUI(const std::string& name)
	:GameObject(name)
{
}

void PongUI::SetScore(int s)
{
	score = s;
	scoreText.SetString("Score : " + std::to_string(score));
}

void PongUI::SetGameText(const std::string& text)
{
	gameText.SetString(text);
	gameText.SetOrigin(Origins::MC);
}

void PongUI::Init()
{
	fontId = "fonts/DS-DIGIT.TTF";

	scoreText.SetFontId(fontId);
	scoreText.SetCharacterSize(100);

	gameText.SetFontId(fontId);
	gameText.SetCharacterSize(100);
	gameText.SetFillColor(sf::Color::Red);
}

void PongUI::Release()
{
}

void PongUI::Reset()
{
	scoreText.GetText().setFont(FONT_MGR.Get(fontId));
	gameText.GetText().setFont(FONT_MGR.Get(fontId));

	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();

	scoreText.SetPosition({10.f,0.f});
	gameText.SetPosition({ bound.width / 2.f, bound.height / 2.f });
	
	SetScore(0);
	gameTextActive = true;
	SetGameText("Press Space to Start!");
}

void PongUI::Update(float dt)
{
}

void PongUI::Draw(sf::RenderWindow& window)
{
	scoreText.Draw(window);
	if (gameTextActive)
	{
		gameText.Draw(window);
	}
}
