#include "stdafx.h"
#include "PingPongUI.h"

PingPongUI::PingPongUI(const std::string& name)
	:GameObject(name)
{
}


void PingPongUI::SetGameText(const std::string& text)
{
	gameText.SetString(text);
	gameText.SetOrigin(Origins::MC);
}

void PingPongUI::SetWinText(const std::string& text)
{
	winText.SetString(text);
	winText.SetOrigin(Origins::MC);
}

void PingPongUI::SetScore1(int score)
{
	score1 = score;
	score1Text.SetString(std::to_string(score1));
	score1Text.SetOrigin(Origins::MC);
}

void PingPongUI::SetScore2(int score)
{
	score2 = score;
	score2Text.SetString(std::to_string(score2));
	score2Text.SetOrigin(Origins::MC);
}

void PingPongUI::Init()
{
	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();

	fontId = "fonts/DS-DIGIT.TTF";

	winText.SetFontId(fontId);
	winText.SetCharacterSize(70);
	winText.SetFillColor(sf::Color::Red);
	
	gameText.SetFontId(fontId);
	gameText.SetCharacterSize(70);
	gameText.SetFillColor(sf::Color::Red);
	
	score1Text.SetFontId(fontId);
	score1Text.SetCharacterSize(70);
	score1Text.SetFillColor(sf::Color::Red);

	score2Text.SetFontId(fontId);
	score2Text.SetCharacterSize(70);
	score2Text.SetFillColor(sf::Color::Red);

	for (int i = 0; i < barCount; i++)
	{
		sf::RectangleShape bar;
		Utils::SetOrigin(bar, Origins::MC);
		bar.setSize({5.f, 10.f});
		bar.setPosition({ bound.width / 2.f, bound.height / (barCount * 2) * 2 * (i+1)});
		middleBar.push_back(bar);
	}

	SetScore1(0);
	SetScore2(0);
}

void PingPongUI::Release()
{
}

void PingPongUI::Reset()
{
	score1Text.GetText().setFont(FONT_MGR.Get(fontId));
	score2Text.GetText().setFont(FONT_MGR.Get(fontId));
	winText.GetText().setFont(FONT_MGR.Get(fontId));
	gameText.GetText().setFont(FONT_MGR.Get(fontId));

	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();

	winText.SetPosition({ bound.width / 2.f, bound.height / 2.f - 100.f });
	gameText.SetPosition({ bound.width / 2.f, bound.height / 2.f + 100.f });
	score1Text.SetPosition({ bound.width / 2.f - 100.f, 30.f });
	score2Text.SetPosition({ bound.width / 2.f + 100.f, 30.f });

	gameTextActive = true;
	SetGameText("Press Enter to Start!");

	if(winTextActive)
	{
		SetScore1(0);
		SetScore2(0);
		winTextActive = false;
	}
}

void PingPongUI::Update(float dt)
{
}

void PingPongUI::Draw(sf::RenderWindow& window)
{
	for (auto bar : middleBar)
	{
		window.draw(bar);
	}
	score1Text.Draw(window);
	score2Text.Draw(window);
	if (gameTextActive)
	{
		gameText.Draw(window);
	}
	if (winTextActive)
	{
		winText.Draw(window);
	}
}