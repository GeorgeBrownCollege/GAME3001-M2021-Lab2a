#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"

// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "Util.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	drawDisplayList();
	SDL_SetRenderDrawColor(Renderer::Instance().getRenderer(), 255, 255, 255, 255);
}

void PlayScene::moveStarShip() const
{
	if(m_toggleSeek)
	{
		m_pStarShip->setDesiredVelocity(m_pTarget->getTransform()->position);
		m_pStarShip->getRigidBody()->velocity += m_pStarShip->getDesiredVelocity() - m_pStarShip->getRigidBody()->velocity;
		m_pStarShip->getTransform()->position += m_pStarShip->getRigidBody()->velocity;
	}
}


void PlayScene::update()
{
	updateDisplayList();

	moveStarShip();
}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance().quit();
	}
}

void PlayScene::start()
{
	// Set GUI Title
	m_guiTitle = "Play Scene";

	// Add Target to Scene
	m_pTarget = new Target();
	m_pTarget->getTransform()->position = glm::vec2(200.0f, 300.0f);
	addChild(m_pTarget);

	// Add the StarShip to Scene
	m_pStarShip = new StarShip();
	m_pStarShip->getTransform()->position = glm::vec2(600.0f, 300.0f);
	m_pStarShip->getRigidBody()->velocity = glm::vec2(1.0f, 0.0f) * m_pStarShip->getMaxSpeed();
	addChild(m_pStarShip);

	ImGuiWindowFrame::Instance().setGUIFunction(std::bind(&PlayScene::GUI_Function, this));
}

void PlayScene::GUI_Function()
{
	// Always open with a NewFrame
	ImGui::NewFrame();

	// See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
	//ImGui::ShowDemoWindow();
	
	ImGui::Begin("Your Window Title Goes Here", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoMove);

	if(ImGui::Button("Toggle Seek"))
	{
		m_toggleSeek = !m_toggleSeek;
	}

	ImGui::Separator();

	static float target_position[2] = { 200.0f, 300.0f};
	if(ImGui::SliderFloat2("Target Position", target_position, 0.0f, 800.0f))
	{
		m_pTarget->getTransform()->position = glm::vec2(target_position[0], target_position[1]);
	}
	
	ImGui::End();
}
