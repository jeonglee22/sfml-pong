#pragma once

enum class Axis
{
	Horizontal,
	Vertical
};

struct AxisInfo
{
	Axis axis;
	std::list<int> positives;
	std::list<int> negatives;

	float sensi = 10.f;
	float value = 0.f;
};

class InputMgr
{
private:
	static std::list<int> downKeys;
	static std::list<int> heldKeys;
	static std::list<int> upKeys;
	/*static std::list<sf::Keyboard::Key> downKeys;
	static std::list<sf::Keyboard::Key> heldKeys;
	static std::list<sf::Keyboard::Key> upKeys;*/

	static std::unordered_map<Axis, AxisInfo> axisInfoMap;

public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::list<int>& list, sf::Keyboard::Key key);
	static bool Contains(const std::list<int>& list, sf::Mouse::Button key);
	/*static bool Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);*/
	static void Remove(std::list<int>& list, sf::Keyboard::Key key);
	static void Remove(std::list<int>& list, sf::Mouse::Button key);
	/*static void Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);*/

	static float GetAxisRaw(Axis axis);
	static float GetAxis(Axis axis);

	static bool GetMouseButtonDown(sf::Mouse::Button button);
	static bool GetMouseButtonUp(sf::Mouse::Button button);
	static bool GetMouseButton(sf::Mouse::Button button);

	static sf::Vector2i GetMousePosition();
};

