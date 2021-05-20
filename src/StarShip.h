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

private:
	float m_turnRate;
};

#endif /* defined (__STAR_SHIP__) */