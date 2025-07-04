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

void PongUI::Init()
{
	fontId = "fonts/DS-DIGIT.TTF";

	scoreText.SetFontId(fontId);
	scoreText.SetCharacterSize(100);
}

void PongUI::Release()
{
}

void PongUI::Reset()
{
	scoreText.GetText().setFont(FONT_MGR.Get(fontId));
	scoreText.SetPosition({10.f,0.f});
	
	SetScore(0);
}

void PongUI::Update(float dt)
{
}

void PongUI::Draw(sf::RenderWindow& window)
{
	scoreText.Draw(window);
}
