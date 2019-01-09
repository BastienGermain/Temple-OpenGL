#pragma once
#ifndef __GAME_MANAGER_HPP__
#define __GAME_MANAGER_HPP__

#include <vector>
#include <algorithm>

#include "moteurJeu/Game.hpp"
#include "moteurJeu/Player.hpp"
#include "moteurJeu/Enemy.hpp"
#include "moteurJeu/Section.hpp"
#include "moteurJeu/PositionObserver.hpp"
#include "moteurJeu/Factory.hpp"
#include "moteurJeu/Parser.hpp"
#include "moteurJeu/EventManager.hpp"

#include "moteurRendu/Drawer.hpp"
#include "moteurRendu/TrackballCamera.hpp"



/// \class GameManager
/// \brief One try a the game
class GameManager : public PositionObserver
{

private:
	const std::string _sectionsDataFilePath = "../Temple-OpenGL/app/assets/sectionsData/sectionsData.txt";
	
	Game _game;
	Player _player;
	Enemy _enemy;
	const Parser _parser;
	Drawer _drawer;
	EventManager _eventManager;
	TrackballCamera _trackball;
	Factory _factory;

	std::vector<Section> _sectionVec;
	std::vector<std::vector<Section*>> _sectionMat;
	
public:
	GameManager(const Program &program, const float &trackballSmoothness = 0.08);
	~GameManager();

	// POUR DEBUGGER
	inline void printPlayerPos()
	{
		std::cout << "pos player (x, y, z) : " << _player.posX() << ", " << _player.posY() << ", " << _player.posZ() << std::endl;
	}

	inline Enemy &enemy() 
	{
		return _enemy;
	}

	inline Player &player()
	{
		return _player;
	}

	inline std::vector<std::vector<Section*>> &sectionMat()
	{
		return _sectionMat;
	}

	inline std::vector<Section> &sectionVec()
	{
		return _sectionVec;
	}

	inline Game game() const 
	{
		return _game;
	}

	inline Drawer &drawer() 
	{
		return _drawer;
	}

	inline EventManager eventManager() const 
	{
		return _eventManager;
	}

	inline TrackballCamera trackball() const 
	{
		return _trackball;
	}

	/// \brief fill the section vector with returns from the factory
	void fillSectionVec(std::vector<std::string> &sectionDataStrings);

	/// \brief read section vector and fill the matrix handling T section
	void fillSectionMat();

	/// \brief update section matrix when player has chosen a side
	/// \param isLeft : boolean, test if chosen side is left
	void updateSectionMat(const bool isLeft);

	/// \brief load the sections data from the sectionDataFile
	void loadSections();

	void observerUpdate(const PositionObservable *observable) const;	

	/// \brief test end of game
	bool isOver() const;

	inline void handleEvent(SDL_Event *event) 
	{
		_eventManager.handleEvent(event, _player, _trackball);
	}

	inline void deleteModelBuffers() {
		_factory.deleteModelBuffers();
	}
};

#endif