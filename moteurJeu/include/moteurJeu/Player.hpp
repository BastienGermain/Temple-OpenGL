#pragma once
#ifndef __Player_HPP__
#define __Player_HPP__

#include <cmath>

#include "moteurRendu/ModelLoader.hpp"
#include "moteurRendu/FreeflyCamera.hpp"
#include "moteurJeu/Factory.hpp"

#define REGULAR_X 0.f
#define MAX_X (REGULAR_X + 2)
#define MIN_X (REGULAR_X - 2)
#define X_SMOOTHNESS 0.01

#define REGULAR_Y 1.7f
#define MAX_Y (REGULAR_Y + 3)
#define Y_SMOOTHNESS 0.01

#define REGULAR_Z 0.f

/// \class Player
/// \brief Class defining the main player
class Player
{

private:
	float _posX; // -1 : left; 0 : middle; 1: right
	float _posY; // -1 : down; 0 : regular; 1: up
	float _posZ; // position of the player, to which the obstacle posZ will be compared
	float _rotateX;
	bool _oppositeRotateX;
	Model *_model;
public:
	bool _jumping;
	bool _landing;
	bool _turningLeft;
	bool _turningRight;

	/// \brief Constructor
	Player();

	Player(const Player &copied);

	/// \brief Destructor
	~Player();

	void goRight(FreeflyCamera &fly);
	void goCenter(FreeflyCamera &fly);
	void goLeft(FreeflyCamera &fly);

	void jump(FreeflyCamera &fly);
	void land(FreeflyCamera &fly);

	inline float posZ() const 
	{
		return _posZ;
	}

	inline float posX() const 
	{
		return _posX;
	}

	inline float posY() const 
	{
		return _posY;
	}

	inline const Model *model() const 
	{
		return _model;
	}

	inline void model(Model *model) {
		_model = model;
	}

};

#endif