#pragma once
#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include <glimac/glm.hpp>

/// \class Enemy
/// \brief Enemy pursuing the player
class Enemy 
{

private:
	unsigned int _distanceToPlayer; // si = 0 --> fin de partie
	//float _size; // à voir si ça sert
	
public:
	Enemy();
	~Enemy();

	/// \brief Getter score
	inline unsigned int distanceToPlayer() const 
	{
		return _distanceToPlayer;
	}

};

#endif