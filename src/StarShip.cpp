#include "StarShip.h"
#include "TextureManager.h"

StarShip::StarShip()
{
	TextureManager::Instance().load("../Assets/textures/ncl.png", "starship");

	auto size = TextureManager::Instance().getTextureSize("starship");
	setWidth(size.x);
	setHeight(size.y);

	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(AGENT);

	setCurrentHeading(0.0f);// current facing angle
	setCurrentDirection(glm::vec2(1.0f, 0.0f)); // facing right

	m_turnRate = 5.0f; // 5 degrees per frame
}

StarShip::~StarShip()
= default;

void StarShip::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the starship
	TextureManager::Instance().draw("starship", x, y, getCurrentHeading(), 255, true);
}

void StarShip::update()
{
}

void StarShip::clean()
{
}
