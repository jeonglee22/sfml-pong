#include "stdafx.h"
#include "InputMgr.h"

std::list<int> InputMgr::downKeys;
std::list<int> InputMgr::heldKeys;
std::list<int> InputMgr::upKeys;

//std::vector<int> InputMgr::mouseStates(sf::Mouse::ButtonCount);

std::unordered_map<Axis, AxisInfo> InputMgr::axisInfoMap;

void InputMgr::Init()
{
	AxisInfo infoH;
	infoH.axis = Axis::Horizontal;
	infoH.positives.push_back(sf::Keyboard::Right);
	infoH.positives.push_back(sf::Keyboard::D);
	infoH.negatives.push_back(sf::Keyboard::Left);
	infoH.negatives.push_back(sf::Keyboard::A);
	axisInfoMap.insert({ Axis::Horizontal, infoH });

	AxisInfo infoV;
	infoV.axis = Axis::Vertical;
	infoV.positives.push_back(sf::Keyboard::Down);
	infoV.positives.push_back(sf::Keyboard::S);
	infoV.negatives.push_back(sf::Keyboard::Up);
	infoV.negatives.push_back(sf::Keyboard::W);
	axisInfoMap.insert({ Axis::Vertical, infoV });
}

void InputMgr::Clear() 
{
	downKeys.clear();
	upKeys.clear();
	/*for (int i = 0 ; i < sf::Mouse::ButtonCount; i++)
	{
		if (mouseStates[i] == 3)
		{
			mouseStates[i] = 0;
		}
		else if (mouseStates[i] == 1)
		{
			mouseStates[i] = 2;
		}
	}*/
}

void InputMgr::UpdateEvent(const sf::Event& ev) 
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!Contains(heldKeys, ev.key.code))
		{
			downKeys.push_back(ev.key.code);
			heldKeys.push_back(ev.key.code);
		}
		break;
	case sf::Event::KeyReleased:
		Remove(heldKeys, ev.key.code);
		upKeys.push_back(ev.key.code);
		break;
	case sf::Event::MouseButtonPressed:
		if (!Contains(heldKeys, ev.mouseButton.button))
		{
			downKeys.push_back(sf::Keyboard::KeyCount + ev.mouseButton.button);
			heldKeys.push_back(sf::Keyboard::KeyCount + ev.mouseButton.button);
		}
		break;
	case sf::Event::MouseButtonReleased:
		Remove(heldKeys, ev.mouseButton.button);
		upKeys.push_back(sf::Keyboard::KeyCount + ev.mouseButton.button);
		break;
	}
}

void InputMgr::Update(float dt) 
{

}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return Contains(heldKeys, key);
}

bool InputMgr::Contains(const std::list<int>& list, sf::Keyboard::Key key)
{
	return std::find(list.begin(), list.end(), key) != list.end();
}

bool InputMgr::Contains(const std::list<int>& list, sf::Mouse::Button button)
{
	return std::find(list.begin(), list.end(), sf::Keyboard::KeyCount + button) != list.end();
}

void InputMgr::Remove(std::list<int>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}

void InputMgr::Remove(std::list<int>& list, sf::Mouse::Button button)
{
	list.remove(sf::Keyboard::KeyCount + button);
}

float InputMgr::GetAxisRaw(Axis axis)
{
	auto findit = axisInfoMap.find(axis);
	if (findit == axisInfoMap.end())
		return 0.f;

	const AxisInfo& axisInfo = findit->second;
	
	auto it = heldKeys.rbegin();
	while (it != heldKeys.rend())
	{
		sf::Keyboard::Key code = (sf::Keyboard::Key)*it;
		if (Contains(axisInfo.positives, code))
		{
			return 1.f;
		}
		else if (Contains(axisInfo.negatives, code))
		{
			return -1.f;
		}

		it++;
	}

	return 0.0f;
}

float InputMgr::GetAxis(Axis axis)
{
	return 0.0f;
}

bool InputMgr::GetMouseButtonDown(sf::Mouse::Button button)
{
	return Contains(downKeys, button);
}

bool InputMgr::GetMouseButtonUp(sf::Mouse::Button button)
{
	return Contains(upKeys, button);
}

bool InputMgr::GetMouseButton(sf::Mouse::Button button)
{
	return Contains(heldKeys, button);;
}

sf::Vector2i InputMgr::GetMousePosition()
{
	return sf::Mouse::getPosition(FRAMEWORK.GetWindow());
}

