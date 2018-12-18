#pragma once
#ifndef __T_SECTION_HPP__
#define __T_SECTION_HPP__

#include "Section.hpp"

/// \class TSection
/// \brief Class defining a TSection 
///  - A specific type of Section in which the player can choose to turn left or right ;
class TSection : public Section
{

private:

public:
	/// \brief Constructor from a position and size
	/// \param model : the Model used for the TSection
	TSection(const Model &model);

	/// \brief Copy constructor using another TSection
	/// \param copied : the copied TSection
	TSection(const TSection &copied);

	/// \brief Destructor
	~TSection();

};

#endif