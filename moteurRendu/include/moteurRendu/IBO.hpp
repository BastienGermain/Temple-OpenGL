#pragma once
#ifndef __IBO_HPP__
#define __IBO_HPP__


#include <vector>
#include <cstdlib>
#include <iostream>

#include <GL/glew.h>

#include "glimac/glm.hpp"
#include "glimac/common.hpp"



/// \class VBO
/// \brief Contain the vertices of an object
class IBO 
{

private:
	GLuint _id;
	const unsigned int* _indexes;
	size_t _size;
	
	
public:
	IBO();
	/// \param vertices: Vector of a structure containing vertex, normal, texture

	IBO(const size_t &size);

	IBO(const size_t &size, const unsigned int* index);

	/// \param copied : The VBO to copy into the current object
	IBO(const IBO &copied);
		// glGenBuffers; glBindBuffer; glBufferData; glVertexAttribPointer
	~IBO();
		// deleteBuffers

	inline GLuint id() const
	{
		return _id;
	};

	inline size_t size() const
	{
		return _size;
	}

	/// \brief Allows to bind the buffer array
	void bind() const;

	/// \brief  Unbinds the buffer
	void debind() const;

	/// \brief BiFill the IBO with the indexes
	void fillIbo() const;



private:

};

#endif