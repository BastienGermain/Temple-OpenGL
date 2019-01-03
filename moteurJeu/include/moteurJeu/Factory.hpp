#pragma once
#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <string>

#include "moteurRendu/ModelLoader.hpp"

#include "moteurJeu/Exception.hpp"

#include "moteurJeu/CornerSection.hpp"
#include "moteurJeu/CorridorSection.hpp"
#include "moteurJeu/TSection.hpp"

#include "moteurJeu/Hole.hpp"
#include "moteurJeu/Rock.hpp"
#include "moteurJeu/Barrier.hpp"

/// \class Factory
/// \brief Creates Section from input string
class Factory 
{

private:
 	float _sectionInitialPosZ;
 	ModelLoader _modelLoader;
public:
 	Model _corridorModel;
 	Model _cornerModel;
 	Model _playerModel;

	/// \brief Default constructor
	Factory(const float &sectionInitialPosZ = 0.0);

	/// \brief Destructor
	~Factory();

	inline const float sectionInitialPosZ() const 
	{
		return _sectionInitialPosZ;
	}

	Obstacle obstacleBuiler(const std::string &key, PositionObserver *observer) const;

	/// \brief 
	Section create(const std::string &key, PositionObserver *observer) const;

	void deleteModelBuffers();

	inline Model *playerModel() 
	{
		return &_playerModel;
	}
};

#endif