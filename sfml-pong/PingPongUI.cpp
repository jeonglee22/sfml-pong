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

void PingPongUI::Init()
{
	fontId = "fonts/DS-DIGIT.TTF";

	winText.SetFontId(fontId);
	winText.SetCharacterSize(70);
	winText.SetFillColor(sf::Color::Red);
	
	gameText.SetFontId(fontId);
	gameText.SetCharacterSize(70);
	gameText.SetFillColor(sf::Color::Red);
	
}

void PingPongUI::Release()
{
}

void PingPongUI::Reset()
{
	winText.GetText().setFont(FONT_MGR.Get(fontId));
	gameText.GetText().setFont(FONT_MGR.Get(fontId));

	sf::FloatRect bound = FRAMEWORK.GetWindowBounds();

	winText.SetPosition({ bound.width / 2.f, bound.height / 2.f - 100.f });
	gameText.SetPosition({ bound.width / 2.f, bound.height / 2.f + 100.f });

	gameTextActive = true;
	SetGameText("Press Enter to Start!");
}

void PingPongUI::Update(float dt)
{
}

void PingPongUI::Draw(sf::RenderWindow& window)
{
	if (gameTextActive)
	{
		gameText.Draw(window);
	}
	if (winTextActive)
	{
		winText.Draw(window);
	}
}