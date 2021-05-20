#pragma once
#ifndef __STAR_SHIP__
#define __STAR_SHIP__
#include "Agent.h"

class StarShip : public Agent
{
public:
	// Constructor
	StarShip();

	// Destrcutor
	~StarShip();
	
	// LifeCycle Functions
	void draw() override;
	void update() override;
	void clean() override;

	// getters and setters
	float getTurnRate() const;
	void setTurnRate(float turn_rate);
	
	float getMaxSpeed() const;
	void setMaxSpeed(float speed);

	glm::vec2 getDesiredVelocity() const;
	void setDesiredVelocity(glm::vec2 target_position);

private:
	float m_turnRate;
	float m_maxSpeed;

	glm::vec2 m_desiredVelocity;
};

#endif /* defined (__STAR_SHIP__) */